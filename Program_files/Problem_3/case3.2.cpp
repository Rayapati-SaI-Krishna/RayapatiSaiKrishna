#include<iostream>
#include<string.h>
using namespace std;
void display()//Function Declaration
{
    unsigned char a='c'; //unsigned character Modifier
    signed char b='c'; //signed character Modifier
    unsigned int c=2500;//unsigned integer Modifier
    signed int d= -2500;//signed integer Modifier
    unsigned short int e=2500;//unsigned shor integer Modifier
    signed short int f= -5000;//signed short integer Modifier
    unsigned long int g=5000;//unsigned long integer Modifier
    signed long int h=-2500;//signed long integer Modifier
    long double i=6000;//Long double Modifier 
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl<<f<<endl<<g<<endl<<h<<endl<<i;
}
int main(int argc,char **argv)
{
    
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare Types of Modifiers"<<endl;
    }
    else
    {
        display();
    }
    return 0;
}