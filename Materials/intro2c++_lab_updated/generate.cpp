#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
 
 
using namespace std;
int main()
{       

random_device mydevice;
uniform_real_distribution<> random_float(0,1);

	
	vector<float> v(10);

        generate(v.begin(), v.end(), [&]() {       return random_float(mydevice) ; });


        for (auto x : v)         cout << x << endl;
      
}
