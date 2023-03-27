#include  <iostream> 
using namespace  std; 
int main()
{
  int i;
  int age[4]; 
  age[0]=23; 
  age[1]=34; 
  age[2]=65; 
  age[3]=74;
  for(i=0; i<4; i++)
  {
    cout  <<"Element: "<< i <<" Value of  age:  "<< age[i] <<"\n";
  }
  return 0;
}

