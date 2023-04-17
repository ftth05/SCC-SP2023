//Program to demonstrate STL iterators.
#include <iostream>
#include <vector>
#include <iterator>
 
using namespace std;

int main( )
{
    vector<int> container;
   // vector<int>::iterator p;
    
    for (int i = 1; i <= 4; i++)
        container.push_back(i);

    cout << "Here is what is in the container:\n";
    
    for (auto p : container)
        cout << p << " ";
    cout << endl;

    cout << "Setting entries to 0:\n";
    for (auto &  p : container)
         p = 0;
    cout << "Container now contains:\n";
 
    for (auto p : container)
        cout << p << " ";
    cout << endl;

    vector<int> container2 = {1,2,3,4};
    auto p = container2.begin();
    cout << "First Entry\t"<<  *p <<endl;
    auto p2 = container2.rbegin();
    cout << "Last Entry\t"<<  *p2 <<endl;

    return 0;
}
