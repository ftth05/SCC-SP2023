#include  <iostream>
#include <memory>
#include  <cstdlib>
using namespace std; 
int  main()
{
   int numStudents, i;
   cout  <<  "Enter  the num of  students  : ";
   cin >>  numStudents;

   unique_ptr<int[]> ptr(new int [numStudents]);
   
   if(ptr==  NULL)
   {
     cout  <<  "\n\nMemory allocation  failed!";
     exit(1);
   }
  for (i=0; i<numStudents;  i++)
  {
     cout  <<  "\nEnter  the marks of  student_" <<  i +1  <<  " ";
     cin >> ptr[i];
  }
  for (i=0; i<numStudents;  i++)
  {
      cout  <<"student_"<<  i+1 <<" has "<< ptr[i];
      cout  <<  " marks\n";
  } 
  return  0;
}

