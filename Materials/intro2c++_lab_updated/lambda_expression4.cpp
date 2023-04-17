#include <vector>
#include <iostream>
#include <random>
 
 
using namespace std;
int main()
{       

random_device mydevice;
uniform_real_distribution<> random_float(0,1);

  auto generate_float= [&]() {       return random_float(mydevice) ; };
	
	vector<float> v(10);

	for (auto & item: v)   item = generate_float(); 

        for (auto x : v)         cout << x << endl;
      
}
