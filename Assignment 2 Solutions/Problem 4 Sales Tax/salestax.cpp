/*
 ASSIGNMENT SALES TAX
 
 Author: Donner Hanson
 Date: 1/13/2020
 UserID: 1276484
 
 Assignment:
 Problem 4 (salestax.cpp): Implement a function called addTax.
 The function addTax has two formal parameters:
 taxRate, which is the amount of sales tax expressed as a percent;
 and cost, which is the cost of an item before tax.
 
 The function returns the value (float) of cost so that it includes sales tax.
 */
#include <iomanip>
#include <iostream>


// USING STATEMENTS FROM RESPECTIVE LIBRARIES
// iomanip
using std::fixed;
using std::setprecision;
//iostream
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

// CONST EXPRESSIONS
const float TAX_RATE(0.075);
const float COST(1000);
const int DECIMAL_PRECISION(2);

//FUNCTION DECLARTAIONS
float addTax(float &taxRate, float &cost);

// MAIN
int main(int argc, const char * argv[]) {
    float taxRate(TAX_RATE), cost(COST);
    cout << fixed << setprecision(DECIMAL_PRECISION)
            << addTax(taxRate, cost) << endl;
    return 0;
}

// FUNCTION DEFINITIONS
float addTax(float &taxRate, float &cost)
{
    return cost + cost * taxRate;
}
