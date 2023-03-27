#include <iostream>
#include <cmath>
using namespace std;
//const double PI = 2.0 * asin(1.0);
// class declaration section
class Circle
{
protected:
double radius;
public:
Circle(double = 1.0); // constructor
double calcval(), PI;
};
// class implementation section for Circle
Circle::Circle(double r) // constructor
{
radius = r;
 PI = 2.0 * asin(1.0);
}
// calculate the area of a circle
double Circle::calcval()
{
return(PI * radius * radius);
}
// class declaration section where Cylinder is derived from Circle
class Cylinder : public Circle
{
protected:
double length; // add one additional data member and
public: // two additional member functions
Cylinder(double r = 1.0, double l = 1.0) : Circle(r), length(l) {}
double calcval();
};
// class implementation section for Cylinder
double Cylinder::calcval() // this calculates a volume
{
return (length * Circle::calcval()); // note the base function call
}

int main()
{
	Circle circle_1, circle_2(2); // create two Circle objects
	Cylinder cylinder_1(3,4); // create one Cylinder object
	cout << "The area of circle_1 is " << circle_1.calcval() << endl;
	cout << "The area of circle_2 is " << circle_2.calcval() << endl;
	cout << "The volume of cylinder_1 is " << cylinder_1.calcval() << endl;
	circle_1 = cylinder_1; // assign a Cylinder to a Circle
	cout << "\nThe area of circle_1 is now " << circle_1.calcval() << endl;
	return 0;
}
