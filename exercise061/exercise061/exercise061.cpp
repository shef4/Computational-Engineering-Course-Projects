// exercise061.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::string alphabet;
    std::string digits;
    std::string alphanumeric;

    std::cout << "Alphabet length is "<< alphabet.length() <<"\n";

    for (int c = 97; c <= 122; ++c) 
        alphabet += (char)c;

    std::cout << "Alphabet length is now " << alphabet.length() << "\n";

    digits += "0123456789";

    std::cout << "The Last Digit value is " << digits.substr(9,1) << "\n";

    alphanumeric.assign(alphabet);
    alphanumeric.append(digits);

    std::cout << "The location of 'yz01' in the alphanumeric string is " << alphanumeric.find("yz01")<< "\n";

    std::cout << "Here is a substring of the alphanumaric String " << alphanumeric.substr(25, 4) << "\n";
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
