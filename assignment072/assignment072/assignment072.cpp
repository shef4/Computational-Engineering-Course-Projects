// assignment072.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	struct Employee
	{
		std::string firstName;
		std::string lastName;
		float browserMin;
	};

	const int NUM_EMPLOYEES = 10;

	Employee arrE[NUM_EMPLOYEES];
	
	float sum = 0;


	for (size_t i = 0; i < NUM_EMPLOYEES; i++)
	{
		std::cout << "Please enter employees first name, last name and browser minutes (add a space inbetween values)\n";
		std::cin >> arrE[i].firstName >> arrE[i].lastName >> arrE[i].browserMin;

		sum += arrE[i].browserMin;
	}

	float avgTime = sum/NUM_EMPLOYEES;

	std::cout << "\n Here are the employees whos browser time is twice that of the average. \n";
	for (size_t i = 0; i < NUM_EMPLOYEES; i++)
	{
		if ( arrE[i].browserMin > (2*avgTime))
		{
			std::cout << "Firstname: " << arrE[i].firstName << " Lastname: " << arrE[i].lastName << " Browser Time (minutes): " << arrE[i].browserMin << "\n";
		}
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
