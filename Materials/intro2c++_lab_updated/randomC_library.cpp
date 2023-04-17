#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
 
int main() 
{
    std::srand(time(nullptr)); // use current time as SEED for random generator
    auto random_variable = rand();
    cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
 
 
    cout << "generate 6 random ints\n";
    for(int i=0; i<6;i++) cout <<rand() << ' ';
        
    cout<<"\n\ngenerate 6 random floats\n";
 
    for(int i=0; i<6;i++) cout << float(rand())/(RAND_MAX) <<' ';  
    
    return 0;
}
