#include <iostream>
#include<string.h>
using namespace std;
class A
{
    
  private:
  int a,b ;
  protected:
  int c, d;

public:
  void adddata(int x1, int y1)
  {
    a = x1;
    b = y1;
  }
  void display()
  {
    cout << "The sum of two private integer data members are = " << a + b << endl;
    cout << "The product of two private integer data members are = " << a * b << endl;
  }

  void getdata(int x, int y)
  {
    c = x;
    d = y;
  }
};
class B : public A
{
public:
  void showdata()
  {
    cout << "The value of the first protected variable(output of subclass)= " << c << endl;
    cout << "The value of the second protected variable(output of subclass)" << d<< endl;
    cout << "Sum of the protected variables = " << c + d << endl;
  }
};
int main(int argc,char **argv)
{
  if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare PUBLIC,PRIVATE & PROTECTED Access modifier"<<endl;
    }
  else{  
  A obj;//object creation
  B obj1;
  obj.adddata(10,11);//intializing data to the private variables
  obj.display();//displaying the private variables
  obj1.getdata(4, 5);//intializing data for the protected access specifier
  obj1.showdata();//displaying the protecetd variables
  }
  return (0);
}