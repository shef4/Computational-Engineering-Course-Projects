// quadratic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    float a;
    float b;
    float c;
    float x;

    while ( !(x == 0))
    {
        std::cout << "For the quadratic ax^2 + bx + c = 0, enter a, b and c separated by spaces (enter zeroes to exit):";
        std::cin >> a >> b >> c;
        std::cout << "(enter zeroes to exit and 1 to re enter your numbers):";
        std::cin >> x;
        
    }

    float D = (b * b) - (4 * a * c);

    if (D > 0)
    {
        float r1 = (-b + sqrt(D)) / (2 * a);
        float r2 = (-b - sqrt(D)) / (2 * a);

        std::cout << " The real roots are "<< r1 <<" and "<< r2 <<"\n";
    }

    if (D < 0)
    {
        float rc = -(b / (2 * a));
        float i = sqrt(abs(D))/(2*a);

        std::cout << " The complex roots are "<< rc <<" +/- "<< i <<" i\n";
    }

    if (D == 0)
    {
        float r = -(b / (2 * a));

        std::cout << " The single real root is " << r << "\n";
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
