

// Name: Fettah Kiran
// UHID: 1678975
// HW3



// Q1:)  Write a program that calculates and prints the area and the perimeter of a square when the size of one side is given in C++


#include <iostream>

using namespace std;

int main() {
    double side;  // Variable to store the side of the square
    double area, perimeter;  // Variables to store the area and perimeter

    cout << "Enter the size of one side of the square: ";
    cin >> side;  // Input the side of the square

    // Calculate the area and perimeter
    area = side * side;
    perimeter = 4 * side;

    // Print the calculated area and perimeter
    cout << "Area of the square: " << area << endl;
    cout << "Perimeter of the square: " << perimeter << endl;

    return 0;
}


