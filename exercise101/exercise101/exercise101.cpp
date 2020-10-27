// exercise101.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename, word;
    int counter = 0;

    std::cout << "Enter text file name : \n";
    std::cin >> filename ;

    std::cout << "Enter search word:\n";
    std::cin >> word ;

    std::ifstream inf{ filename };

    if (inf) 
    {
        while (!inf.eof())
        {
            // read stuff from the file into a string and print it
            std::string strInput;
            inf >> strInput;

            if (strInput == word)
            {
                counter++;
            }

        }

        std::cout << counter << " occurrences of "<< word << " were found in " << filename;

    }
    else
    {
        std::cout << "File " << filename<< " not found\n";
        return 1;
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
