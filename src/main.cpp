#include <iostream>
#include <string>
#include <vector>

#include <token.hpp>
#include <lexer.hpp>

void test(std::string input) {
	std::cout << "Running test on input: " << input << "\n" << std::endl;

	// Tokenize input
	lexer::Lexer l = lexer::Lexer(input);
	std::vector<token::Token> tokenized_input;
	token::Token currToken;
	while (currToken.type != token::TokenType::END) {
		currToken = l.nextToken();
		tokenized_input.push_back(currToken);
	}

	// Print Tokens
	for (size_t i = 0; i < tokenized_input.size(); i++) {
		tokenized_input[i].print();
	}
	
	std::cout << "Finished test\n" << std::endl;
}

int main(int argc, char* argv[]) {
	// Starts REPL
	if (argc == 2) {
		// TODO change condition to (argc == 1) and start REPL
		std::cout << "Functionality not yet implemented" << std::endl;
		return 1;
	}

	std::string test_string_1 = "+(){};";
	std::string test_string_2 = R"(
	let five = 5;
	let ten = 10;

	let add = fn(x, y) {
		x + y;
	}

	let result = add(five, ten);
	)";

	// Run Tests
	test(test_string_1);
	test(test_string_2);

	return 0;
}
