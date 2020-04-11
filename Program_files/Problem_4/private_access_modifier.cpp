#include<iostream>
#include<string.h>
using namespace std;
class age//class Declaration
{
    private: //private data member
    int i_age;
    public://public member function
    void display(int i_age1)//display function member function can access private data member i_age
    {
        i_age=i_age1;
        cout<<"A Women can marry at the age:18"<<endl;
        cout<<"A men can marry at the age:"<<i_age<<endl;
    }
    
};
int main(int argc,char **argv)
{
    
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare 'PRIVATE' Access modifier"<<endl;
    }
    else
    {
        age ob;//creating object for class
        ob.display(21);// trying to access private data member directly outside the class
    }
    return 0;
}