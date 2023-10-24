#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <system_error>
#include <vector>
#include <cstring>

#include "./token.hpp"

#include "./tokenization.hpp"
#include "./remove.hpp"
#include "./toAsm.hpp"
#include "./parser.hpp"
#include "./tokenViewer.hpp"

#define UWIC_VERSION "alpha 1.0"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Incorrect usage of uwic" << std::endl;
        std::cerr << "uwic <file.uwi>" << std::endl;
        return EXIT_FAILURE;
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        std::cout << "uwic version:" << std::endl;
        std::cout << UWIC_VERSION << std::endl;
        return EXIT_SUCCESS;
    } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        std::cout << "UWIC, the official compiler\nfor the uwi programming language\n" << std::endl;
        std::cout << "Usage: `uwic <file.uwi>`" << std::endl;
        std::cout << "Options:" << std::endl;
        std::cout << "    -h           show this help page" << std::endl;
        std::cout << "    --help       show this help page" << std::endl;
        std::cout << "    -v           show version of the program" << std::endl;
        std::cout << "    --version    show version of the program" << std::endl;
        std::cout << "\nIf you notice any bugs open an isue in the github repo:"  << std::endl;
        std::cout << "<https://github.com/lxbx44/uwi>" << std::endl;
        return EXIT_SUCCESS;
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

    std::vector<Token> tokens = tokenize(contents, uwiname);

    std::vector<Token> parsedTokens = tokenParser(tokens);

    viewTokens(parsedTokens);

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

