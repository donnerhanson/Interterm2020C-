/*ASSIGNMENT 3: PET CLASS
 
 Author: Donner Hanson
 Date: 1/28/2020
 UserID: 1276484
 
 Assignment:
 Create a class called Pet with all the necessary files
 (.h , .cpp, etc.) This class should have member
 variables name (string), age (int), type ([‘dog’, ‘cat’]) (string)
 and weight (double).
 Make sure to include the appropriate accessor (getters), mutator
 (setters).
 Once the Pet class has been implemented, create two instances of
 Pet and print their details to console output.
 */

#include <iostream>

#include "Pet.h"

using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    // default constructor
    Pet petOne;
    
    // show that the setters work
    Pet petTwo;
    petTwo.setName("Named Pet");
    petTwo.setAge(3);
    petTwo.setType("dog");
    petTwo.setWeight(40);
    
    cout << petOne << endl << petTwo;
    return 0;
}
