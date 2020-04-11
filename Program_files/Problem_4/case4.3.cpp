#include<iostream>
#include<string.h>
using namespace std;
class age//class Declaration
{
    protected: //protected data member
    int i_age;
};
class marriage : public age
{
    public:
    void setage(int i_age1)//public member function
    {
    
    i_age=i_age1;
    }
    void display()//display function member function can access private data member i_age
    {
        //i_age=i_age1;
        cout<<"A Women can marry at the age:18"<<endl;
        cout<<"A men can marry at the age:"<<i_age<<endl;
    }
    
};
int main(int argc,char **argv)
{
    
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare 'PROTECTED' Access modifier"<<endl;
    }
    else
    {
        marriage ob;//creating object for class
        ob.setage(21);
        ob.display();// trying to access PROTECTED data member directly outside the class
    }
    return 0;
}