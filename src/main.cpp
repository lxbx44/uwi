#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "./tokenization.hpp"
#include "./remove.hpp"
#include "./tokenToAsm.hpp"

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

