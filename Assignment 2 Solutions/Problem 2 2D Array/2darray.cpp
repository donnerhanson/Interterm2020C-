/*ASSIGNMENT 2DARRAY
 
 Author: Donner Hanson
 Date: 1/13/2020
 UserID: 1276484
 
 Assignment:
 Problem 2 (2darray.cpp):
 Write code that will fill the array a (declared below) with numbers typed in at
 the key- board. The numbers will be input five per line, on four lines (although your solution need not depend on how the input numbers are divided into lines).
 
 int a[4][5];
 */

#include <fstream>
#include <iostream>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
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
// stdexcept
using std::invalid_argument;
// string
using std::string;


// CONST EXPRESSIONS
const int ROWS = 4;
const int COLS = 5;

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
            //cout << userIn << endl;
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
