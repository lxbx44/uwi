#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "parser.hpp"
#include "token.hpp"
#include "tokenViewer.hpp"

#define ty TokenTy

std::vector<Token> tokenParser(std::vector<Token> tokens, std::string filename) {
    size_t n = 0;
    size_t line_count = 1;

    while (tokens[n].type != ty::_EOF) {
        if (tokens[n].type == ty::newline) {
            n++;
            line_count++;
            continue;
        }

        /* 
         * variables
         */
            
        // STRINGS
        

        if (tokens[n].type == ty::_str) {
            if (tokens[n + 1].type != ty::_var_name) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count;
                std::cerr << "\nerror: After token 'str' there must be a variable name: $<var name>\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 2].type == ty::_semicolon) {
                n += 3;
                continue;
            }
            if (tokens[n + 2].type != ty::_asign) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after token '<var name>' there must be an assigment symbol\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::str_l) {
                switch (tokens[n + 3].type) {
                    case ty::int_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a string literal, not an integer\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::char_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a string literal, not a character\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::float_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a string literal, not a float\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_bool:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a string literal, not a boolean\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_null:
                        break;
                    default:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token '<assignment>' there must be a string literal\n";
                        exit(EXIT_FAILURE);
                }
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after making a string there must be a semicolon\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }
        

        // INTEGERS
        

        if (tokens[n].type == ty::_int) {
            if (tokens[n + 1].type != ty::_var_name) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count;
                std::cerr << "\nerror: After token 'int' there must be a variable name: $<var name>\n";
                exit(EXIT_FAILURE);
            }

            if (tokens[n + 2].type == ty::_semicolon) {
                n += 3;
                continue;
            } else if (tokens[n + 2].type != ty::_asign) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after token '<var name>' there must be an assigment symbol\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::int_l) {
                switch (tokens[n + 3].type) {
                    case ty::str_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be an integer literal, not a string\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::char_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be an integer literal, not a character\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::float_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be an integer literal, not a float\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_bool:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be an integer literal, not a boolean\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_null:
                        break;
                    default:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token '<assignment>' there must be an integer literal\n";
                        exit(EXIT_FAILURE);
                }
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after making an integer there must be a semicolon\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }
        

        // FLOATS
        
        if (tokens[n].type == ty::_float) {
            if (tokens[n + 1].type != ty::_var_name) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count;
                std::cerr << "\nerror: After token 'float' there must be a variable name: $<var name>\n";
                exit(EXIT_FAILURE);
            }

            if (tokens[n + 2].type == ty::_semicolon) {
                n += 3;
                continue;
            } else if (tokens[n + 2].type != ty::_asign) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after token '<var name>' there must be an assigment symbol\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::float_l) {
                switch (tokens[n + 3].type) {
                    case ty::str_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a float literal, not a string\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::char_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a float literal, not a character\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::int_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a float literal, not an integer\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_bool:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a float literal, not a boolean\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_null:
                        break;
                    default:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token '<assignment>' there must be a float literal\n";
                        exit(EXIT_FAILURE);
                }
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after making an float there must be a semicolon\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }
        

        // CHARACTERS
        

        if (tokens[n].type == ty::_char) {
            if (tokens[n + 1].type != ty::_var_name) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count;
                std::cerr << "\nerror: After token 'char' there must be a variable name: $<var name>\n";
                exit(EXIT_FAILURE);
            }

            if (tokens[n + 2].type == ty::_semicolon) {
                n += 3;
                continue;
            } else if (tokens[n + 2].type != ty::_asign) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after token '<var name>' there must be an assigment symbol\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::char_l) {
                switch (tokens[n + 3].type) {
                    case ty::str_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a character literal, not a string\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::float_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a character literal, not a float\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::int_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a character literal, not an integer\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_bool:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a character literal, not a boolean\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_null:
                        break;
                    default:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token '<assignment>' there must be a character literal\n";
                        exit(EXIT_FAILURE);
                }
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after making an float there must be a semicolon\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }
        

        // BOOLEANS
        

        if (tokens[n].type == ty::_bool) {
            if (tokens[n + 1].type != ty::_var_name) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: Syntax error\n";
                std::cerr << " --> Line " << line_count;
                std::cerr << "\nerror: After token 'bool' there must be a variable name: $<var name>\n";
                exit(EXIT_FAILURE);
            }

            if (tokens[n + 2].type == ty::_semicolon) {
                n += 3;
                continue;
            } else if (tokens[n + 2].type != ty::_asign) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after token '<var name>' there must be an assigment symbol\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::_bool) {
                switch (tokens[n + 3].type) {
                    case ty::str_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a boolean, not a string\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::float_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a boolean, not a float\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::int_l:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a boolean, not an integer\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_char:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token assigning, there must be a boolean, not a character\n";
                        exit(EXIT_FAILURE);
                        break;
                    case ty::_null:
                        break;
                    default:
                        std::cerr << "error in " << filename << ".uwi on line " << line_count;
                        std::cerr << "\nerror message: syntax error\n";
                        std::cerr << " --> line " << line_count;
                        std::cerr << "\nerror: after token '<assignment>' there must be a boolean\n";
                        exit(EXIT_FAILURE);
                }
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nerror: after making an float there must be a semicolon\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }



        /*
         *   PRINTLINE TINPUT
         */

        if (tokens[n].type == ty::_print) {
            if (tokens[n + 1].type != ty::_left_par) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nA left parenthesis is required: printline();\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 2].type != ty::str_l &&
                tokens[n + 2].type != ty::int_l &&
                tokens[n + 2].type != ty::float_l &&
                tokens[n + 2].type != ty::char_l &&
                tokens[n + 2].type != ty::_null &&
                tokens[n + 2].type != ty::_bool) {

                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nA type is required inside the parenthesis:";
                std::cerr << "\n   - string";
                std::cerr << "\n   - integer";
                std::cerr << "\n   - float";
                std::cerr << "\n   - character";
                std::cerr << "\n   - boolean";
                std::cerr << "\n   - null\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 3].type != ty::_right_par) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nA right parenthesis is required: printline();\n";
                exit(EXIT_FAILURE);
            }
            if (tokens[n + 4].type != ty::_semicolon) {
                std::cerr << "error in " << filename << ".uwi on line " << line_count;
                std::cerr << "\nerror message: syntax error\n";
                std::cerr << " --> line " << line_count;
                std::cerr << "\nA semicolon is required: printline();\n";
                exit(EXIT_FAILURE);
            }

            n += 5;
            continue;
        }

    }
    std::cout << "Program finished" << std::endl;

    return tokens;
}
