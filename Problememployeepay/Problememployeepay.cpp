//
//  main.cpp
//  Problememployeepay
//
//  Created by Donner Hanson on 1/14/20.
//
/*
 Problem 3 (employeepay):
 An employee is paid at a rate of $16.00 per hour for regular hours worked in a week. Any hours over that
 are paid at the overtime rate of one and one-half times that. From the worker’s gross pay, 6% is withheld
 for Social Security tax, 14% is withheld for federal income tax, 5% is withheld for state income tax, and
 $10 per week is withheld for medical insurance.
 
 Write a program that will read in the number of hours worked in a week as input and that will then output the worker’s gross pay, each withholding amount, and the net take-home pay for the week.
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
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
// limits
using std::numeric_limits;
// stdexcept
using std::invalid_argument;
using std::runtime_error;
// string
using std::string;

// CONST EXPRESSIONS
const int FLOAT_PRECISION = 2;
const double DEFAULT_DOUBLE = 0.00;

const double NORMAL_WRK_WK_HRS = 40.00;

const double REG_PAY = 16.00;
const double OT_PERCENT = 1.50;
const double SS_TAX_PERCENT = 0.06;
const double FI_TAX_PERCENT = 0.14;
const double SI_TAX_PERCENT = 0.05;
const double MED_WITHOLD_DOLLARS = 10.00;

//FUNCTIONS
double
getNormalPay(double workHours)
{
    return workHours * REG_PAY;
}

double
getOverTimePay(double overTimeAmount)
{
    return overTimeAmount * REG_PAY * OT_PERCENT;
}

double
calcSSWithhold(double grossPay)
{
    double deductableAmount(grossPay * SS_TAX_PERCENT);
    cout << "Social Security Tax Witheld: " << deductableAmount << "\n";
    return deductableAmount;
}

double
calcFIWithhold(double grossPay)
{
    double deductableAmount(grossPay * FI_TAX_PERCENT);
    cout << "Federal Income Tax Witheld: " << deductableAmount << "\n";
    return deductableAmount;
}

double
calcSIWithhold(double grossPay)
{
    double deductableAmount(grossPay * SI_TAX_PERCENT);
    cout << "State Income Tax Witheld: " << deductableAmount << "\n";
    return deductableAmount;
}

double
calcMedWithhold(double grossPay)
{
    double deductableAmount(MED_WITHOLD_DOLLARS);
    cout << "Medical Witheld: " << deductableAmount << "\n";
    return deductableAmount;
}

void
outputNetPay(double gross, double amountDeductible)
{
    cout << "Net take-home pay: " << gross - amountDeductible << "\n";
}

double
enactGovernment(double hardEarnedCash)
{
    double deductedAmount(0);
    // 6% is withheld for Social Security tax
    deductedAmount += calcSSWithhold(hardEarnedCash);
    // 14% is withheld for federal income tax
    deductedAmount += calcFIWithhold(hardEarnedCash);
    // 5% is withheld for state income tax
    deductedAmount += calcSIWithhold(hardEarnedCash);
    // $10 per week is withheld for medical insurance
    deductedAmount += calcMedWithhold(hardEarnedCash);
    return deductedAmount;
}

int main(int argc, const char * argv[]) {
    
    // set precision of floating point numbers
    cout << fixed << setprecision(FLOAT_PRECISION);
    
    
    double hoursWorked(0);
    
    string userInput;
    // 1) READ hours worked - Catch any errors from user
    // uses float comparison method
    while (fabs(hoursWorked) <=
           numeric_limits<double>::epsilon())
    {
        cout << "Enter the amount of hours worked in the weekly pay period: \n";
        cin >> userInput;
        try
        {
            // CONFIRM IS DOUBLE
            // If no conversion could be performed,
            // an invalid_argument exception is thrown.
            hoursWorked = stod(userInput);
            if (hoursWorked <=
                numeric_limits<double>::epsilon()) // if 0 or neg results in bad data
            {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                throw invalid_argument("");
            }
        }
        catch (const invalid_argument &e)
        {
            cout << "Input values should include only positive floating point numbers...\n";
            // Reset
            hoursWorked = DEFAULT_DOUBLE;
        }
        catch (...) // something terrible happened
        {
            cerr << "Uknown error occured.\n";
            exit(EXIT_FAILURE);
        }
    }
    
    double grossPay(0);
    
    // if 40 or less hours worked
    if (fabs(hoursWorked - NORMAL_WRK_WK_HRS) <= numeric_limits<double>::epsilon()  || hoursWorked < NORMAL_WRK_WK_HRS)
    {
        grossPay += getNormalPay(hoursWorked);
    }
    else if (hoursWorked > NORMAL_WRK_WK_HRS) // OT
    {
        grossPay += getNormalPay(NORMAL_WRK_WK_HRS);
        // Any hours over that are paid at the overtime rate of one and one-half times that.
        grossPay += getOverTimePay(hoursWorked - NORMAL_WRK_WK_HRS);
    }
    
    // if gross pay still == 0 throw an error
    try
    {
        if (fabs(grossPay) <= numeric_limits<double>::epsilon())
        {
            throw runtime_error("Hours incorrectly entered...\nexiting...\n");
        }
    }
    catch (runtime_error &e)
    {
        cerr << e.what();
        throw(EXIT_FAILURE);
    }
    cout << "Gross pay: " << grossPay << "\n";
    
    // deductableAmount is a positive floating point number
    double deductableAmount(enactGovernment(grossPay));
    
    outputNetPay(grossPay, deductableAmount);

    
    return 0;
}
