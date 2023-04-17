#include  <iostream>
#include  <fstream>
#include  <string> 
using namespace std; 
int main (int argc, char** argv)
{
  string  line;
  int counter =0;
  if (argc < 2)
 {
  cout<< "Needs two or more arguements"<<endl;
 exit(1);
 }
  ifstream myfile (argv[1]);
  if (myfile.is_open())
  {
     while ( myfile.good() )
     {
        getline (myfile,line); 
        //cout << line << endl;
        if(!myfile.eof())counter++;
     }
     myfile.close();
   } 
   else
   cout  <<  "Unable to  open  file";

   cout << "Found "<<counter <<" lines"<<endl;
   return  0;
}

