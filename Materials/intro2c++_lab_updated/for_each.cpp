#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <cmath> 
 
using namespace std;
int main()
{       

  random_device mydevice;
  uniform_real_distribution<> random_float(0,1);

  vector<float> v(1000);

  generate(v.begin(), v.end(), [&]() {       return random_float(mydevice) ; });
  
 for_each (v.begin(), v.end(),   [&] (float & x) {  x = tan(x) + log(x); });


  for (int  i =0; i <6; i++) cout << v[i] << endl; 
}
