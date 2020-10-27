#include "Tokens.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;
using std::string;


// This program performs automated unit tests for the isIdentifier(), isIntConstant(),
// isLabelDefinition(), isDroneCommand() and isOpcode() functions.
// These functions are called with various token string arguments to determine whether
// the functions work correctly.
// If an individual test passes then no output is generated for the test.
// If an individual test fails then the function name and token causing the failure are
// displayed on cout.
// At the end of testing the number of failing tests are written to cout.
// If all tests pass then program's return code is 0; otherwise -1 is returned.


int main()
{
    int return_code = 0;

    int error_count = 0;

    // Two unit tests are provided to get you started.
    string token = "add";
    if (isOpcode(token) == false) {
        cout << "isOpcode(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }
    token = "abc";
    if (isOpcode(token) == true) {
        cout << "isOpcode(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    // TODO: Insert your 18 additional unit tests here.
    token = "sEt";
    if (isOpcode(token) == true) {
        cout << "isOpcode(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "3eg";
    if (isOpcode(token) == true) {
        cout << "isOpcode(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }



   
    token = "int";
    if (isIdentifier(token) == true) {
        cout << "isIdentifier(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "abc:";
    if (isIdentifier(token) == true) {
        cout << "isIdentifier(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "";
    if (isIdentifier(token) == true) {
        cout << "isIdentifier(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "zyc";
    if (isIdentifier(token) == false) {
        cout << "isIdentifier(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }





    token = "";
    if (isIntConstant(token) == true) {
        cout << "isIntConstant(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "a68";
    if (isIntConstant(token) == true) {
        cout << "isIntConstant(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "+123";
    if (isIntConstant(token) == false) {
        cout << "isIntConstant(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }
    token = "557";
    if (isIntConstant(token) == false) {
        cout << "isIntConstant(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }



    token = "";
    if (isLabelDefinition(token) == true) {
        cout << "isLabelDefinition(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "a1c3";
    if (isLabelDefinition(token) == true) {
        cout << "isLabelDefinition(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "abc:";
    if (isLabelDefinition(token) == false) {
        cout << "isLabelDefinition(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }
    token = "bbb";
    if (isLabelDefinition(token) == true) {
        cout << "isLabelDefinition(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }





    token = "ab>";
    if (isDroneCommand(token) == true) {
        cout << "isDroneCommand(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "<532>";
    if (isDroneCommand(token) == false) {
        cout << "isDroneCommand(" << addQuotes(token) << ") should be true" << endl;
        error_count++;
    }
    token = "<";
    if (isDroneCommand(token) == true) {
        cout << "isDroneCommand(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }
    token = "<34";
    if (isDroneCommand(token) == true) {
        cout << "isDroneCommand(" << addQuotes(token) << ") should be false" << endl;
        error_count++;
    }






    cout << error_count << " errors occurred" << endl;

    if (error_count > 0) {
        return_code = -1;
    }

    return return_code;
}
