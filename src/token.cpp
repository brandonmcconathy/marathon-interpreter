#include <string>
#include <iostream>

#include <token.hpp>

token::Token::Token() {
	this->type = "";
	this->literal = "";
}

token::Token::Token(std::string type, std::string literal) {
	this->type = type;
	this->literal = literal;
}

void token::Token::print() {
	std::cout << "Type: " << this->type << ", Literal: " << this->literal << std::endl;
}

std::string token::lookupIdent(std::string ident) {
	if (token::keywords.contains(ident)) {
		return token::keywords[ident];
	}
	return token::TokenType::IDENT;
}
