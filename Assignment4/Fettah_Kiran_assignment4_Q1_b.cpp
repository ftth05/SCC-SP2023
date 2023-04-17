

// Name: Fettah Kiran
// UHID: 1678975
// HW3



/* 1 b)

Write a C++ code that would solve the problem, when given appropriate inputs. i.e. Principle 4
*/

#include <iostream>

using namespace std;

int main() {
    // Input
    int M, A, B, C;
    cout << "Enter the total cost of coffee mugs and key chains (M): ";
    cin >> M;
    cout << "Enter the cost of one coffee mug (A): ";
    cin >> A;
    cout << "Enter the cost of one key chain (B): ";
    cin >> B;
    cout << "Enter the total number of coffee mugs and key chains purchased (C): ";
    cin >> C;

    // Error Handling
    if (A <= 0 || B <= 0 || C <= 0) {
        cout << "Invalid input! Cost and quantity must be positive integers." << endl;
        return 1; // Return error code 1
    }

    // Computation
    int key_chains_cost = M - (A * C);
    int key_chains_purchased = key_chains_cost / B;
    int coffee_mugs_purchased = C - key_chains_purchased;

    // Output
    cout << "The number of coffee mugs purchased is: " << coffee_mugs_purchased << endl;

    return 0;
}

