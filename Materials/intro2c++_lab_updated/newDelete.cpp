#include  <iostream>
#include  <cstdlib>
 using namespace std; 
int  main()
{
   int numStudents,  *ptr, i;
   cout  <<  "Enter  the num of  students  : ";
   cin >>  numStudents;
   ptr= new int [numStudents];
   if(ptr==  NULL)
   {
     cout  <<  "\n\nMemory allocation  failed!";
     exit(1);
   }
  for (i=0; i<numStudents;  i++)
  {
     cout  <<  "\nEnter  the marks of  student_" <<  i +1  <<  " ";
     cin >>  *(ptr+i);
  }
  for (i=0; i<numStudents;  i++)
  {
      cout  <<"student_"<<  i+1 <<" has "<< *(ptr + i);
      cout  <<  " marks\n";
  } 
  delete [ ] ptr;
  return  0;
}

