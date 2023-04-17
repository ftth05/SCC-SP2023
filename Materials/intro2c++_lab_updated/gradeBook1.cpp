#include <iostream>
using namespace std;

class GradeBook{
  void displayMessage(){
    cout << "Welcome to the Grade Book!" << endl;
  }
 public:
  void calldisplay(){ displayMessage();}
};

int main(){
  GradeBook myGradeBook;
  //myGradeBook.displayMessage();
  myGradeBook.calldisplay();
  return 0;
}

