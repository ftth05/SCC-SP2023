// Name: Fettah Kiran
// UHID: 1678975
// HW8
// This program computes individual shares of a restaurant bill with STL Map data structure object


#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main() {
    // Declare a map to store the names and bills of friends
    map<string, double> record;

    // Read in the names and bills of friends
    for (int i = 1; i <= 5; i++) {
        string name;
        double bill;
        cout << "Enter name and bill of friend" << i << ": ";
        cin >> name >> bill;
        record[name] = bill;
    }

    // Read in the tip percentage
    double tip_percentage;
    cout <<endl<< "Enter tip percentage: ";
    cin >> tip_percentage;

    // Calculate the total bill and each person's share
    double total_bill = 0;
    for (const auto& [name, bill] : record) {
        total_bill += bill;
    }
    total_bill *= (1 + tip_percentage / 100);
    double share = total_bill / record.size();

    // Print the total bill and each person's share
    cout << fixed << setprecision(2);
    cout <<endl<< "Total bill plus tip: $ " << total_bill << endl;
    cout << endl<<"Friends Individual bills before tip         bills after including tip" << endl;

    for (const auto& [name, bill] : record) {
        cout << name << "              " << bill << "                                        " << share << endl;
    }

    return 0;
}
