#include <iostream> 
using namespace std;
int main()
{
  int total;
  //multiplication  has higher  precedence  than  subtraction
  total=100-25*2;
  cout << "The  total is: " <<  total <<  endl;

  //parentheses make  a lot of  difference!
  total=(100-25)*2;
  cout << "The  total is: " <<  total <<  endl;
  return 0;
}

