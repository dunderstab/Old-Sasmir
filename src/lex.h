#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <regex>
#include "desc.h"

namespace lex {
    std::string TT_EQUALS = "TT_EQUALS";
    std::string TT_INTEGER = "TT_INTEGER";
    std::string TT_KEYWORD = "TT_KEYWORD";
    std::string TT_NEWLINE = "TT_NEWLINE";
    std::string TT_NAME = "TT_NAME";

    std::vector<std::string> keywords = {".create", ".data", ".local", ".include", ".fnprolouge", ".fnepilouge", ".label", ".asm"};

    typedef struct {
        std::string name;
        std::string value;
    }Token;

    bool is_valid_identifier(std::string s) {
        std::regex identifier_regex("^[a-zA-Z_][a-zA-Z0-9_]*$");
        if (std::regex_match(s, identifier_regex) && std::count(keywords.begin(), keywords.end(), s) != true) {
            return true;
        } else {
            return false;
        }
        return false;
    }

    std::vector<Token> lexer(std::string sourceCode) {

        // define our variables
        std::vector<Token> tokens;
        std::string tmp = "";
        std::string tmp2 = "";
        std::string tmpid = "";

        // regexs

        std::regex integer_regex("^[0-9]+$");

        for (int i = 0; i < sourceCode.length(); i++) {
            char currentValue = sourceCode[i];
            
            if (currentValue == ' ' && tmpid == "") {
                std::cout << "hit3!\n";
                tmp = tmp2;
                tmp2 = "";
            } else if (currentValue == '\n' && tmpid == "") {
                Token newline;
                newline.name = TT_NEWLINE;
                tokens.push_back(newline);
                tmp = tmp2;
                tmp2 = "";
            } else if (currentValue == '=' && tmpid == "") {
                Token equals;
                equals.name = TT_EQUALS;
                tokens.push_back(equals);
                tmpid = "";
                tmp2 = "";
            } else {
                // std::cout << "hit2!\n";
                tmp2 += currentValue;
                // std::cout << tmp2 << "\n";
            }
            if (std::regex_match(tmp, integer_regex)) {
                std::cout << "hit!\n";
                Token integer;
                integer.name = TT_INTEGER;
                integer.value = tmp;
                tokens.push_back(integer);
                tmpid = "";
                tmp = "";
            } else if (std::count(keywords.begin(), keywords.end(), tmp)) {
                Token keyword;
                keyword.name = TT_KEYWORD;
                keyword.value = tmp;
                tokens.push_back(keyword);
                tmpid = "";
                tmp = "";
            
            } else if (is_valid_identifier(tmp)) {
                Token identififer;
                identififer.name = TT_NAME;
                identififer.value = tmp;
                tokens.push_back(identififer);
                tmpid = "";
                tmp = "";
            } else {
                std::string info = "Unknown sequence '" + tmp + "'";
                desc::sendError(desc::errorMessageLexer, info, 2);
            }
        }

        return tokens;
    }
}