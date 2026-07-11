#include <string>
#include <iostream>

#include <lexer.hpp>
#include <token.hpp>

Lexer::Lexer(std::string input) {
	this->input 		= input;
	this->position 		= -1;
	this->readPosition 	= 0;
	this->ch 			= 1;
	this->readChar();
}

void Lexer::print() {
	std::cout << "input: " << this->input << std::endl;
	std::cout << "position: " << this->position << std::endl;
	std::cout << "readPosition: " << this->readPosition << std::endl;
	std::cout << "ch: " << this->ch << std::endl;
}

void Lexer::readChar() {
	if (this->readPosition >= input.length()) {
		this->ch = 0;
	} else {
		this->ch = this->input[this->readPosition];
	}
	this->position = this->readPosition;
	this->readPosition++;
}

Token Lexer::nextToken() {
	Token tok;

	switch (this->ch) {
		case '=':
			tok = this->newToken(TokenType::ASSIGN, this->ch);
			break;
		case ';':
			tok = this->newToken(TokenType::SEMICOLON, this->ch);
			break;
		case '(':
			tok = this->newToken(TokenType::LPAREN, this->ch);
			break;
		case ')':
			tok = this->newToken(TokenType::RPAREN, this->ch);
			break;
		case ',':
			tok = this->newToken(TokenType::COMMA, this->ch);
			break;
		case '+':
			tok = this->newToken(TokenType::PLUS, this->ch);
			break;
		case '{':
			tok = this->newToken(TokenType::LBRACE, this->ch);
			break;
		case '}':
			tok = this->newToken(TokenType::RBRACE, this->ch);
			break;
		case 0:
			tok = this->newToken(TokenType::END, this->ch);
			break;
		default:
			tok = this->newToken(TokenType::ILLEGAL, this->ch);
			break;
	}
	this->readChar();
	return tok;
}

Token Lexer::newToken(std::string type, char ch) {
	return Token(type, {ch});
}
