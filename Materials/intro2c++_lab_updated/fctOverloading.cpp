#include <iostream>
using namespace std;

//overloading volume
int volume (int);  //prototype declaration
double volume (double, double); //prototype declaration
double volume (double, double, double); //prototype decl.

int main(){
 cout << "cube vol: "<< volume(10) << endl;
 cout << "cylinder vol: " << volume(2.5, 8.5) << endl;
 cout << "cuboid vol: " << volume(100.5, 75.5, 15.5)<<"\n";
 return 0;
}

//volume of a cube
int volume(int s){
  return s*s*s;
}           

//volume of a cylinder
double volume(double r, double h){
  return (3.14519 * r * r * h);
}

//rectangular box or cuboid
double volume(double l, double b, double h){
  return (l*b*h);
}

