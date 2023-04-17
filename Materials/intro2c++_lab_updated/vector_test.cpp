#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{

cout.precision(16);
cout.setf(ios::fixed,ios::floatfield);

vector<double> data={M_PI, 2/sqrt(M_PI), M_2_SQRTPI};

for (auto item : data)
cout << item  <<endl;
cout << "Size " << data.size()<<  endl<< data.data() << endl; 
return 0;
}
