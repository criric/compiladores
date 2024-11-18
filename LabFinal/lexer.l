%{
// Reconhecedor de uma linguagem simplificada
#include <iostream>
#include "tokens.h"
using std::cout;
%}

%option noyywrap
delim	[ \t\n]
brancos {delim}+
letra	[A-Za-z]
digito	[0-9]
id	    ({letra}|_)(({letra}|{digito}|_)*) 
integer  {digito}+
float    {digito}+"."{digito}+([eE][+-]?{digito}+)?
string   \"([^"\\]|\\.|\\\\)*\"

%%
\/\/[^\n]*             
\/\*([^*]|\*+[^*/])*\*\/ 
{brancos}	;


if		    return Tag::IF; 
then		return Tag::THEN; 
else		return Tag::ELSE; 
while		return Tag::WHILE; 
do          return Tag::DO;
main        return Tag::MAIN;
int         return Tag::TYPE;
float       return Tag::TYPE;
bool        return Tag::TYPE;
true        return Tag::TRUE;
false       return Tag::FALSE;


{id}		return Tag::ID;  
{integer}	return Tag::INTEGER; 
{float}     return Tag::FLOATING;
{string}    return Tag::STRING;


"<"         return Tag::LT; 
"<="        return Tag::LTE; 
"=="        return Tag::EQ; 
"="         return Tag::ATT; 
"!="        return Tag::NE; 
">"         return Tag::GT;
">="        return Tag::GTE;
"||"        return Tag::OR; 
"&&"        return Tag::AND; 

"+"         return Tag::SOMA;
"-"         return Tag::SUBT;
"*"         return Tag::MULT;
"/"         return Tag::DIV;
"!"         return Tag::NEGACAO;

"("         return Tag::PARENESQ;
")"         return Tag::PARENDIR;
"["         return Tag::COLCHETEESQ;
"]"         return Tag::COLCHETEDIR;
"{"         return Tag::CHAVEESQ;
"}"         return Tag::CHAVEDIR;
";"         return Tag::PONTOVIRGULA;
.           cout << YYText() << " é um token inválido!\n"; 
%%

// nenhuma função auxiliar é necessária
