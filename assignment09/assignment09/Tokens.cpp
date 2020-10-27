#include "Tokens.h"
#include "Opcodes.h"
#include <cctype>


using std::size_t;
using std::string;


// Returns whether the string token argument represents an identifier such as a variable name.
// Identifier names are non-empty, begin with an alphabetic character, are not terminated with a ':' character,
// and are not an opcode.
// No other error checking is performed.

bool isIdentifier(const string& token)
{
	bool result = false;

	// TODO: Set result to true if the token is an identifier.
	Opcodes opcode = stringToOpcode(token);
	int issuecount = 0;

	if (token != "" && token[token.length()-1] != ':' && opcode == Opcodes::UNDEFINED && isalpha(token[0]))
	{
	
				result = true;
	}

	if (issuecount > 0)
	{
		result = false;
	}

	return result;
}


// Returns whether the string token argument represents an integer constant.
// Integer constants are non-empty and contain only digits optionally preceded by a '+' or '-' sign.

bool isIntConstant(const string& token)
{
	bool result = false;

	// TODO: Set result to true if the token is an integer constant.
	int issuecount = 0;

	if(token != "")
	{
		for (size_t i = 0; i < token.length(); i++)
		{
			if (isdigit(token[i]) == true)
			{
				result = true;
			}
			if (token[i] == '+' || token[i] == '-')
			{
				result = true;
			}
		}
	}


	return result;
}


// Returns whether the string token argument represents a label definition.
// Labels are non-empty, begin with an alphabetic character, and are terminated with a ':' character.
// No other error checking is performed.

bool isLabelDefinition(const string& token)
{
	bool result = false;

	// TODO: Set result to true if the token is a label definition.
	if (token != "" && isalpha(token[0]) == true && token[token.length() - 1] == ':')
	{
		result = true;
	}

	return result;
}


// Returns whether the string token argument represents a drone command.
// Drone commands consist of at least 2 characters where the first character is '<'
// and the last character is '>'.
// No other error checking is performed.

bool isDroneCommand(const string& token)
{
	bool result = false;

	// TODO: Set result to true if the token is a drone command.
	if (token.length() >= 2 && token[0]=='<' && token[token.length() - 1] =='>')
	{
		result = true;
	}

	return result;
}


// Returns whether the string token argument represents an opcode.

bool isOpcode(const string& token)
{
	bool result = false;

	Opcodes opcode = stringToOpcode(token);

	if (opcode != Opcodes::UNDEFINED) {
		result = true;
	}

	return result;
}


// Return the string argument surrounded with double quotes.

string addQuotes(const string& token)
{
	return ('"' + token + '"');
}
