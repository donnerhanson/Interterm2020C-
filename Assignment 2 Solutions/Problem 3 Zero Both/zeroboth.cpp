/*
 ASSIGNMENT ZERO BOTH

Author: Donner Hanson
Date: 1/13/2020
UserID: 1276484

Assignment:
Problem 3 (zeroboth.cpp): Implement a void function called
 zeroBoth that has two call-by- reference parameters,
 both of which are variables of type int, and sets
 the values of both variables to 0.
 */


#include <iostream>



// USING STATEMENTS FROM RESPECTIVE LIBRARIES

//iostream
using std::cerr;
using std::cin;
using std::cout;
using std::endl;


// CONST EXPRESSIONS


//FUNCTION - Declarations
void zeroBoth (int &a, int &b);

// MAIN
int main(int argc, const char * argv[]) {

    int a(100), b(100);
    zeroBoth(a, b);
    cout << a << ", " << b << endl;
    return 0;
}
//Function Definitions
void zeroBoth (int &a, int &b)
{
    a = 0;
    b = 0;
}
