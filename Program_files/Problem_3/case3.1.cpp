#include<iostream>
#include<string.h>
using namespace std;
int age=21;//Declared Global variable
void display()//Function Declaration
{
    int age=18;//Local Variable Declaration which will be used for this particulor function
    cout<<"A Women can marry at the age:"<<age<<endl;//age can be accessed by global declared variable
}
int main(int argc,char **argv)
{
    
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare the Local & Global scope variable"<<endl;
    }
    else
    {
        display();//displaying the function
        
        cout<<"A men can marry at the age:"<<age<<endl;//Here age is taken globally
        
    }
    return 0;
}
