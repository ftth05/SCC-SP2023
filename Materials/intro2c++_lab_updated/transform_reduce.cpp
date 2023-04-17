#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
 
 
using namespace std;
int main()
{       

  random_device mydevice;
  uniform_real_distribution<> random_float(0,1);

  vector<float> v1(1000) , v2(1000), v3(1000);

  generate(v1.begin(), v1.end(), [&]() {       return random_float(mydevice) ; });
  generate(v2.begin(), v2.end(), [&]() {       return random_float(mydevice) ; });


  auto x = transform_reduce (v1.begin(), v1.end(), v2.begin(), 0.0f, plus<float>(),  [](float a, float b) { return  a*b;}  );

  cout << x/v1.size() << endl;

}
