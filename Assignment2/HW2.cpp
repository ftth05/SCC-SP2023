
// Name: Fettah Kiran
// UHID: 1678975
// HW2


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Declare variables for names and bills
    string name1, name2, name3, name4, name5;
    double bill1, bill2, bill3, bill4, bill5;
    
    // Ask for friend names and store them in variables
    cout << "Enter the name of friend: ";
    getline(cin, name1);
    cout << "Enter the name of friend: ";
    getline(cin, name2);
    cout << "Enter the name of friend: ";
    getline(cin, name3);
    cout << "Enter the name of friend: ";
    getline(cin, name4);
    cout << "Enter the name of friend: ";
    getline(cin, name5);
    
    // Ask for the bills of each friend: and store them in variables
    cout << "Enter the bill for " << name1 << " : ";
    cin >> bill1;
    cout << "Enter the bill for " << name2 << " : ";
    cin >> bill2;
    cout << "Enter the bill for " << name3 << " : ";
    cin >> bill3;
    cout << "Enter the bill for " << name4 << " : ";
    cin >> bill4;
    cout << "Enter the bill for " << name5 << " : ";
    cin >> bill5;
    
    // Print out the names  of friends
    cout << endl << "Names of Friends:" ;
    cout << name1  << ", "<< name2 << ", "<<name3  << ", "<< name4 << ", " << name5;

    

    // Print out the bills 
    cout << endl << "Individual bills: " ;
    cout << setprecision(2) << bill1 <<", "<< setprecision(2) << bill2 <<", "<<setprecision(2) << bill3 <<", "<<setprecision(2) << bill4 <<", "<<setprecision(2) << bill5 << endl;


    // Ask for the tip percentage and compute the total bill and individual shares
    double tipPercent;
    cout << endl << "Enter the tip percentage: ";
    cin >> tipPercent;
    
    double totalBill = bill1 + bill2 + bill3 + bill4 + bill5;
    double tipAmount = totalBill * (tipPercent / 100);
    double grandTotal = totalBill + tipAmount;
    double share = grandTotal / 5;
    
    // Print out the total bill and individual shares
    cout << endl << "Total bill plus tip: $ " << fixed << setprecision(2) << grandTotal << endl;
    cout << endl << "Each of us must pay: $ " << fixed << setprecision(2) << share << endl << endl;
    
    return 0;
}


