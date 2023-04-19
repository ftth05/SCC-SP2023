

// Name: Fettah Kiran
// UHID: 1678975
// HW5



/* 

6: Factorial. The factorial of a number is defined as the product of all values
from one to that number. A shorthand for N factorial is N! where N! ==
factorial (N) == 1 * 2 * 3 * … * (N-2) * (N-1) * N!. So 4! == 1 * 2 * 3 * 4.
Write a program such that given N, the value N! is returned.
*/

#include <iostream>

using namespace std;

int main() {
    // Input
    int N;
    cout << "Enter the N: ";
    cin >> N;

    // Computation
    int result =1;
    for (int x=1;x<=N; x++) { result = result*x;}
    std::cout<< "N! = " <<result <<std::endl;


    return 0;
}
