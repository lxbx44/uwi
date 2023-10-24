#include <cstddef>
#include <vector>

#include "parser.hpp"
#include "token.hpp"

std::vector<Token> tokenParser(std::vector<Token> tokens) {
    bool error = false;

    std::vector<Token> parsedTokens;

    int tn = 1; // tn -> token number
    size_t tt = tokens.size(); // tt -> total tokens
                               //
    while (tn <= tt && !error) {
        break;
    }

    return tokens;
}
