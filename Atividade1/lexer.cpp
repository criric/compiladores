#include "lexer.h"
#include <iostream>
#include <sstream>
using std::cin;
using std::cout;
using std::stringstream;

// Construtor
Lexer::Lexer()
{
	// Insere as palavras-reservadas na tabela de id's
	id_table["true"] = Id{Tag::TRUE, "true"};
	id_table["false"] = Id{Tag::FALSE, "false"};
}

void Lexer::IgnoreComment()
{
	if (peek == '/')
	{
		peek = cin.get(); // Lê o próximo caractere

		if (peek == '/')
		{ // Comentário de linha
			// Ignora até o final da linha
			while (peek != '\n' && peek != EOF)
			{
				peek = cin.get();
			}
			// Avança para o próximo caractere após o \n
			peek = cin.get();
		}
		else if (peek == '*')
		{ // Comentário de bloco
			// Ignora até encontrar */
			while (true)
			{
				peek = cin.get();
				if (peek == EOF)
					break; // Proteção para fim de arquivo
				if (peek == '*')
				{
					peek = cin.get();
					if (peek == '/')
						break; // Encontrou "*/"
				}
			}
			// Avança para o próximo caractere
			peek = cin.get();
		}
	}
}

Token Lexer::Scan()
{
	// Salta espaços em branco, tabulações e novas linhas
	while (isspace(peek))
	{
		if (peek == '\n')
			line += 1;
		peek = cin.get();
	}

	// Verifica se encontrou um comentário e ignora
	if (peek == '/')
	{
		IgnoreComment(); // Ignora o comentário
		return Scan();	 // Continua procurando um token
	}

	// Retorna números
	if (isdigit(peek))
	{
		int v = 0;
		do
		{
			int n = peek - '0';
			v = 10 * v + n;
			peek = cin.get();
		} while (isdigit(peek));

		cout << "<NUM," << v << "> ";
		return Num{v};
	}

	// Retorna palavras-chave e identificadores
	if (isalpha(peek))
	{
		stringstream ss;
		do
		{
			ss << peek;
			peek = cin.get();
		} while (isalpha(peek));

		string s = ss.str();
		auto pos = id_table.find(s);

		if (pos != id_table.end())
		{
			cout << "<" << (pos->second.tag == TRUE ? "TRUE" : "FALSE")
					 << "," << pos->second.name << "> ";
			return pos->second;
		}

		Id new_id{Tag::ID, s};
		id_table[s] = new_id;

		cout << "<ID," << new_id.name << "> ";
		return new_id;
	}

	// Operadores e caracteres isolados
	Token t{peek};
	peek = ' ';

	cout << "<" << char(t.tag) << "> ";
	return t;
}

void Lexer::Start()
{
	// Simula o analisador sintático pedindo tokens para o analisador léxico
	while (peek != '\n')
	{
		Scan();
	}
}
