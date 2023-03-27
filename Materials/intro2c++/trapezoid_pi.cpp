#include <iostream>
#include <cmath>

using namespace std;
double f(double x)
{
  return 4.0f/(1 + x*x);
}

void trapezoid(  double a, double b, int n)
{

 int i,j,k;
 double sum, h, x;
 
 h=b-a;
 h=h/(float)n;
 sum =  ( f(a) + f(b) );


cout.precision(16);
cout.setf(ios::fixed,ios::floatfield);

for (i=1; i<n;i++)
{
   x = a + i*h;
   sum = sum + f(x);
 }
 sum =sum * h;
 cout <<"Best estimate = "<< sum << endl;

}

int main (int argc , char **argv)
{
 cout << "Enter the Number of Intervals N: ";
 int N=5, n=5;
 cin >>  N ;
 cout << "\n\n";
 if ( N<=0) n=5;
 else n=N;
 int i;
 double a, b,  sum, **r;
 b=1.0;
 a=0.0;
 trapezoid(a,b,n);
 return 0;
}

