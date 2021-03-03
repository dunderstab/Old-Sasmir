#pragma once

#include <string>
#include <iostream>
#include "lex.h"
#include "tools.h"
#include "desc.h"
#include <vector>

namespace parse {
    class Node {
        private:
        Node* right;
        Node* left;
        std::string value;
        public:
        Node(Node* right, Node* left, std::string value) {
            this->right = right;
            this->left = left;
            this->value = value;
        }
    };

    class Expr {
        private:
        bool isvalid;
        Node* value;
        std::string type;
        public:
        Expr(bool isvalid, Node* value, std::string type) {
            this->isvalid = isvalid;
            this->type = type;
            this->value = value;
        }
    };

    Expr* checkExpr(std::vector<lex::Token> tokens) {
        if (tokens.size() == 1) {
            // Has to be an integer or an identifier

            if (tokens[0].name == "TT_INTEGER") {
                // Its an integer
            } else if (tokens[0].name == "TT_IDENTIFIER") {
                // Its an identifier
            } else {
                std::string info = "Unknown expression '" + tokens[0].name + "'";
                desc::sendError(desc::errorMessageParser, info, 3);
            }
        }
    }
}