#include  <iostream>
#include  <fstream>
using namespace std;
int main  ()
{
  ofstream  myfile, myfile2;
  myfile.open ("example.txt");
  myfile  <<  "Writing  this  to  a file.\n";
  myfile.close();
  myfile2.open ("example.txt",ios::app);
  myfile2  <<  "Appending  2nd line this  to same file.\n";
  myfile2.close();
  return  0;
}

