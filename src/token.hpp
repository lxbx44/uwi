#pragma once

#include <string>
#include <optional>

enum class TokenTy {
    _return,
    print,
    _input,
    dec_string,
    dec_int,

    _int,
    _string,
    _char,
    varname,

    equal,
    loop,

    semi,
    lpar,
    rpar,
    lsbraq,
    rsbraq,
    lcbraq,
    rcbraq,
    qmark,
    coma
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
    std::optional<bool> is {};
};

