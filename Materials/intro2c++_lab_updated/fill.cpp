#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
 
 
using namespace std;
int main()
{       

	
	vector<float> v(10);

	fill(v.begin(), v.end(), 11);

        for (auto x : v)         cout << x << endl;
      
}
