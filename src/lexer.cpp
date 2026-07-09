#include <string>
#include <iostream>

#include <lexer.hpp>

Lexer::Lexer(std::string input) {
	this->input 		= input;
	this->position 		= -1;
	this->readPosition 	= 0;
	this->ch 			= 1;
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

