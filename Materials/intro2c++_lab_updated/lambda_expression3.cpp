#include <vector>
#include <iostream>
#include <random>
 
 
using namespace std;
int main()
{       
  string s1;
  string s2 = "Welcome to world of CXX";  
  auto welcome = [&](string name ) { cout << name + ", " +  s2 <<endl;};

  cout << "Enter your name"<<endl;
  getline(cin,s1); 
 
     welcome(s1); 
}
