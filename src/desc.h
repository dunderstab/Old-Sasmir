#pragma once

#include <string>
#include <iostream>

namespace desc {
    /*
    Error codes:

    2 - lexer error
    3 - parser error
    127 - segfault
    */

    /*
    Grammar:

    expression : int
                | name
                | expression + expression

    */
    std::string Release = "Beta 1";
    std::string Update = "1";
    std::string Bugfix = "1";
    std::string version = Release + "." + Update + "." + Bugfix;

    std::string languageName = "Sasmir"; // change this for your specified language

    std::string errorMessageParser = languageName + ": Error: ParserError: %s! Aborting...";
    std::string errorMessageLexer = languageName + ": Error: LexerError: %s! Aborting...";
    
    void sendError(std::string Error, std::string info, int exitCode) {
        std::printf(Error.c_str(), info.c_str());
        exit(exitCode);
    }
}