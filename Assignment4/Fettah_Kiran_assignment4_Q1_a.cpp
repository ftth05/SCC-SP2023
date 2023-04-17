

// Name: Fettah Kiran
// UHID: 1678975
// HW3



/* 1 a)

Write an algorithm to solve the following problem, use the principles described in Lecture 1 addendum, and Wayne Browns reading assignment. Make sure it is clear which principle you are  referring to by labeling statement blocks using headers ( Principle 1,  Principle 2, Principle 3)

Computational Problem

"A manager purchased a total of  C coffee mugs and key chains. Each Coffee mug cost A dollars and each key chain cost B dollars.  If the manager spent a total of M dollars. How many coffee mugs  did the manager purchase?"

b)

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

    // Computation
    int key_chains_cost = M - (A * C);
    int key_chains_purchased = key_chains_cost / B;
    int coffee_mugs_purchased = C - key_chains_purchased;

    // Output
    cout << "The number of coffee mugs purchased is: " << coffee_mugs_purchased << endl;

    return 0;
}
