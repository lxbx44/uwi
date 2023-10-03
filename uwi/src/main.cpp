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
#include <vector>

enum class TokenTy {
    _return,
    _int,
    semi
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
};

std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens;

    std::string buf;
    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);

        if (std::isalpha(c)) {
            buf.push_back(c);
            i++;
            while (std::isalnum(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;

            if (buf == "return") {
                tokens.push_back({.type = TokenTy::_return});
                buf.clear();
                continue;
            } else {
                std::cerr << "You messed up!" << std::endl;
                exit(EXIT_FAILURE);
            }
        } else if (std::isdigit(c)) {
            buf.push_back(c);
            i++;
            while (std::isdigit(str.at(i))) {
                buf.push_back(str.at(i));
                i++;
            }
            i--;
            tokens.push_back({.type = TokenTy::_int, .value = buf});
            buf.clear();
        } else if (c == ';') {
            tokens.push_back({.type = TokenTy::semi});
        } else if (std::isspace(c)) {
            continue;
        } else {
            std::cerr << "You messed up!" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return tokens;
};

std::string tokens_to_asm(const std::vector<Token>& tokens) {
    std::stringstream output;
    output << "global _start\n_start:\n";
    for (int i = 0; i < tokens.size(); i++) {
        const Token& token = tokens.at(i);
        if (token.type == TokenTy::_return) {
            if (i + 1 < tokens.size() && tokens.at(i + 1).type == TokenTy::_int) {
                if (i + 2 < tokens.size() && tokens.at(i + 2).type == TokenTy::semi) {
                    output << "    mov rax, 60\n";
                    output << "    mov rdi, " << tokens.at(i + 1).value.value() << "\n";
                    output << "    syscall";
                }
            }
        }
    }
    return output.str();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage of uwic" << std::endl;
        std::cerr << "uwic <file.uwi>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stram;
        std::fstream input(argv[1], std::ios::in);
        contents_stram << input.rdbuf();
        contents = contents_stram.str();
    }


    std::vector<Token> tokens = tokenize(contents);
   
    {
        std::fstream file("out.asm", std::ios::out);
        file << tokens_to_asm(tokens);
    }

    system("nasm -felf64 out.asm");
    system("ld -o out out.o");
    system("rm -f out.o out.asm");


    return EXIT_SUCCESS;
}
