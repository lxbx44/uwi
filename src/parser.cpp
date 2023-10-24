#include <cstddef>
#include <iostream>
#include <vector>

#include "parser.hpp"
#include "token.hpp"


std::vector<Token> tokenParser(std::vector<Token> tokens) {
    bool error = false;

    std::vector<Token> buffer;
    std::vector<std::vector<Token>> instructions;

    int numSemi = 1;

    for (const Token& token : tokens) {
        break;
    }
}
