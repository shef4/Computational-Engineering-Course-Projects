// assignment06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int ibase, obase;
    std::cout << "Please enter a two integer number from 2 to 10 (use a space to separte them)\n";
    std::cin >> ibase >> obase;
    
        if (2 <= ibase <= 10 && 2 <= obase <= 10) {
            
                std::string input;
                std::cout << "Please enter an input (or x to exist)\n";
                std::cin >> input;
                while (input != "x") {
                    int value = 0;
                    
                    for (size_t i = 0; i < (input.length()); i++)
                    {
                        int digit_int = input[i] - 0x30;
                        value = (value * ibase) + digit_int;
                    }
                    std::string output;
                    do{
                        int remainder = value % obase;
                        char digit_char = remainder + 0x30;
                        output.insert(0, 1,digit_char);
                        value = value / obase;
                    } while (value != 0);
                    std::cout << "Input: "<< input <<" of base: " << ibase << " equal to output: " << output << " of base: " << obase << "\n";
                    std::cout << "Please enter an input (or x to exist)\n";
                    std::cin >> input;
                
                }
        }
        else {
            std::cout << "ibase and/or obase is invalid\n";
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
