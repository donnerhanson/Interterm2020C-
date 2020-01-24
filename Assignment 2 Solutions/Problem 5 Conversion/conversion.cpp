/*
 ASSIGNMENT CONVERSION
 
 Author: Donner Hanson
 Date: 1/23/2020
 UserID: 1276484
 
 Assignment:
 Problem 5 (conversion.cpp):
 Write a program that will read in a length in feet and inches
 and output the equivalent length in meters and centimeters.
 Use at least three functions:
 one for user input,
 one or more for calculating,
 and one for output(console).
 
 Include a loop that lets the user repeat this computation for new
 input values until the user says he or she wants to end the program
 (user has to type exit).
 
 There are 0.3048 meters in a foot,
 100 centimeters in a meter,
 and 12 inches in a foot.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>


// USING STATEMENTS FROM RESPECTIVE LIBRARIES
// cmath
using std::fabs;
using std::fmod;
// iomanip
using std::fixed;
using std::setprecision;
//iostream
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
// limits
using std::numeric_limits;
// stdexcept
using std::invalid_argument;
// string
using std::string;
// sstream
using std::stringstream;

// CONST EXPRESSIONS
const double METERS_IN_FT(0.3048);
const double CENTIMETERS_IN_METER(100.0000);
const double INCH_IN_FT(12.0000);
const string DIGITS = "0123456789 ";
const string MSG = "Enter a length in feet and inches"
" (numbers separated by space) or exit to quit:";
const string EXIT = "exit";
const int PRECISION(2);

//FUNCTIONS
void getUserInput(string &);
double calculate (string);
void output (double totalMeters);


// MAIN
int main(int argc, const char * argv[]) {
    
    string userIn("");
    double totalMeters(0.0);
    while (userIn != EXIT)
    {
        getUserInput(userIn);
        if (userIn != EXIT)
        {
            totalMeters = calculate(userIn);
            output(totalMeters);
        }
    }
    return 0;
}

// FUNCTION DEFS
void getUserInput(string &userIn)
{
    bool isDone(false);
    while (!isDone)
    {
        userIn = ""; // reset user in for each iteration
        cout << MSG << endl;
        getline(cin, userIn);
        // scan user input for correctness or quit otherwise continue
        if (!userIn.empty() &&
            userIn.find_first_not_of(DIGITS) == std::string::npos)
        {
            isDone = true;
        }
        else if (!userIn.empty() && userIn == EXIT)
        {
            isDone = true;
        }
    }
}
double calculate (string userIn)
{
    double feet(0), inch(0), meters(0);
    // get index of the space
    int idx = (int)userIn.find(' ');
    // create a substring of the ft
    string ftStr = userIn.substr(0, idx);
    // erase the ft in the string with inches remainder
    string inStr = userIn.erase(0, idx);
    
    // parse first and insert to feet
    stringstream is(ftStr);
    is >> feet;
    // clear stream of data and reset
    is.str(string());
    is.clear();
    // parse second and put into inch
    is.str(inStr);
    is >> inch;
    // clear stream of data and reset
    is.str(string());
    is.clear();

    // add inches to feet (feet becomes decimal)
    feet += (inch / INCH_IN_FT);
    // feet to Meters
    meters = feet * METERS_IN_FT;
    return meters;
}

void output(double totalMeters)
{
    double cent(0);
    // temp int cast - removes decimal
    int wholeMeters = (int)totalMeters;
    cent = (totalMeters - wholeMeters);
    // Centimeters as whole number
    cent *= CENTIMETERS_IN_METER;
    
    cout << "meters: " << wholeMeters;
    // set centimeter precision
    cout << fixed << setprecision(PRECISION)
            << ", centimeters: " << cent << endl;
    cout.unsetf(std::ios_base::floatfield); // reset precision
}
