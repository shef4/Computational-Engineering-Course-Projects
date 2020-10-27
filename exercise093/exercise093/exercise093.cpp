// exercise093.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
void lowerToUpper(std::string& sentence)
{
	for (size_t i = 0; i < sentence.length(); i++)
	{
		if (islower(sentence[i]))
		{
			sentence[i] = toupper(sentence[i]);
		}
	}
}

int main()
{
	std::string sentence = "Hello how are you doing?";

	bool valid = true;

	lowerToUpper(sentence);

	for (size_t i = 0; i < sentence.length()-1; i++)
	{
		if (!isupper(sentence[i]) && sentence[i] != ' ')
		{
			valid = false;
		}
	}

	if (valid == true)
	{
		return 0;
	}else
	{
		std::cout << "ERROR: \nFunction: void lowerToUpper(std::string& sentence) \nwith argument: lowerToUpper(sentence) \nProvided incoreect result: "<<sentence<<"\n";
		return -1;
	}
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
