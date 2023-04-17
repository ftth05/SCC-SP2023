#include <vector>
#include <iostream>
#include <random>
 
 
using namespace std;
int main()
{       
  string s1;	
  auto welcome = [](string name ) { cout << name + ", Welcome to world of CXX"<<endl;};

  cout << "Enter your name"<<endl;
  getline(cin,s1); 
 
     welcome(s1); 
}
