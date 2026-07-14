#include <string>
#include <iostream>

#include <lexer.hpp>
#include <token.hpp>

lexer::Lexer::Lexer(std::string input) {
	this->input 		= input;
	this->position 		= -1;
	this->readPosition 	= 0;
	this->ch 			= 1;
	this->readChar();
}

void lexer::Lexer::print() {
	std::cout << "input: " << this->input << "\n";
	std::cout << "position: " << this->position << "\n";
	std::cout << "readPosition: " << this->readPosition << "\n";
	std::cout << "ch: " << this->ch << std::endl;
}

void lexer::Lexer::readChar() {
	if (this->readPosition >= static_cast<int>(input.length())) {
		this->ch = 0;
	} else {
		this->ch = this->input[this->readPosition];
	}
	this->position = this->readPosition;
	this->readPosition++;
}

token::Token lexer::Lexer::nextToken() {
	token::Token tok;

	this->eatWhitespace();

	switch (this->ch) {
		case '=':
			tok = this->newToken(token::TokenType::ASSIGN, this->ch);
			break;
		case ';':
			tok = this->newToken(token::TokenType::SEMICOLON, this->ch);
			break;
		case '(':
			tok = this->newToken(token::TokenType::LPAREN, this->ch);
			break;
		case ')':
			tok = this->newToken(token::TokenType::RPAREN, this->ch);
			break;
		case ',':
			tok = this->newToken(token::TokenType::COMMA, this->ch);
			break;
		case '+':
			tok = this->newToken(token::TokenType::PLUS, this->ch);
			break;
		case '{':
			tok = this->newToken(token::TokenType::LBRACE, this->ch);
			break;
		case '}':
			tok = this->newToken(token::TokenType::RBRACE, this->ch);
			break;
		case 0:
			tok = this->newToken(token::TokenType::END, this->ch);
			break;
		default:
			if (this->isLetter()) {
				tok.literal = this->readIdentifier();
				tok.type = token::lookupIdent(tok.literal);
				return tok;
			}
			tok = this->newToken(token::TokenType::ILLEGAL, this->ch);
			break;
	}
	this->readChar();
	return tok;
}

token::Token lexer::Lexer::newToken(std::string type, char ch) {
	return token::Token(type, {ch});
}

bool lexer::Lexer::isLetter() {
	return (this->ch >= 'A' && this->ch <= 'Z') || (this->ch >= 'a' && this->ch <= 'z');
}

std::string lexer::Lexer::readIdentifier() {
	int startPos = this->position;
	while (this->isLetter()) {
		this->readChar();
	}
	return this->input.substr(startPos, this->position - startPos);
}

void lexer::Lexer::eatWhitespace() {
	while (this->ch == ' ' || this->ch == '\t' || this->ch == '\n' || this->ch == '\r') {
		this->readChar();
	}
}
