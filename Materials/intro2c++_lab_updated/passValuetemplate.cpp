#include  <iostream>
using namespace std; 

template <typename T>
void add(T a, T b)
{
   T  c;
   c= a + b;
   cout  <<  "\n Addition  is  : " <<  c <<endl;
}


int main()
{
  int a,  b;
  cout  <<  "\n Enter Any 2 Int Numbers : ";
  cin >>  a >>  b;

  add ( a, b );

  double c,  d;
  cout  <<  "\n Enter Any 2 Decimal Numbers : ";
  cin >>  c >>  d;
  add (c,d);

  return  0;
}
