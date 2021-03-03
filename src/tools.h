#pragma once

#include "lex.h"
#include <string>
#include <iostream>
#include <vector>

std::string tokenVectorToString(std::vector<lex::Token> v) {
    std::string result;

    for (int i = 0; i < v.size(); i++) {
        std::string format;
        format = "\n\n(Token:\n\t{TokenType: \n\t\t" + v[i].name + "\n\tTokenValue: \n\t\t" + v[i].value + "\n\t}\n)";
        result += format;
    }

    return result;
}