#include "tokenization.hpp"
#include "token.hpp"

std::vector<Token> tokenize(const std::string& str) {
    std::vector<Token> tokens;

    std::string buf;
    size_t line = 1;

    for (size_t i = 0; i < str.length(); i++) {
        char c = str.at(i);

        if (c == '\n') {
            tokens.push_back({.type = TokenTy::newline});
        }

    }
    return tokens;
};
