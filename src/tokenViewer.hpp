#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "token.hpp"

std::string tokenTypeToString(TokenTy type);
void viewTokens(std::vector<Token> tokens);
