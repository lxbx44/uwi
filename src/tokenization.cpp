#include "tokenization.hpp"
#include "token.hpp"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

std::vector<Token> tokenize(const std::string& str, std::string filename) {
    std::vector<Token> tokens;

    std::string buf;

    size_t strlength = str.length();

    size_t line_count = 1;

    for (size_t i = 0; i < str.length(); i++) {
        char c = str.at(i);
        
        // SPACE

        while (i < str.length() && c == ' ') {
            i++;
            c = str.at(i);
        }

        if (c == '\n') {
            tokens.push_back({.type = TokenTy::newline});
            line_count++;
        }
        // KEYWORDS

        else if (isalpha(c)) {
            while (isalpha(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            if (buf == "if") {
                tokens.push_back({.type = TokenTy::_if});
            } else if (buf == "elif") {
                tokens.push_back({.type = TokenTy::_elif});
            } else if (buf == "else") {
                tokens.push_back({.type = TokenTy::_else});
            } else if (buf == "loop") {
                tokens.push_back({.type = TokenTy::_loop});
            } else if (buf == "for") {
                tokens.push_back({.type = TokenTy::_for});
            } else if (buf == "in") {
                tokens.push_back({.type = TokenTy::_in});
            } else if (buf == "times") {
                tokens.push_back({.type = TokenTy::_times});
            } else if (buf == "break") {
                tokens.push_back({.type = TokenTy::_break});
            } else if (buf == "continue") {
                tokens.push_back({.type = TokenTy::_continue});
            } else if (buf == "str") {
                tokens.push_back({.type = TokenTy::_str});
            } else if (buf == "int") {
                tokens.push_back({.type = TokenTy::_int});
            } else if (buf == "float") {
                tokens.push_back({.type = TokenTy::_float});
            } else if (buf == "char") {
                tokens.push_back({.type = TokenTy::_char});
            } else if (buf == "bool") {
                tokens.push_back({.type = TokenTy::_bool});
            } else if (buf == "printline") {
                tokens.push_back({.type = TokenTy::_print});
            } else if (buf == "tinput") {
                tokens.push_back({.type = TokenTy::_input});
            } else if (buf == "funct") {
                tokens.push_back({.type = TokenTy::_function});
            } else if (buf == "true") {
                tokens.push_back({.type = TokenTy::_true});
            } else if (buf == "false") {
                tokens.push_back({.type = TokenTy::_false});
            } else if (buf == "null") {
                tokens.push_back({.type = TokenTy::_null});
            } else if (buf == "return") {
                tokens.push_back({.type = TokenTy::_return});
            } else if (buf == "and") {
                tokens.push_back({.type = TokenTy::_and});
            } else if (buf == "or") {
                tokens.push_back({.type = TokenTy::_or});
            } else if (buf == "not") {
                tokens.push_back({.type = TokenTy::_not});
            } else {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
                std::cerr << " --> " << "Unexpected token: '" << buf << "'\n";
                std::cerr << "\nerror: Found an unexpected token. Expected a valid keyword or identifier.\n";
                exit(EXIT_FAILURE);
            }


            i--;
            buf.clear();
        }

        // LITERALS
        
        else if (c == '"') {
            i++;
            int cond = true;
            while (cond) {
                if (i >= strlength) {
                    std::cerr << "error in " << filename << ".uwi on line " << line_count;
                    std::cerr << "\nerror message: Syntax error\n";
                    std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
                    std::cerr << " --> " << "String literal not terminated\n";
                    exit(EXIT_FAILURE);
                } else if (str.at(i) == '\\' && str.at(i + 1) == '"') {
                    buf.push_back('"');
                    i += 2;
                } else if (str.at(i) == '"') {
                    cond = false;
                } else {
                    buf.push_back(str.at(i));
                    i++;
                }
            }

            tokens.push_back({.type = TokenTy::str_l, .value = buf});
            buf.clear();
        } else if (std::isdigit(c)) {
            int pointCount = 0;

            while (std::isdigit(str.at(i)) || str.at(i) == '.') {
                if (str.at(i) == '.') {
                    pointCount++;
                }
                buf.push_back(str.at(i));
                i++;
            }

            if (pointCount > 1) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
                std::cerr << " --> Invalid float literal, there can only be 1 '.'\n";
                exit(EXIT_FAILURE);
            }

            if (pointCount == 1) {
                tokens.push_back({.type = TokenTy::float_l, .value = buf});
            } else {
                tokens.push_back({.type = TokenTy::int_l, .value = buf});
            }

            i--;
            buf.clear();
        } else if (c == '\'') {
            i++;
            buf.push_back(str.at(i));
            i++;

            if (str.at(i) != '\'') {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
                std::cerr << " --> Invalid character literal\n";
                exit(EXIT_FAILURE);
            }

            tokens.push_back({.type = TokenTy::char_l, .value = buf});
            buf.clear();

        } else if (c == '+') {
            if (str.at(i + 1) == '+') {
                tokens.push_back({.type = TokenTy::_sum1});
                i++;
            } else if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_asign_sum});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_sum});
            }
            buf.clear();
        } else if (c == '-') {
            if (str.at(i + 1) == '-') {
                tokens.push_back({.type = TokenTy::_sub1});
                i++;
            } else if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_asign_sub});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_subtraction});
            }
            buf.clear();
        } else if (c == '*') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_asign_mult});
                i++;
            } else if (str.at(i + 1) == '*') {
                tokens.push_back({.type = TokenTy::_pow});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_mult});
            }
            buf.clear();
        } else if (c == '/') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_asign_div});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_div});
            }
            buf.clear();
        } else if (c == '%') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_asign_mod});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_mod});
            }
            buf.clear();
        } else if (c == '>') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_get});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_gt});
            }
            buf.clear();
        } else if (c == '<') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_set});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_st});
            }
            buf.clear();
        } else if (c == '|') {
            if (str.at(i + 1) == '|') {
                tokens.push_back({.type = TokenTy::_or});
                i++;
            }
            buf.clear();
        } else if (c == '&') {
            if (str.at(i + 1) == '&') {
                tokens.push_back({.type = TokenTy::_and});
                i++;
            }
            buf.clear();
        } else if (c == '!') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_notequal});
                i++;
            }
            buf.clear();
        } else if (c == '=') {
            if (str.at(i + 1) == '=') {
                tokens.push_back({.type = TokenTy::_equal});
                i++;
            } else {
                tokens.push_back({.type = TokenTy::_asign});
            }
            buf.clear();
        } else if (c == ';') {
            tokens.push_back({.type = TokenTy::_semicolon});
            buf.clear();
        } else if (c == ',') {
            tokens.push_back({.type = TokenTy::_coma});
            buf.clear();
        } else if (c == '.') {
            if (std::isdigit(str.at(i + 1))) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
                std::cerr << " --> Invalid usage of float, 0 is required (for example: 0.32)\n";
                exit(EXIT_FAILURE);
            }
            tokens.push_back({.type = TokenTy::_period});
            buf.clear();
        } else if (c == ':') {
            tokens.push_back({.type = TokenTy::_colon});
            buf.clear();
        } else if (c == '(') {
            tokens.push_back({.type = TokenTy::_left_par});
            buf.clear();
        } else if (c == ')') {
            tokens.push_back({.type = TokenTy::_right_par});
            buf.clear();
        } else if (c == '{') {
            tokens.push_back({.type = TokenTy::_lef_brace});
            buf.clear();
        } else if (c == '}') {
            tokens.push_back({.type = TokenTy::_right_brace});
            buf.clear();
        } else if (c == '[') {
            tokens.push_back({.type = TokenTy::_left_sqbraquet});
            buf.clear();
        } else if (c == ']') {
            tokens.push_back({.type = TokenTy::_right_sqbraquet});
            buf.clear();
        } else if (c == '/') {
            if (str.at(i + 1) == '/') {
                i += 2;
                while (i < str.length() && str.at(i) != '\n') {
                    i++;
                }
                if (i < str.length()) {
                    i++;
                }
            }
            buf.clear();
            tokens.push_back({.type = TokenTy::_comment});
        } else if (c == '$') {
            i++;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            tokens.push_back({.type = TokenTy::_var_name, .value = buf});
            buf.clear();
        } else {
            std::cerr << "error in " << filename << ".uwi on line " << line_count;
            std::cerr << "\nerror message: Syntax error\n";
            std::cerr << " --> Line " << line_count << ": " << str.substr(i - buf.length(), buf.length()) << "\n";
            std::cerr << " --> " << "Unexpected token: '" << buf << "'\n";
            std::cerr << "\nerror: Found an unexpected token. Expected a valid keyword or identifier.\n";
            exit(EXIT_FAILURE);
        }
    }

    tokens.push_back({.type = TokenTy::_EOF});

    return tokens;
};
