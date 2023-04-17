#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
 
 
using namespace std;
int main()
{       

  random_device mydevice;
  uniform_real_distribution<> random_float(0,1);

  vector<float> v(1000);

  generate(v.begin(), v.end(), [&]() {       return random_float(mydevice) ; });
  
  auto x = reduce (v.begin(), v.end(), 0.0f, plus<float>() );

  cout << x/v.size() << endl;
      
}
