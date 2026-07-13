#pragma once

#include <string>

#include <token.hpp>

namespace lexer {

	struct Lexer {
		std::string	input;
		int 		position;
		int 		readPosition;
		char		ch;

		Lexer(std::string input);

		void print();

		void readChar();

		token::Token nextToken();

		token::Token newToken(std::string tokenType, char ch);

		bool isLetter();

		std::string readIdentifier();
	};

}
