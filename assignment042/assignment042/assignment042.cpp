// assignment042.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int routingNum;
    int d [9];
    int rNumCut;

    std::cout << "Enter a 9-digit routing number without any spaces:\n";
    std::cin >> routingNum;
    rNumCut = routingNum;
    for (size_t i = 0; i < 9; i++)
    {
        d[i] = rNumCut % 10;
        rNumCut = rNumCut / 10;

    }

    int sum = (3 * (d[8] + d[5] + d[2])) + (7 * (d[7] + d[4] + d[1])) + (d[6] + d[3] + d[0]);
    //std::cout << d[0] << "\n" << d[1] << "\n" << d[2] << "\n" << d[3] << "\n" << d[4] << "\n" << d[5] << "\n" << d[6] << "\n" << d[7] << "\n" << d[8] << "\n";
    if ((sum % 10) == 0) 
    {
        std::cout << "Routing number is valid\n";
    }
    else
    {
        std::cout << "Routing number is invalid\n";
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
