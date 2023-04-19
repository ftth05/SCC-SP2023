

// Name: Fettah Kiran
// UHID: 1678975
// HW7



/* 

Congrats, your team just got a 7.6% pay increase. Write a C++ program that creates a pay object from the pay class.
Your class should do the following
1. Contain the following private data members:
 old_pay, pay_rate_increase and future_pay

2. pay class  must have a default constructor and destructor functions

3. pay class must include an overloaded constructor that takes  old_pay and pay increase as arguments, and sets private data members, old_pay, pay_rate_increase,  and future_pay.
  
4. Class should include accessor and mutator functions, to set  up or retrieve  old_pay, pay_rate_increase, and future pay 
5. Class should include  function/method to compute future pay and update pay_object
your code should take in your old pay and increase as input and prints out your new pay, taking into account your pay increase.  
6. Add a main function that uses an instance of the class, and shows all the constructor and member methods work correctly.
*/

#include <iostream>
using namespace std;

class Pay {
private:
    double old_pay;             // old pay
    double pay_rate_increase;   // pay rate increase as a percentage
    double future_pay;          // future pay after increase

public:
    // Default constructor
    Pay() : old_pay(0), pay_rate_increase(0), future_pay(0) {}

    // Overloaded constructor
    Pay(double old_pay, double pay_rate_increase) : old_pay(old_pay), pay_rate_increase(pay_rate_increase), future_pay(0) {}

    // Destructor
    ~Pay() {}

    // Accessor functions
    double getOldPay() const {
        return old_pay;
    }

    double getPayRateIncrease() const {
        return pay_rate_increase;
    }

    double getFuturePay() const {
        return future_pay;
    }

    // Mutator functions
    void setOldPay(double old_pay) {
        this->old_pay = old_pay;
    }

    void setPayRateIncrease(double pay_rate_increase) {
        this->pay_rate_increase = pay_rate_increase;
    }

    void setFuturePay(double future_pay) {
        this->future_pay = future_pay;
    }

    // Function to compute future pay and update pay object
    void computeFuturePay() {
        double increase_amount = old_pay * (pay_rate_increase / 100.0);
        future_pay = old_pay + increase_amount;
    }
};

int main() {
    // Create an instance of the Pay class
    Pay payObject;

    // Set old pay and pay rate increase
    double oldPay = 5000.0;
    double payRateIncrease = 7.6;

    payObject.setOldPay(oldPay);
    payObject.setPayRateIncrease(payRateIncrease);

    // Compute future pay
    payObject.computeFuturePay();

    // Get the updated pay information
    double futurePay = payObject.getFuturePay();

    // Print the results
    cout << "Old Pay: $" << oldPay << endl;
    cout << "Congrats, your team just got a: " << payRateIncrease << "%" << " pay increase."<<endl;
    cout << "Future Pay: $" << futurePay << endl;

    return 0;
}
