#include <string>
#include <iostream>
#include <vector>

#include "token.hpp"

std::string tokenTypeToString(TokenTy type) {
    switch (type) {
        case TokenTy::newline: return "newline";
        case TokenTy::_if: return "if";
case TokenTy::_elif: return "elif";
        case TokenTy::_else: return "else";
        case TokenTy::_loop: return "loop";
        case TokenTy::_for: return "for";
        case TokenTy::_in: return "in";
        case TokenTy::_times: return "times";
        case TokenTy::_break: return "break";
        case TokenTy::_continue: return "continue";
        case TokenTy::_int: return "int";
        case TokenTy::_str: return "str";
        case TokenTy::_float: return "float";
        case TokenTy::_char: return "char";
        case TokenTy::_bool: return "bool";
        case TokenTy::_true: return "true";
        case TokenTy::_false: return "false";
        case TokenTy::_null: return "null";
        case TokenTy::_print: return "print";
        case TokenTy::_input: return "input";
        case TokenTy::_function: return "function";
        case TokenTy::_return: return "return";
        case TokenTy::str_l: return "string literal";
        case TokenTy::float_l: return "float literal";
        case TokenTy::int_l: return "integer literal";
        case TokenTy::char_l: return "character literal";
        case TokenTy::_sum: return "addition";
        case TokenTy::_subtraction: return "subtraction";
        case TokenTy::_mult: return "multiplication";
        case TokenTy::_div: return "division";
        case TokenTy::_mod: return "modulo";
        case TokenTy::_gt: return "greater than";
        case TokenTy::_st: return "less than";
        case TokenTy::_get: return "greater than or equal to";
        case TokenTy::_set: return "less than or equal to";
        case TokenTy::_equal: return "equal to";
        case TokenTy::_notequal: return "not equal to";
        case TokenTy::_and: return "logical and";
        case TokenTy::_or: return "logical or";
        case TokenTy::_not: return "logical not";
        case TokenTy::_asign: return "assignment";
        case TokenTy::_asign_sum: return "addition assignment";
        case TokenTy::_asign_sub: return "subtraction assignment";
        case TokenTy::_asign_mult: return "multiplication assignment";
        case TokenTy::_asign_div: return "division assignment";
        case TokenTy::_asign_mod: return "modulo assignment";
        case TokenTy::_sum1: return "increment";
        case TokenTy::_sub1: return "decrement";
        case TokenTy::_semicolon: return "semicolon";
        case TokenTy::_coma: return "comma";
        case TokenTy::_period: return "period";
        case TokenTy::_colon: return "colon";
        case TokenTy::_left_par: return "left parenthesis";
        case TokenTy::_right_par: return "right parenthesis";
        case TokenTy::_lef_brace: return "left brace";
        case TokenTy::_right_brace: return "right brace";
        case TokenTy::_left_sqbraquet: return "left square bracket";
        case TokenTy::_right_sqbraquet: return "right square bracket";
        case TokenTy::_comment: return "comment";
        case TokenTy::_var_name: return "variable name";
        default: return "unknown";
    }
}

void viewTokens(std::vector<Token> tokens) {
    for (const Token& token : tokens) {
        std::cout << "Token Type: " << tokenTypeToString(token.type);
        if (token.value) {
            std::cout << " - Value: " << token.value.value();
        }
        std::cout << std::endl;
    }
}
