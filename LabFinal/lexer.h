#ifndef COMPILER_LEXER
#define COMPILER_LEXER

#include <FlexLexer.h>
#include "tokens.h"
#include <string>

#include <unordered_map>
using std::unordered_map;
using std::string;

struct Token
{
	int tag;
	std::string lexeme;

	Token() : tag(0) {}
	Token(char ch) : tag(int(ch)), lexeme({ch}) {}
	Token(int t, std::string s) : tag(t), lexeme(s) {}
};


class Lexer : public yyFlexLexer
{
private:
	int line = 1;		
	int lookahead;

	Token token;		
public:
	explicit Lexer(std::istream* in) : yyFlexLexer(in) {}
	int Lineno();		
	Token * Scan();	
};

#endif
