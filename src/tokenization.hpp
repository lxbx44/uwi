#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <string>

#include "token.hpp"

std::vector<Token> tokenize(const std::string& str, std::string filename);
bool is_valid_float(const std::string& buf);
bool is_valid_int(const std::string& buf);
