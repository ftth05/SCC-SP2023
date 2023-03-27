#include  <iostream> 
using namespace std;
int main()
{
  float temperature1;
  float temperature2;
  float average;

  cout  <<  "Enter the first temperature reading in Fahrenheit:  ";
  cin >>  temperature1;

  cout  <<  "Enter the second temperature reading in Fahrenheit:  ";
  cin >>  temperature2;

  average = (temperature1 + temperature2)/2.0f;

  cout  <<  "The average temperature is: " <<  average <<" F"<<  endl;

  cout  <<  "The average temperature in Kelvin is: " <<  (5/9.0 * (average -32)) + 273 <<" K"<<  endl;
  
  return  0;
}
