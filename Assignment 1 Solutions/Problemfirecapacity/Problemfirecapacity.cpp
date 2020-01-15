// Name: Donner Hanson
// Chapman ID: 1276484
// Assignement 1: Problem 2 Fire Capacity
// Description:
// Problem 2 (firecapacity): a program that determines whether a meeting room is
// in violation of fire law regulations regarding the maximum room capacity.
// The program will: 1) read in the maximum room capacity and the number of
// people to attend the meeting. If the number of people is less than or equal
// to the maximum room capacity, the program announces that it is legal to hold
// the meeting and tells how many additional people may legally attend.
// 2) If the number of people exceeds the maximum room capacity, the
// program announces: the meeting cannot be held as planned due to
// fire regulations and tells how many people must be excluded in order to meet
// the fire regulations.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

// USING DECLARATIONS
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    //only whole people allowed into the party
    int maxCapacity;
    int numAttending;
    cout << "Enter max capacity of room followed by the number of people"
            << " attending - followed by return:\n";
    cin >> maxCapacity >> numAttending;
    
    if (numAttending <= maxCapacity)
    {
        cout << "It is legal to hold the meeting\n";
        if (numAttending != maxCapacity && (maxCapacity - numAttending) > 1)
            cout << maxCapacity - numAttending
                    << " additional people may legally attend.\n";
        else
            cout << maxCapacity - numAttending
            << " additional person may legally attend.\n";
    }
    else
    {
        cout << "It is illegal to hold the meeting\n";
            cout << numAttending - maxCapacity
                    << " people must be excluded in order to meet"
                    << " the fire regulations.\n";
    }
    return 0;
}
