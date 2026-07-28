#include <gtest/gtest.h>

#include <token.hpp>
#include <lexer.hpp>

TEST(LexerTest, Test1) {

	std::string input = R"(
		let five = 5;
		let ten = 10;

		let add = fn(x, y) {
			x + y;
		};

		let result = add(five, ten);
		)";

	std::vector<token::Token> expected_tokens = {
		{token::TokenType::LET, "let"},
		{token::TokenType::IDENT, "five"},
		{token::TokenType::ASSIGN, "="},
		{token::TokenType::INT, "5"},
		{token::TokenType::SEMICOLON, ";"},
		{token::TokenType::LET, "let"},
		{token::TokenType::IDENT, "ten"},
		{token::TokenType::ASSIGN, "="},
		{token::TokenType::INT, "10"},
		{token::TokenType::SEMICOLON, ";"},
		{token::TokenType::LET, "let"},
		{token::TokenType::IDENT, "add"},
		{token::TokenType::ASSIGN, "="},
		{token::TokenType::FUNCTION, "fn"},
		{token::TokenType::LPAREN, "("},
		{token::TokenType::IDENT, "x"},
		{token::TokenType::COMMA, ","},
		{token::TokenType::IDENT, "y"},
		{token::TokenType::RPAREN, ")"},
		{token::TokenType::LBRACE, "{"},
		{token::TokenType::IDENT, "x"},
		{token::TokenType::PLUS, "+"},
		{token::TokenType::IDENT, "y"},
		{token::TokenType::SEMICOLON, ";"},
		{token::TokenType::RBRACE, "}"},
		{token::TokenType::SEMICOLON, ";"},
		{token::TokenType::LET, "let"},
		{token::TokenType::IDENT, "result"},
		{token::TokenType::ASSIGN, "="},
		{token::TokenType::IDENT, "add"},
		{token::TokenType::LPAREN, "("},
		{token::TokenType::IDENT, "five"},
		{token::TokenType::COMMA, ","},
		{token::TokenType::IDENT, "ten"},
		{token::TokenType::RPAREN, ")"},
		{token::TokenType::SEMICOLON, ";"},
		{token::TokenType::END, " "}
	};

	// Tokenize input
	lexer::Lexer l = lexer::Lexer(input);
	std::vector<token::Token> tokenized_input;
	token::Token currToken;
	while (currToken.type != token::TokenType::END) {
		currToken = l.nextToken();
		tokenized_input.push_back(currToken);
	}

	// Makes sure we generated the correct amount of tokens
	ASSERT_EQ(expected_tokens.size(), tokenized_input.size());

	// Tests each token
	for (size_t i = 0; i < expected_tokens.size(); i++) {
		EXPECT_EQ(expected_tokens[i], tokenized_input[i]);
	}
}
