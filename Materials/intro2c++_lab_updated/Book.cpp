#include <iostream>
#include <string>
using namespace std;
class Book
{
public:
  virtual string getDescription() { return "Book"; }
 Book(){issbn="12345";};
 private:
  string issbn;
public:
string get_issbn(){return issbn;}
};

class Paperback : public Book
{
public:
  virtual string getDescription() { 
    return "Paperback " + Book::getDescription(); 
  }
};

class Romance : public Paperback
{
public:
  virtual string getDescription() { 
    return "Romance " + Paperback::getDescription(); 
  }
};

class Technical : public Book
{
public:
  virtual string getDescription() { 
    return "Technical " + Book::getDescription();
  }
string issbn;
};

int main()
{

  Romance novel;
  Book book; 
  Technical science;
 
 // outputs "Romance Paperback Book”
    cout << novel.getDescription() << endl;
 //    
 //    // outputs "Book"
       cout << book.getDescription() << endl;
 //
  cout << science.getDescription() << endl;
  cout << science.Book::get_issbn()<< endl;
}
