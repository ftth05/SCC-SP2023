// Name: Fettah Kiran
// UHID: 1678975
// HW3

//Q3. Write programs to address the following problems

// Suppose you want to find the slope between two points (a, f(a)) and (b, f(b)) where f(x) = x^2+ 2x - 7.

// Create a function f(x) = x^2+ 2x - 7.
// Create a function g(a, b) that will find the slope between two points x = a and x = b on f(x).
// Use g to find the slope between x = 3 and x = 5
// Use g to find the slope between x = -2 and x = 7


#include <iostream>
#include <cmath>

using namespace std;

// Function f(x) = x^2 + 2x - 7
double f1(double x) {
    return pow(x, 2) + 2 * x - 7;
    
}

// Function to find the slope between two points
double g(double a, double b) {
    double slope = (f1(b) - f1(a)) / (b - a);
    return slope;
}

int main() {
    double slope1, slope2; 

    // the slope1
    slope1 = g(3, 5);
    cout << "Slope between x = 3 and x = 5: " << slope1 << endl;

    // the slope2 
    slope2 = g(-2, 7);
    cout << "Slope between x = -2 and x = 7: " << slope2 << endl;

    return 0;
}
