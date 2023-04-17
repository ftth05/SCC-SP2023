#include <iostream>
using namespace std;

template <class T>
T maximum(T value1, T value2, T  value3){
  T maxValue = value1;
  if (value2 > maxValue){
    maxValue = value2;
  }
  if(value3 > maxValue){
    maxValue = value3;
  }
  return maxValue;
}

int main(){
  int val1, val2, val3;
  double val4, val5, val6;
  cout << "\nEnter three integer values\n";
  cin >> val1 >> val2 >> val3;
  cout << "Maximum integer value is: "<< maximum(val1,val2,val3);

  cout << "\nEnter three double values\n";
  cin >> val4 >> val5 >> val6;
  cout <<"Maximum double value is: "<< maximum(val4,val5,val6);
  return 0;
}

