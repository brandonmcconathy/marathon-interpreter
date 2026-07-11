#include <string>
#include <iostream>

#include <token.hpp>

Token::Token() {
	this->type = "";
	this->literal = "";
}

Token::Token(std::string type, std::string literal) {
	this->type = type;
	this->literal = literal;
}

void Token::print() {
	std::cout << "Type: " << this->type << ", Literal: " << this->literal << std::endl;
}
