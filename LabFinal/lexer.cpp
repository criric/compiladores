#include "lexer.h"
#include <FlexLexer.h>
#include <fstream>
#include <sstream>

using std::stringstream;

extern std::ifstream fin;

extern int yylex();
extern Lexer * scanner;


int Lexer::Lineno()
{
	return line;
}

Token * Lexer::Scan()
{ 
	if ((lookahead = yylex()) != 0){
        token = Token{lookahead, YYText()};
        return &token;
    } else
		return nullptr;
} 
