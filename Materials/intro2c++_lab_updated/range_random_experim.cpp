#include <iostream>
#include <experimental/random>
using namespace std;
using std::experimental::fundamentals_v2::randint; 
int main() 
{
    
    cout<< "generate intergers within a range, from the uniform standard distribution\n";
    for(int i=0; i<6;i++) cout << randint(1,100) <<' '; 
    cout<<endl;     
    return 0;
}
