#include <iostream>
#include "src/lex.h"
#include "src/tools.h"

int main(int argc, char** argv) {
    if (argc >= 2) {
        std::cout << tokenVectorToString(lex::lexer(".create .data 55\n")) << "\n";
    } else {
        std::cout << "Usage: sasmir <file>\n";
        exit(1);
    }

    return 0;
}