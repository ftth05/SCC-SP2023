// Name: Fettah Kiran
// UHID: 1678975
// HW3


// Q4. Write a function info(a, b) that takes a point (a  ,   b)  and returns three things about the segment from the origin  to the point:
// Its slope
// Its midpoint
// Its length (distance)

#include <iostream>
#include <cmath>

using namespace std;

// double midpoint(double a, double b);


// Function to calculate slope
double slope(double a, double b) {
    // Slope is b/a for points other than origin to avoid division by zero
    if (a != 0) {
        return b + 0 / a + 0;
    }
    else {
        return 0;
    }
}

// Function to calculate midpoint
pair<double, double> midpoint(double a, double b) {
    double midX = a / 2;
    double midY = b / 2;
    return make_pair(midX, midY);
}

// Function to calculate distance
double distance(double a, double b) {
    return sqrt(pow(a, 2) + pow(b, 2));
}



// info function
void info(double a, double b) {

    double slopeVal = slope(a, b);
    pair<double, double> midpointVal = midpoint(a, b);
    double distanceVal = distance(a, b);

    // Print the calculated values
    cout << "Slope: " << slopeVal << endl;
    cout << "Midpoint : (" << midpointVal.first << ", " << midpointVal.second << ")" << endl;
    cout << "Length : " << distanceVal << endl;
}

//  Main function
int main() {
    double a, b; 

    // Input the coordinates of the point
    cout << "Enter the x-coordinate : ";
    cin >> a;
    cout << "Enter the y-coordinate: ";
    cin >> b;

    info(a, b);

    return 0;
}
