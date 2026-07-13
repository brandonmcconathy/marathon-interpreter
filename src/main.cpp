#include <iostream>
#include <string>
#include <vector>

#include <token.hpp>
#include <lexer.hpp>

int main(int argc, char* argv[]) {
	// Starts REPL
	if (argc == 2) {
		// TODO change condition to (argc == 1) and start REPL
		std::cout << "Functionality not yet implemented" << std::endl;
		return 1;
	}

	std::string test_string = "+(){};";

	// Tokenize input 
	lexer::Lexer l = lexer::Lexer(test_string);
	std::vector<token::Token> tokenized_input;
	token::Token currToken;
	while (currToken.type != token::TokenType::END) {
		currToken = l.nextToken();
		tokenized_input.push_back(currToken);
	}

	// Print Tokens
	for (int i = 0; i < tokenized_input.size(); i++) {
		tokenized_input[i].print();
	}

	return 0;
}
