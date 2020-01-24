/*ASSIGNMENT 2DARRAY
 
 Author: Donner Hanson
 Date: 1/23/2020
 UserID: 1276484
 
 Assignment:
 Problem 2 (2darray.cpp):
 Write code that will fill the array 'a'
 (declared below) with numbers typed in at
 the keyboard.
 The numbers will be input:
 five per line,
 on four lines
 (although your solution need not depend on
 how the input numbers are divided into lines).
 
 int a[4][5];
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// USING STATEMENTS FROM RESPECTIVE LIBRARIES
//iostream
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::getline;
// sstream
using std::stringstream;
// string
using std::string;

// CONST EXPRESSIONS
const int ROWS = 4; // CHANGE THIS TO ADJUST ARRAY SIZE - ROWS
const int COLS = 5; // CHANGE THIS TO ADJUST ARRAY SIZE - COLUMNS
const string DIGITS = "0123456789 ";
const string ERROR_DETECTED = "Invalid character detected. Output may be corrupted...";
const string F_N_F = "File not found";
//FUNCTIONS

// MAIN
int main(int argc, const char * argv[]) {
    if (argc == 2) // TEST CASE WITH FILE
    {
        string fileName = argv[1];
        std::ifstream fs;
        fs.open(fileName);
        if (!fs)
        {
            cout << F_N_F << endl;
            return 1;
        }
        int a[ROWS][COLS] = { 0 };
        int convertedNum = 0;
        string userIn("");
        
        stringstream strToNum("");
        for (int i(0); i < ROWS; ++i)
        {
            // get input for line
            getline(fs, userIn);
            if (!userIn.empty() &&
                userIn.find_first_not_of(DIGITS)
                == std::string::npos)
            {
                strToNum << userIn;
                // assume user input values wont overflow INT_MAX value
                for (int j(0); j < COLS &&
                     strToNum >> convertedNum; ++j)
                {
                    a[i][j] = convertedNum;
                }
            }
            else
            {
                cout <<  ERROR_DETECTED << endl;
            }
            userIn = "";
            userIn.clear();
            strToNum.clear();
            strToNum.str(string());
        }
        for (int i(0); i < ROWS; i++)
        {
            for (int j(0);j < COLS; j++)
            {
                if (j < COLS - 1)
                    cout << a[i][j] << ", ";
                else
                    cout << a[i][j] << endl;
            }
        }
        fs.close();
    }
    else // test without file
    {
        int a[ROWS][COLS] = { 0 };
        int convertedNum = 0;
        string userIn("");
        
        stringstream strToNum("");
        for (int i(0); i < ROWS; ++i)
        {
            // get input for line
            cout << "Enter line with " << COLS << " numbers: \n";
            getline(cin, userIn);
            strToNum << userIn;
            // assume user input values that wont overflow int value
            for (int j(0); j < COLS && strToNum >> convertedNum; ++j)
            {
                a[i][j] = convertedNum;
            }
            userIn = "";
            userIn.clear();
            strToNum.clear();
            strToNum.str(string());
            cin.clear();
        }
        
        for (int i(0); i < ROWS; i++)
        {
            for (int j(0);j < COLS; j++)
            {
                if (j < COLS - 1)
                    cout << a[i][j] << ", ";
                else
                    cout << a[i][j] << endl;
            }
        }
    }
    cout << endl;
    return 0;
}
