// exercise072.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    const int NUM_VALUES = 7;
	int num_Array[NUM_VALUES];

    std::cout << "Enter "<< NUM_VALUES <<" integers separated by blanks: \n";

	for (size_t i = 0; i < NUM_VALUES; i++)
	{
		std::cin >> num_Array[i];
	}

	std::cout << "The array contents in reverse order : \n";

	for (size_t i = 0; i < NUM_VALUES; i++)
	{
		int value = NUM_VALUES - (i + 1); //selects the array values in reverse

		std::cout << num_Array[value] << " ";
	}
	

	return 0;
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
