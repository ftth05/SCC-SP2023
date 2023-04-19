

// Name: Fettah Kiran
// UHID: 1678975
// HW5



/* 

5:Write a program to have the user input three (3) numbers: (f)rom,
(t)o, and (i)ncrement. Count from f to t in increments of i, inclusive of f and
t. For example, if the input is f == 2, t == 24, and i == 4, the program would
output: 2, 6, 10, 14, 18, 22.
*/

#include <iostream>

using namespace std;

int main() {
    // Input
    int f, t, i;
    cout << "Enter the (f)rom: ";
    cin >> f;
    cout << "Enter the (t): ";
    cin >> t;
    cout << "Enter the (i)ncrement: ";
    cin >> i;

    // Computation
    int x =0;
    for (int x=f;x<t; x=x+i) { std::cout<< x <<std::endl;}


    return 0;
}
