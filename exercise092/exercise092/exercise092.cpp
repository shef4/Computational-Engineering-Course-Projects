// exercise092.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int gcd(int a, int b) 
{
    while (b != 0) {
        int b_prev = b; // save old value of b
        b = a % b;      // remainder upon dividing a by b
        a = b_prev;     // assign the old value of b to a
        // display a and b
    }
    return a;
}

int main()
{
    int num1 = 56724, num2 = 48;
    if (gcd(num1 , num2) == 12)
    {
        return 0;
    }
    else {
        std::cout << "ERROR: Funtion gcd(int a, int b) with arguments: "<<num1<<" & "<<num2<<" returned incorrect value: "<< gcd(num1, num2) <<". \nThe function should return value: "<<12<<"\n";
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
