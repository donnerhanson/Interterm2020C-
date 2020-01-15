// Name: Donner Hanson
// Chapman ID: 1276484
// Assignement 1: Problem 4 (Inflation)
// Description:
// Problem 4 (inflation): Write a program to gauge the expected cost of an item
// in a specified number of years. User inputs cost as a double, years as an
// unsigned int, and the inflation rate as a double - formatted as a percentage
// value -- i.e. 5.6 is 5.6 percent and transformed to a double .056 later for
// calculations
////////////////////////////////////////////////////////////////////////////////

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


// CONST EXPRESSIONS
const int DEFAULT_DOUBLE = 0.00;
const int FLOAT_PRECISION = 2; // user only needs to see cents value of price

//FUNCTIONS
double
calcPriceAfterInflation(double price,
                        double inflationRate, unsigned int years)
{
    // initially inflationRate given as "5.6" --> ".056"
    inflationRate /= 100.00;
    for (unsigned int i(0); i < years; i++)
    {
        // inflation affects every year (compounds)
        price += (price * inflationRate);
    }
    // local price returned as value - param not affected
    return price;
}


int main(int argc, const char * argv[]) {
    double currCost(DEFAULT_DOUBLE), inflationRate(DEFAULT_DOUBLE);
    unsigned int numYears(0);
    
    cout << fixed << setprecision(FLOAT_PRECISION);
    
    cout << "Enter the cost of the item: ";
    cin >> currCost;
    cout << "Enter the number of years from now the item will be purchased"
    " (positive integer value): ";
    cin >> numYears;
    cout << "enter the rate of inflation (as a percentage value - e.g. 5.6): ";
    cin >> inflationRate;
    // Calculates and store future price
    double futurePrice(calcPriceAfterInflation(currCost,
                                               inflationRate, numYears));
    cout << "Initial Price: $" << currCost << "\n"
    << "Inflated price after " << numYears << " years at an inflation rate of "
    << inflationRate << " percent: $" << futurePrice << "\n";
    return 0;
}
