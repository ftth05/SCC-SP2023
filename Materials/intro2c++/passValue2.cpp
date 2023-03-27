#include  <iostream>
#include <cstdlib>
using namespace std; 
int add( int a, int b);

int main( int argc, char ** argv)
{
    int a,  b, c;
    if  (argc != 3) {
    cout  <<  "\nInsufficient num.  of  arguments.\n";
    cout  <<  "\nUsage:"  <<  argv[0] <<  " <firstNum>  <secondNum> \n";
} 
else{
       a = atoi(argv[1]);
       b = atoi(argv[2]); 
       c  = add(a, b); 
       cout  <<  "\n Addition of a and b is  : " <<  c<<endl;
      }
  return  0;
}
int add(int a, int b) 
{
    return (a + b);
}

