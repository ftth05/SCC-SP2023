//Program to demonstrate bidirectional and random access iterators.
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main( )
{
    vector<char> container;
    container.push_back('A');
    container.push_back('B');
    container.push_back('C');
    container.push_back('D');   

    for (int i = 0; i < 4; i++)
        cout << "container[" << i << "] == " 
             << container[i] << endl;

    vector<char>::iterator p = container.begin( );
    cout << "The third entry is " << container[2] << endl;
    cout << "The third entry is " << p[2] << endl;
    cout << "The third entry is " << *(p + 2) << endl;
    vector<char>::reverse_iterator rp = container.rbegin( );

    cout << "The last entry is " << *rp << endl;

    return 0;
}
