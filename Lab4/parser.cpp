#include "parser.h"
#include "tokens.h"
#include <iostream>
using std::cout;
using std::string;

#include <string>

std::string processEscapedCharacters(const std::string& input) {
    std::string output;
    size_t length = input.length();

    for (size_t i = 0; i < length; ++i) {
        if (input[i] == '\\' && (i + 1) < length) {
            char nextChar = input[i + 1];
            if (nextChar == '"') {
                output += '"';
                ++i;
            } else if (nextChar == '\\') {
                output += '\\';
                ++i;
            } else {
                output += input[i];
            }
        } else {
            output += input[i];
        }
    }

    return output;
}


void Parser::Start()
{
    // enquanto não atingir o fim da entrada
    while ((lookahead = scanner.yylex()) != 0)
    {
        // trata o token recebido do analisador léxico
        switch(lookahead)
        {
            case IF: cout << "IF\n"; break;
            case THEN: cout << "THEN\n"; break;
            case ELSE: cout << "ELSE\n"; break;
            case WHILE: cout << "WHILE\n"; break;
            case ID: cout << "ID: " << scanner.YYText() << "\n"; break;
            case NUM: cout << "NUM: " << scanner.YYText() << "\n"; break;
            case RELOP: cout << "RELOP: " << scanner.YYText() << "\n";; break;
            case STRING: cout << "STRING: " << processEscapedCharacters(scanner.YYText()) << "\n"; break;
                
        }
    }
}