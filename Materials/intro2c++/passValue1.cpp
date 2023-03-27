#include  <iostream>
using namespace std; 
void add( int  x, int y);
int main()
{
  int a,  b;
  cout  <<  "\n Enter Any 2 Numbers : ";
  cin >>  a >>  b;

  add ( a, b );
  return  0;
}
void add(int a, int b)
{
   int  c;
   c= a + b;
   cout  <<  "\n Addition  is  : " <<  c <<endl;
}

