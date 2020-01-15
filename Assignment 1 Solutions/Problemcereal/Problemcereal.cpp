// Name: Donner Hanson
// Chapman ID: 1276484
// Assignement 1: Problem 1 CEREAL
// Description:
// Problem 1 (CEREAL): a program that will: Read the weight (console input)
// of a package of breakfast cereal in ounces, output the weight in metric tons
// and output the number of boxes needed to yield one metric ton of cereal.
////////////////////////////////////////////////////////////////////////////////

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
// string
using std::string;

// CONST EXPRESSIONS
const int FLOAT_PRECISION = 10;
const double MTON_IN_OUNCES = 35273.92;
const double DEFAULT_VAL = -1.0;


class CerealBoxUnitConverter
{
public:
    CerealBoxUnitConverter() : weightOunces(DEFAULT_VAL),
                                packageWeightInMT(DEFAULT_VAL),
                                numOfOneMetricTonOfBoxes(DEFAULT_VAL){}
    
    void updateValues()
    {
        setWeightOunces();
        
        setPackageWeightInMetricTons();
        // Set and Output Number of boxes needed to equal one metric ton of
        // cereal
        setNumberOfOrigBoxesToMetricTon();
    }
   
    double
    getWeightOunces() const
    {
        return weightOunces;
    }
    
    double
    getPackageWeightInMetricTons()
    {
        return packageWeightInMT;
    }
    

    double
    getNumOfOneMetricTonOfBoxes()
    {
        return numOfOneMetricTonOfBoxes;
    }
    
    // OUTPUT FUNCTIONS
    void
    singlePackageWeightMetricTonsOut()
    {
        cout << "Box weight converted to metric tons: \n"
        << getPackageWeightInMetricTons() << "\n";
    }
    
    void
    outputNumPackagesForMetricTon()
    {
        cout << "Boxes needed for one Metric Ton of cereal:\n" <<
        getNumOfOneMetricTonOfBoxes() << "\n";
    }
    
private:
    // Member Functions
    void
    setWeightOunces()
    {
        string userInput;
        // 1) READ WEIGHT IN OUNCES - Catch any errors from user
        // uses float comparison method
        while (fabs(weightOunces - DEFAULT_VAL) <=
               numeric_limits<double>::epsilon())
        {
            std::cout << "Input weight amount of each box in ounces:\n";
            std::cin >> userInput;
            try
            {
                // CONFIRM IS DOUBLE
                // If no conversion could be performed,
                // an invalid_argument exception is thrown.
                weightOunces = stod(userInput);
                if (weightOunces <= 0.0) // if 0 or neg results in bad data
                {
                    cin.clear();
                    cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                    throw invalid_argument("");
                }
            }
            catch (const invalid_argument &e)
            {
                cout << "Input values should include only positive numbers...\n";
                // Reset
                weightOunces = DEFAULT_VAL;
            }
            catch (...) // something terrible happened
            {
                cerr << "Uknown error occured.\n";
                exit(EXIT_FAILURE);
            }
        }
        
    }
    
    void
    setPackageWeightInMetricTons()
    {
        // Convert to Metric tons
        packageWeightInMT = weightOunces * 1.0f/MTON_IN_OUNCES;
    }
    
    void
    setNumberOfOrigBoxesToMetricTon()
    {
        numOfOneMetricTonOfBoxes = 1.0 / packageWeightInMT;
    }
    
    // Member Variables
    double weightOunces;
    double packageWeightInMT;
    double numOfOneMetricTonOfBoxes;
};


int main(int argc, const char * argv[]) {
    // set precision of floating point numbers
    cout << fixed << setprecision(FLOAT_PRECISION);

    CerealBoxUnitConverter batchOne;
    batchOne.updateValues();
    batchOne.singlePackageWeightMetricTonsOut();
    batchOne.outputNumPackagesForMetricTon();
    
    return 0;
}
