#include <cmath>
#include <iostream>

class integral {    // members by default are private
  double lower;     // lower integral bound, a private data member 
  double upper;     // upper integral bound, private 

  //  double (*integrand)(double);
  typedef double (*pfn)(double);  // define pfn to be type of a function pointer
  pfn integrand;    // integrand takes a double and returns a double

  mutable double value;                   // store value from trapezoidal rule
  mutable bool value_valid;               // value valid or not
public:             // public members
  //  integral(double a, double b, double(*f)(double)){      // a constructor 
  integral(double a, double b, pfn f){      // a constructor 
    lower = a;
    upper = b; 
    integrand = f;
    value_valid = false;
  }
  double lowbd() const { return lower; }    // a const function member
  double upbd() const { return upper; }     // a const function member
  void changebd(double, double);            // a nonconst function member 
  double trapezoidal(int = 100) const;      // a const function member
  friend double simpson(integral, int );     // a friend
};

inline void integral::changebd(double a, double b) { // definition of a fn
  lower = a;                                    // declared to be inline
  upper = b;
  value_valid = false;
}

double simpson(integral ig, int n) {            // a friend 
  double h = (ig.upper - ig.lower)/n;           // size of each subinterval
  double sum = ig.integrand(ig.lower)*0.5;
  for (int i = 1; i < n; i++) sum += ig.integrand(ig.lower + i*h);
  sum += ig.integrand(ig.upper)*0.5;

  double sum2 = 0.0; 
  for (int i = 1; i <= n; i++) sum2 += ig.integrand(ig.lower + (i-0.5)*h);

  return (sum + 2*sum2)*h/3.0;
}

double xlog(double x) { return x*x*std::log(x); }

double f(double x)
{
  return 4.0f/(1 + x*x);
}

int main(){
  integral di(0.0, 1.0, f);          // initialization
  int intervals=100;
  std::cout.precision(16);
  std::cout.setf(std::ios::fixed,std::ios::floatfield);

  std::cout <<"Enter number of Intervals\n";
  std::cin >> intervals;
  double result = di.trapezoidal(intervals);  // calling a fn member
  std::cout << "For Trapezoidal Rule:\nThe integral from " << di.lowbd() << " to " 
            << di.upbd() << " is approximately = " << result << "\n";

  integral dj(0.0, 1.0, f);
  result =  simpson(dj,intervals);  
  std::cout << "\n\nFor Simpsons Rule:\nThe integral from " << dj.lowbd() << " to " 
            << dj.upbd() << " is approximately = " << result << "\n";

}


double integral::trapezoidal(int n) const {       // a const member 
  if (value_valid == false || n !=  100) {
    double h = (upper - lower)/n;                 
    double sum = integrand(lower)*0.5;
    for (int i = 1; i < n; i++) sum += integrand(lower + i*h);
    sum += integrand(upper)*0.5;

    value = sum*h;                                // updating mutable member
    value_valid = true;                           // updating mutable member

    std::cout << "did the calculation\n";
  }
  return value;
}

