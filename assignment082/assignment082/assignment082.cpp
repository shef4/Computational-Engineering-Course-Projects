#include "FlightPlanParse.h"
#include <iostream>
#include <fstream>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;


// The program prompts for the name of a Flight Plan Language file
// and displays any tokens extracted from each line.


int main()
{
	cout << "Enter the FPL file name without the .txt suffix: ";

	string file_name;
	cin >> file_name;
	file_name += ".txt";

	ifstream fpl_file(file_name);

	if (fpl_file.is_open()) {
		string line;
		while (getline(fpl_file, line)) {
			cout << line << endl;
			line += ' ';
			parseLine(line);
		}
	}
	else {
		cout << "File " << file_name << " not found" << endl;
	}

	return 0;
}
