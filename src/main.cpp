#include <iostream>
#include <string>

#include <token.hpp>
#include <lexer.hpp>

int main(int argc, char* argv[]) {
	// Starts REPL
	if (argc == 2) {
		// TODO change condition to (argc == 1) and start REPL
		return 0;
	}

	std::string test_string = "+(){};";
	Lexer l = Lexer(test_string);
	l.print();
	while (l.ch != 0) {
		l.readChar();
		l.print();
	}
	return 0;
}
