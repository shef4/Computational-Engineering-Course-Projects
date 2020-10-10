// Exercise 03.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int intNum;
    double dNum;
    float fNum;
    char cchar;

    std::cout << "Enter an int:\n";
    std::cin >> intNum;
    std::cout << "Enter a double:\n";
    std::cin >> dNum;
    std::cout << "Enter a float:\n";
    std::cin >> fNum;
    std::cout << "Enter a character:\n";
    std::cin >> cchar;


    intNum = 5;
    dNum = 5.32;
    fNum = 22/7;
    cchar = 'a' ;

    std::cout << "Your new int is: " << intNum << "\n";
    std::cout << "Your new double is: " << dNum << "\n";
    std::cout << "Your new float is: " << fNum << "\n";
    std::cout << "Your new character is: " << cchar ;

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
