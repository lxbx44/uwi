#include "parser.hpp"

std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens;

    /*
    bool isLoop = false;
    bool isFunc = false;
    */

    std::string buf;
    for (size_t i = 0; i < str.length(); i++) {
        char c = str.at(i);

        if (std::isalpha(c) || std::isspace(c)) {
            if (i > 0 && (str.at(i - 1) == '\'' || str.at(i - 1) == '"')) {
                while (str.at(i) != '\'' && str.at(i) != '"') {
                    buf.push_back(str.at(i));
                    i++;
                }
                i--;
                tokens.push_back({.type = TokenTy::_string, .value = buf});
                buf.clear();

            } else if (std::isalpha(c)) {
                buf.push_back(c);

                if (buf == "return") {
                    tokens.push_back({.type = TokenTy::_return});
                    buf.clear();
                } else if (buf == "printline") {
                    tokens.push_back({.type = TokenTy::print});
                    buf.clear();
                } else if (buf == "tinput") {
                    tokens.push_back({.type = TokenTy::_input});
                    buf.clear();
                } else if (buf == "loop") {
                    tokens.push_back({.type = TokenTy::loop});
                    buf.clear();
                } else if (buf == "str") {
                    tokens.push_back({.type = TokenTy::dec_string});
                    buf.clear();
                } else if (buf == "int") {
                    tokens.push_back({.type = TokenTy::dec_int});
                    buf.clear();
                } else if (buf == "char") {
                    tokens.push_back({.type = TokenTy::_char});
                    buf.clear();
                }
            }
        } else if (std::isdigit(c)) {
            while (std::isdigit(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            tokens.push_back({.type = TokenTy::_int, .value = buf});
            buf.clear();

        } else if (c == ';') {
            tokens.push_back({.type = TokenTy::semi});
            buf.clear();
        } else if (c == '(') {
            tokens.push_back({.type = TokenTy::lpar});
            buf.clear();
        } else if (c == ')') {
            tokens.push_back({.type = TokenTy::rpar});
            buf.clear();
        } else if (c == '[') {
            tokens.push_back({.type = TokenTy::lsbraq});
            buf.clear();
        } else if (c == ']') {
            tokens.push_back({.type = TokenTy::rsbraq});
            buf.clear();
        } else if (c == '{') {
            tokens.push_back({.type = TokenTy::lcbraq});
            buf.clear();
        } else if (c == '}') {
            tokens.push_back({.type = TokenTy::rcbraq});
            buf.clear();
        } else if (c == '\'' || c == '"') {
            tokens.push_back({.type = TokenTy::qmark});
            buf.clear();
        } else if (c == ',') {
            tokens.push_back({.type = TokenTy::coma});
            buf.clear();
        } else if (c == '$') {
            buf.push_back(c);
            i++;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenTy::varname, .value = buf});
            buf.clear();
        } else if (c == '=') {
            tokens.push_back({.type = TokenTy::equal});
            buf.clear();
        } else if (c == '%') {
            i++;
            if (str.at(i) == '%') {
                i++;
                while (str.at(i) != '%') {
                    i++;
                }
                continue;
            }
        } else if (std::isspace(c)) {
            continue;
        } else {
            std::cout << "nah" << std::endl;
        }
    }
    return tokens;
};
