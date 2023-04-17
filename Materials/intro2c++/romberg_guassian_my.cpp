#include <iostream>
#include <cmath>

using namespace std;
double f(double x)
{
  //write gaussian function here

  return 2/sqrt(M_PI) * exp(-x*x);
  //return 2/M_2_SQRTPI * exp(-x*x); // M_2_SQRTPI is defined in math.h   

}

void romberg(double **r,  double a, double b, int n)
{

 int i,j,k;
 double sum, h;
 
 h=b-a;

 r[0][0]= h/2.0 * ( f(a) + f(b) );

 cout << r[0][0] <<endl;

cout.precision(16);
cout.setf(ios::fixed,ios::floatfield);

for (i=1; i<n;i++)
{
 h = h/2.0f;
 sum=0.0;
 for (k=1; k <= pow(2.0,i)   ;  k+=2)
 {

   sum = sum + f( a+ k*h);
 }

 r[i][0]= ( 0.5f * r[i-1][0]) + sum*h;
 cout << r[i][0]; 

 for (j=1; j <=i; j++)
 {
  r[i][j] =  r[i][j-1] + (r[i][j-1] - r[i-1][j-1])/(pow(4.0,j)-1);
  cout <<" "<<r[i][j] ;
  r[n-1][n-1]=  r[i][j] ;
 }
 cout << endl;
}
cout <<"Best estimate = "<< r[n-1][n-1] << endl;

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
 r=new double *[n];
 for (i=0;i<n; i++) r[i]=new double  [n];
 romberg(r,a,b,n);
 return 0;
}

