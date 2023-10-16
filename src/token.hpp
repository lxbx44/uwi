#pragma once

#include <string>
#include <optional>

enum class TokenTy {
    // Space
    newline,

    // keywords
    _if,
    _elif,
    _else,

    _loop,
    _for,
    _in,
    _times,
    _break,
    _continue,
    
    _int,
    _str,
    _float,
    _char,
    _bool,

    _true,
    _false,
    _null,

    _print,
    _input,
    _function,

    _return,

    // Literals
    str_l,
    float_l,
    int_l,
    char_l,

    // Operators
    _sum,
    _subtraction,
    _mult,
    _div,
    _mod,

    _gt,
    _st,
    _equal,
    _notequal,

    _and,
    _or,
    _not,

    _asign,
    _asign_sum,
    _asign_min,
    _asign_mult,
    _asign_div,
    _asign_mod,

    // Punctuation
    _semicolon,
    _coma,
    _period,
    _colon,

    _left_par,
    _right_par,

    _lef_brace,
    _right_brace,

    _left_sqbraquet,
    _right_sqbraquet,

    // Other
    _comment_line,
    _start_comment,
    _end_comment
};

struct Token {
    TokenTy type;
    std::optional<std::string> value {};
};

