#include <iostream>
using namespace std;
void testauto(); // function prototype

int main()
{
	int count; // count is a local auto variable
	for(count = 1; count <= 3; count++)
		testauto();
	return 0;
}

void testauto()
{
	static int num = 0; // num is a local auto variable
	// initialized to 0
	cout << "The value of the automatic variable num is "
	<< num << endl;
	num++;
}
