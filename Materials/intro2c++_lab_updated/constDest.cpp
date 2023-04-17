#include <iostream>

using namespace std;

class Point{
 public:
	 double x,y;
	 Point (){
	 cout << "We just allocated/created for class point\n";}
	 ~Point (){ cout << "We just dellocated/destroyed for class point\n";}
};
void foo(Point & k)
{
  k.x = 11;
  k.y = 21;
}

int main(){
  Point p1, p2;
  cout << "Enter new values\n";

  p1.x = 10;
  p1.y = 20;
   
  cout << "Value of class variables x and y: "; 
  cout << p1.x << ", " << p1.y;
  cout << endl;
  foo (p2);

  return 0;
}

