#pragma once

#include <string>
#include <optional>

enum class TokenTy {
    newline,
    _return
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
};

