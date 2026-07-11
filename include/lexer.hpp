#pragma once

#include <string>

#include <token.hpp>

struct Lexer {
	std::string	input;
	int 		position;
	int 		readPosition;
	char		ch;

	Lexer(std::string input);

	void print();

	void readChar();

	Token nextToken();

	Token newToken(std::string tokenType, char ch);
};
