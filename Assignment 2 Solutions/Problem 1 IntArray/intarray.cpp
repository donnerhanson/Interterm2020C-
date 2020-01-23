/*
 ASSIGNMENT IntArray
 
 Author: Donner Hanson
 Date: 1/23/2020
 UserID: 1276484
 
 Assignment:
 Problem 1 (intarray.cpp): Write a program that will read up to ten
 nonnegative integers into an array called
 numberArray and then write the integers back to the screen (console
 output). For this exercise you need not use any functions.
 */

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

// USING STATEMENTS FROM RESPECTIVE LIBRARIES
//iostream
using std::cout;
using std::cin;
using std::endl;
// limits
using std::numeric_limits;
// string
using std::string;
using std::to_string;
// sstream
using std::stringstream;
// CONST EXPRESSIONS
const int ARR_SZ = 10;
const string MAX_INT_VAL = to_string(numeric_limits<int>::max());
const string DIGITS = "0123456789";
const string NUM_TOO_LARGE_MSG = "Number too large for integer storage\n";
//FUNCTIONS


// MAIN
int main(int argc, const char * argv[]) {
    int numberArray[ARR_SZ];
    for (int i(0); i < ARR_SZ; ++i)
    {
        numberArray [i] = -1;  // initialize all to -1
    }
    
    string userIn = "";
    int convertedNum(0);
    cout << "This program will output non-negative numbers"
    << " that are entered by a user. Enter a negative number or"
    << " alphabetic character to quit and output\n";
    cout << "Enter first number: ";
    stringstream strToNum("");
    for (int i(0); convertedNum >= 0 && i < ARR_SZ; ++i)
    {
        
        cin >> userIn;
        // check if empty and if positive integer
        if (!userIn.empty() &&
            userIn.find_first_not_of(DIGITS) == std::string::npos)
        {
            if (userIn.length() == MAX_INT_VAL.length())
            {
                bool isTooLarge(false);
                for (int j(0); j < userIn.length(); ++j)
                {
                    // if the number is greater than the max int value break
                    if (userIn.at(j) > MAX_INT_VAL.at(j))
                    {
                        isTooLarge = true;
                        break;
                    }
                    // at least one digit in length is smaller - fits
                    else if (userIn.at(j) < MAX_INT_VAL.at(j))
                    {
                        break;
                    }
                }
                if (isTooLarge)
                {
                    cout << NUM_TOO_LARGE_MSG;
                    break;
                }
                
            }
            else if (userIn.length() > MAX_INT_VAL.length())
            {
                cout << NUM_TOO_LARGE_MSG;
                break;
            }
            // else its a good length
            strToNum << userIn;
            strToNum >> convertedNum;
            numberArray[i] = convertedNum;
            // clear eof bit to reset stream insertion
            strToNum.clear();
            // technically more efficient than .str("")
            strToNum.str(std::string());
            
        }
        else
        {
            break;
        }
        if (i < ARR_SZ - 1)
            cout << "Enter next number: ";
    }
    if (numberArray[0] != -1) // formatting
        cout << "Stored values: " << endl;
    // all invalid elements set to -1 - will break when -1 found
    for (int i(0); i < ARR_SZ && numberArray[i] >= 0; ++i)
    {
        cout << numberArray[i] << endl;
    }
    return 0;
}
