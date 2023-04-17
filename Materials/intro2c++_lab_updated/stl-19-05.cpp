//Program to demonstrate the STL template class list.
#include <iostream>
#include <list>

using namespace std;

int main( )
{
    list<int> listObject;

    for (int i = 1; i <= 3; i++)
        listObject.push_back(i);

    cout << "List contains:\n";
    list<int>::iterator iter;
    for (iter = listObject.begin( ); iter != listObject.end( ); iter++)
        cout << *iter << " ";
    cout << endl;

    cout << "Setting all entries to 0:\n";
    for (iter = listObject.begin( ); iter != listObject.end( ); iter++)
        *iter = 0;

    cout << "List now contains:\n";
    for (iter = listObject.begin( ); iter != listObject.end( ); iter++)
        cout << *iter << " ";
    cout << endl;

    list<int> object2= {1,2,4,5};
    for (auto item : object2)
	    cout << 1+ item <<endl;


    cout << object2[2]<<endl;
    return 0;
}
