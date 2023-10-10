#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <cwctype>
#include <ios>
#include <iostream>
#include <fstream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>

enum class TokenTy {
    _return,
    print,
    _input,
    dec_string,
    dec_int,

    _int,
    _string,
    _char,
    varname,

    equal,
    loop,

    semi,
    lpar,
    rpar,
    lsbraq,
    rsbraq,
    lcbraq,
    rcbraq,
    qmark,
    coma
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
};

void del_files(std::string filename, bool iferr = false) {
    if (iferr == true) {
        std::string command = "rm -f " + filename;
        std::system(command.c_str());
    } else {
        std::system("rm -f out.o out.asm");
    }
}

std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens;

    std::string buf;
    for (int i = 0; i < str.length(); i++) {
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

std::string tokens_to_asm(const std::vector<Token>& tokens, std::string fname) {
    std::stringstream output;

    return output.str();
}

void viewtokens(std::vector<Token> tokens) {
    for (const auto& token : tokens) {
        std::cout << "Token Type: ";
        switch (token.type) {
            case TokenTy::_return:
                std::cout << "_return";
                break;
            case TokenTy::_int:
                std::cout << "_int";
                break;
            case TokenTy::_string:
                std::cout << "_string";
                break;
            case TokenTy::semi:
                std::cout << "semi\n";
                break;
            case TokenTy::print:
                std::cout << "print";
                break;
            case TokenTy::lpar:
                std::cout << "lpar";
                break;
            case TokenTy::rpar:
                std::cout << "rpar";
                break;
            case TokenTy::qmark:
                std::cout << "qmark";
                break;
            case TokenTy::coma:
                std::cout << "coma";
                break;
            case TokenTy::_input:
                std::cout << "_input";
                break;
            case TokenTy::varname:
                std::cout << "varname";
                break;
            case TokenTy::dec_string:
                std::cout << "dec_string";
                break;
            case TokenTy::dec_int:
                std::cout << "dec_int";
                break;
            case TokenTy::equal:
                std::cout << "equal";
                break;
            case TokenTy::_char:
                std::cout << "_char";
                break;
            case TokenTy::lsbraq:
                std::cout << "lsbraq";
                break;
            case TokenTy::rsbraq:
                std::cout << "rsbraq";
                break;
            case TokenTy::lcbraq:
                std::cout << "lcbraq";
                break;
            case TokenTy::rcbraq:
                std::cout << "rcbraq";
                break;
            case TokenTy::loop:
                std::cout << "loop";
                break;
        }

        if (token.value.has_value()) {
            std::cout << ", Value: " << token.value.value();
        }
        std::cout << std::endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage of uwic" << std::endl;
        std::cerr << "uwic <file.uwi>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string arg = argv[1];

    if (arg.find('.') == std::string::npos) {
        std::cerr << "Incorrect usage of uwic" << std::endl;
        std::cerr << "uwic <file.uwi>" << std::endl;
        return EXIT_FAILURE;
    }

    std::stringstream ss(arg);
    std::string t;

    std::vector<std::string> ts;
    while (std::getline(ss, t, '.')) {
        ts.push_back(t);
    }

    std::string uwiname = ts[0];

    std::string contents;
    {
        std::stringstream contents_stram;
        std::fstream input(argv[1], std::ios::in);
        contents_stram << input.rdbuf();
        contents = contents_stram.str();
    }

    std::vector<Token> tokens = tokenize(contents);

    viewtokens(tokens);

    /*
    {
        std::fstream file("out.asm", std::ios::out);
        file << tokens_to_asm(tokens, uwiname);
    }

    std::system("nasm -felf64 out.asm");
    std::string command = "ld -o " + uwiname + " out.o";
    std::system(command.c_str());

    del_files(uwiname);

    std::cout << "Succesfully compiled " << uwiname << ".wui" << std::endl;
    */

    return EXIT_SUCCESS;
}

