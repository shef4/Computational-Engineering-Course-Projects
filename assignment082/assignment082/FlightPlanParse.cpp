#include "FlightPlanParse.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;
using std::size_t;


// Accepts a string corresponding to line of an FPL program.
// White space (space and tab characters) are skipped over.
// A '#' character indicates the start of a comment that extends to the end of the line.
// Any tokens appearing in the line are accumulated character by character and displayed.
// A line is not required to have any tokens, and could be blank or only a comment.
// The line must have white space after every token including the last token on the line.

void parseLine(const string& line)
{
	const char BLANK         = ' ';   // Your code should use all of these constants.
	const char TAB           = '\t';
	const char COMMENT_START = '#';
	const char DRONE_START   = '<';
	const char DRONE_END     = '>';

	enum class ParseStates { WHITE_SPACE, COMMENT, DRONE_COMMAND, OTHER_TOKEN };

	ParseStates state = ParseStates::WHITE_SPACE;  // Initially in the WHITE_SPACE state

	string token;                 // Accumulates characters forming a token

	bool complete_token = false;  // Set to true when a complete token has been formed

	const size_t n = line.length();

	for (size_t i = 0; i < n; i++) {
		const char c = line[i];  // const to catch "c = " errors in if statements
		switch (state) {
		case ParseStates::WHITE_SPACE:
			// TODO: define the actions and possible transitions for the WHITE_SPACE state
			if (c == BLANK || c == TAB)
			{
				state = ParseStates::WHITE_SPACE;
			}
			if (c == COMMENT_START)
			{
				state = ParseStates::COMMENT;
				i = n;
			}
			if (c == DRONE_START)
			{
				state = ParseStates::DRONE_COMMAND;
				token = line.substr(i - 1, n);
				complete_token = true;
				i = n;
			}
			if (c != DRONE_START && c != COMMENT_START && c != TAB && c != BLANK && c != DRONE_END)
			{
				state = ParseStates::OTHER_TOKEN;
				token += line[i];
				if (line[i + 1] == BLANK)
				{
					complete_token = true;
				}

			}
			break;
		case ParseStates::COMMENT:
			// TODO: define the actions (if any) for the COMMENT state
			if (c == BLANK || c == TAB)
			{
				state = ParseStates::WHITE_SPACE;
			}
			if (c == COMMENT_START)
			{
				state = ParseStates::COMMENT;
				i = n;
			}
			if (c == DRONE_START)
			{
				state = ParseStates::DRONE_COMMAND;
				token = line.substr(i - 1, n);
				complete_token = true;
				i = n;
			}
			if (c != DRONE_START && c != COMMENT_START && c != TAB && c != BLANK && c != DRONE_END)
			{
				state = ParseStates::OTHER_TOKEN;
				token += line[i];
				if (line[i + 1] == BLANK)
				{
					complete_token = true;
				}

			}
			break;
		case ParseStates::DRONE_COMMAND:
			// TODO: define the actions and possible transitions for the DRONE_COMMAND state
			if (c == BLANK || c == TAB)
			{
				state = ParseStates::WHITE_SPACE;
			}
			if (c == COMMENT_START)
			{
				state = ParseStates::COMMENT;
				i = n;
			}
			if (c == DRONE_START)
			{
				state = ParseStates::DRONE_COMMAND;
				token = line.substr(i - 1, n);
				complete_token = true;
				i = n;
			}
			if (c != DRONE_START && c != COMMENT_START && c != TAB && c != BLANK && c != DRONE_END)
			{
				state = ParseStates::OTHER_TOKEN;
				token += line[i];
				if (line[i + 1] == BLANK)
				{
					complete_token = true;
				}

			}
			break;
		case ParseStates::OTHER_TOKEN:
			// TODO: define the actions and possible transitions for the OTHER_TOKEN state
			if (c == BLANK || c == TAB)
			{
				state = ParseStates::WHITE_SPACE;
			}
			if (c == COMMENT_START)
			{
				state = ParseStates::COMMENT;
				i = n;
			}
			if (c == DRONE_START)
			{
				state = ParseStates::DRONE_COMMAND;
				token = line.substr(i - 1, n);
				complete_token = true;
				i = n;
			}
			if (c != DRONE_START && c != COMMENT_START && c != TAB && c != BLANK && c != DRONE_END)
			{
				state = ParseStates::OTHER_TOKEN;
				token += line[i];
				if (line[i + 1] == BLANK)
				{
					complete_token = true;
				}

			}
			break;
		default:
			break;
		}
		if (complete_token) {
			cout << "\t\ttoken: \"" << token << '"' << endl;
			token.erase();
			complete_token = false;
		}
	}
}
