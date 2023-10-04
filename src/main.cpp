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

    _int,
    _string,

    semi,
    lpar,
    rpar,
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

                if (buf == "retuwirn") {
                    tokens.push_back({.type = TokenTy::_return});
                    buf.clear();
                } else if (buf == "priwint") {
                    tokens.push_back({.type = TokenTy::print});
                    buf.clear();
                } else if (buf == "iwimput") {
                    tokens.push_back({.type = TokenTy::_input});
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
        } else if (c == '\'' || c == '"') {
            tokens.push_back({.type = TokenTy::qmark});
            buf.clear();
        } else if (c == ',') {
            tokens.push_back({.type = TokenTy::coma});
            buf.clear();
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

    std::cout << contents << std::endl;


    std::vector<Token> tokens = tokenize(contents);

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
                std::cout << "semi";
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
        }

        if (token.value.has_value()) {
            std::cout << ", Value: " << token.value.value();
        }
        std::cout << std::endl;
    }
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

