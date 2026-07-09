#pragma once
#include <string>

namespace Token {

	using TokenType = std::string;

	struct Token {
		TokenType	Type;
		std::string	Literal;
	};

	// Define possible TokenTypes
	// Special
	inline constexpr TokenType ILLEGAL 		= "ILLEGAL";
	inline constexpr TokenType END			= "END";

	// Identifiers and literals
	inline constexpr TokenType IDENT		= "IDENT";
	inline constexpr TokenType INT 			= "INT";

	// Operators
	inline constexpr TokenType ASSIGN 		= "ASSIGN";
	inline constexpr TokenType PLUS 		= "+";

	// Delimeters
	inline constexpr TokenType COMMA		= ",";
	inline constexpr TokenType SEMICOLON	= ";";

	// Utility
	inline constexpr TokenType LPAREN 		= "(";
	inline constexpr TokenType RPAREN 		= ")";
	inline constexpr TokenType LBRACE 		= "{";
	inline constexpr TokenType RBRACE 		= "}";

	// Keywords
	inline constexpr TokenType FUNCTION 	= "FUNCTION";
	inline constexpr TokenType LET 			= "LET";
}
