// Name: Fettah Kiran
// UHID: 1678975
// HW3



// Q2:) Write a program that, using a C++ string, prints your name in the format shown below after being prompted to input your first and the last name. Note that the last name should come before the first name as shown.
// Your full name is: last, first

#include <iostream>
#include <string>

using namespace std;

int main() {
    string firstName, lastName;  

    cout << "Enter your first name: ";
    cin >> firstName;  

    cout << "Enter your last name: ";
    cin >> lastName;  

    // Print the full name 
    cout << "Your full name is: " << lastName << ", " << firstName << endl;

    return 0;
}
