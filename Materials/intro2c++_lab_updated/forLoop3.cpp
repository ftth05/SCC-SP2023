#include  <iostream> 
using namespace std; 
int main()
{
  int myarray[]={1,2,3};

  for (auto k : myarray) k*=2;

  for ( auto i : myarray)
  {  
     cout <<i << " What a wonderful class!"<<endl;
  }
  return  0;
}
