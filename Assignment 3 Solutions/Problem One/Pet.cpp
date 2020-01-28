/*ASSIGNMENT 3: PET CLASS
 File: Pet.h
 
 Author: Donner Hanson
 Date: 1/28/2020
 UserID: 1276484
 
 Definitions for Pet class
 */

#include <iostream>
#include <string>
using std::endl;

#include "Pet.h"


// CONSTRUCTOR

Pet::Pet (const Pet& other) // copy constructor
{
    name = other.name;
    age = other.age;
    type = other.type;
    weight = other.weight;
}


// GETTERS
string Pet::getName() const {return name;}
int Pet::getAge() const {return age;}
string Pet::getType() const {return type;}
double Pet::getWeight() const {return weight;}
// SETTERS
void Pet::setName(string name)
{
    this->name = name;
}
void Pet::setAge(int age)
{
    this->age = age;
}
void Pet::setType(string type)
{
    this->type = type;
}
void Pet::setWeight(double weight)
{
    this->weight = weight;
}

std::ostream& operator << (std::ostream& os, const Pet& pet)
{
    os << "Name: " << pet.getName() << endl;
    os << "Age: " << pet.getAge() << endl;
    os << "Type: " << pet.getType() << endl;
    os << "Weight: " << pet.getWeight() << endl;
    return os;
}
