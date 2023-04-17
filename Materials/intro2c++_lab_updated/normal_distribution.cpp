#include <iostream>
#include <random>
 
 
using namespace std;
int main()
{
    random_device  mydevice;
    normal_distribution<> d{5, 2}; //mean=5; stddev =2; 
    for (int n = 0; n != 10; ++n) cout << d(mydevice) <<" ";
    cout << endl;
      
}
