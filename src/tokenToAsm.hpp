#include <string>
#include <vector>
#include <sstream>

#include "./token.hpp"

std::string tokens_to_asm(const std::vector<Token>& tokens, std::string fname);
