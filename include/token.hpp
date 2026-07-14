#pragma once
#include <string>
#include <unordered_map>

namespace token {

	struct Token {
		std::string	type;
		std::string	literal;

		Token();
		Token(std::string type, std::string literal);

		void print();
	};

	namespace TokenType {

		// Define possible std::strings
		// Special
		inline constexpr std::string ILLEGAL 	= "ILLEGAL";
		inline constexpr std::string END		= "END";

		// Identifiers and literals
		inline constexpr std::string IDENT		= "IDENT";
		inline constexpr std::string INT 		= "INT";

		// Operators
		inline constexpr std::string ASSIGN 	= "ASSIGN";
		inline constexpr std::string PLUS 		= "+";

		// Delimeters
		inline constexpr std::string COMMA		= ",";
		inline constexpr std::string SEMICOLON	= ";";

		// Utility
		inline constexpr std::string LPAREN 	= "(";
		inline constexpr std::string RPAREN 	= ")";
		inline constexpr std::string LBRACE 	= "{";
		inline constexpr std::string RBRACE 	= "}";

		// Keywords
		inline constexpr std::string FUNCTION 	= "FUNCTION";
		inline constexpr std::string LET 		= "LET";
	}

	inline std::unordered_map<std::string, std::string> keywords = {
		{"fn", TokenType::FUNCTION},
		{"let", TokenType::LET}
	};

	std::string lookupIdent(std::string ident);

}
