// exercise081.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    enum class States
    {
        QUARTERS,
        DIMES,
        NICKELS,
        PENNIES,
        DONE
    };

    States state = States::QUARTERS;
    float change=0;
    int quarters =0,
        dimes=0,
        nickles=0,
        pennies=0;

    std::cout << "Please input change amount. \n";
    std::cin >> change;

    while (state != States::DONE) {
        switch (state) {
        case States::QUARTERS:
            // actions performed in the QUARTERS state
            if (change >= 25) {
                change = change - 25;
                quarters++;
            }
            else {
                state = States::DIMES;
            }
            break;
        case States::DIMES:
            // actions performed in the DIMES state
            if (change >= 10) {
                change = change - 10;
                dimes++;
            }
            else {
                state = States::NICKELS;
            }
            break;
        case States::NICKELS:
            // actions performed in the NICKELS state
            if (change >= 5) {
                change = change - 5;
                nickles++;
            }
            else {
                state = States::PENNIES;
            }
            break;
        case States::PENNIES:
            // actions performed in the PENNIES state
            if (change >= 1) {
                change = change - 1;
                pennies++;
            }
            else {
                state = States::DONE;
            }
            break;
        case States::DONE:
            // actions performed in the DONE state
            break;
        default:
            break;
        }

    }
   

    std::cout << "The change is \n" << quarters <<" Quartes, "<< dimes<< " Dimes, "<<nickles<< " Nickles, "<< pennies<<" Pennies";
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
