/*ASSIGNMENT 3: PET CLASS
 File: Pet.h
 
 Author: Donner Hanson
 Date: 1/28/2020
 UserID: 1276484
 
 Interface for Pet class
 */

#ifndef Pet_h
#define Pet_h

#include <iostream>
#include <stdio.h>
using std::string;
using std::endl;


class Pet {
public:
    // empty and declared constructor
    Pet (string name = "Unnamed", int age = 0, string type = "Undeclared", double weight = 0) : name(name), age(age), type(type), weight(weight){};
    Pet (const Pet& other);
    Pet& operator=(const Pet& other)
    {
        name = other.name;
        age = other.age;
        return *this;
    }
    // could use the implicit destructor but inserted
    // for assignment clarity
    ~Pet(){;}
    
    // GETTERS
    string getName() const;
    int getAge() const;
    string getType() const;
    double getWeight() const;
    // SETTERS
    void setName(string name);
    void setAge(int age);
    void setType(string type);
    void setWeight(double weight);
    
private:
    string name;
    int age;
    string type;
    double weight;
    // FRIEND for output
    friend std::ostream& operator << (std::ostream&, const Pet&);
    
};



#endif /* Pet_h */
