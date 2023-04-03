
// Name: Fettah Kiran
// UHID: 1678975

/*
Write a program that calculates the sales tax of a transaction 
given the sale amount. 

*/

#include  <iostream>
using namespace std; 
void saleTax(double sAmount);

int main()
{

    double sAmount =1;
    cout<< "\n --> To exit, enter 0 <-- \n" << "\n";
   
    while (sAmount !=0)
    {
      cout<< "Enter the sale amount: ";
      cin >> sAmount;
      saleTax(sAmount); 
    }

    return  0;
}

void saleTax(double sAmount)
{

    const double tax = 0.09;
    double tAmount = sAmount * tax;
    double total= sAmount + tAmount;

    cout  <<  "Sale amount: "<< sAmount<<"\n";
    cout  <<  "Tax amount: "<< tAmount<<"\n";
    cout  <<  "Total amount due: "<< total<<"\n" << "\n";
}


