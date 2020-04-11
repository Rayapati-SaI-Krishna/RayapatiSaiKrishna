#include<iostream>
#include<string.h>
using namespace std;
class age//class Declaration
{
    public: //public data member
    int i_age;
    void display()//display function
    {
        cout<<"A Women can marry at the age:18"<<endl;
        cout<<"A men can marry at the age:"<<i_age<<endl;
    }
    
};
int main(int argc,char **argv)
{
    
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare 'PUBLIC' Access modifier"<<endl;
    }
    else
    {
        age ob;//creating object for class
        ob.i_age=21;//accesing public varibale outside the class
        ob.display();// for Displaying function
    }
    return 0;
}