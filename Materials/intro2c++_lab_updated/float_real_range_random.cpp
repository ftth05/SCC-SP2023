#include <iostream>
#include <random>

using namespace std;
 
int main()
{
    random_device mydevice;  // Will be used to obtain a seed for the random number engine
    uniform_real_distribution<> random_float(0,1);
 
    for (int n = 0;  n != 6; ++n) cout << random_float(mydevice) << ' ';
    cout << '\n';
}
