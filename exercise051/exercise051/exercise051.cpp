// exercise051.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int num1;
    int num2;
    int num3;

    std::cout << "Enter 3 integers separated by spaces: \n";
    std::cin >> num1 >> num2 >> num3;

    if (num1 > num2 && num1 > num3)
    {
        std::cout << "The largest value entered is: \n" << num1;

    }
    if (num2 > num3 && num2 > num1)
    {
        std::cout << "The largest value entered is: \n" << num2;

    }
    if(num3 > num2 && num3 > num1)
    {
        std::cout << "The largest value entered is: \n" << num3;

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
