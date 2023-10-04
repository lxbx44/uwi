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
    _int,
    semi,
    print
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
};

void del_files(std::string filename, bool iferr = false) {
    if (iferr == true) {
        std::string command = "rm -f " + filename;
        system(command.c_str());
    } else {
        system("rm -f out.o out.asm");
    }
}

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

            if (buf == "retuwirn") {
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

std::string tokens_to_asm(const std::vector<Token>& tokens, std::string fname) {
    std::stringstream output;
    output << "global _start\n_start:\n";
    for (int i = 0; i < tokens.size(); i++) {
        const Token& token = tokens.at(i);
        if (token.type == TokenTy::_return) {
            if (i + 1 < tokens.size() && tokens.at(i + 1).type == TokenTy::_int) {
                if (i + 2 < tokens.size() && tokens.at(i + 2).type == TokenTy::semi) {
                    int num = std::stoi(tokens.at(i + 1).value.value());

                    if (num > 255) {
                        std::cout << "ERROR COMPILING " << fname << ".uwi" << std::endl;
                        std::cout << "\nThe returm value of the main function shoud be an 8bit number (0-255)" << std::endl;
                        del_files(fname, true);
                        system("rm -f out.asm");
                        exit(EXIT_FAILURE);
                    } else {
                        output << "    mov rax, 60\n";
                        output << "    mov rdi, " << num << "\n";
                        output << "    syscall";
                    }
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
   
    {
        std::fstream file("out.asm", std::ios::out);
        file << tokens_to_asm(tokens, uwiname);
    }

    system("nasm -felf64 out.asm");
    std::string command = "ld -o " + uwiname + " out.o";
    system(command.c_str());

    del_files(uwiname);

    std::cout << "Succesfully compiled " << uwiname << ".wui" << std::endl;
    return EXIT_SUCCESS;
}

