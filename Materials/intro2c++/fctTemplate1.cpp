#include <iostream>
using namespace std;
template <class T>
void cdabs(T number) // compute and show the absolute value
{
	if (number < 0)
	   number = -number;
	cout << "The absolute value of the number is "
	<< number << endl;
}
int main()
{
	int num1 = -4;
	float num2 = -4.23f;
	double num3 = -4.23456;
	cdabs(num1);
	cdabs(num2);
	cdabs(num3);
	return 0;
}
