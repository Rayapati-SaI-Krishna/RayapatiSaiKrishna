#include <iostream> 
#include<string.h>
using namespace std;
extern int a;//global variable
class Program
{
    public:
     mutable int f;
      Program()
     {
      f=10;
      int g=10;
     } 
    
    void auto_func()//Declaring automatic storage class function
    {
        auto x=7.5;
        auto y=8;
        auto z="sai_Krishna";
        cout<<"float value is:"<<x<<endl<<"integer value is:"<<y<<endl<<"string is:"<< z;
    }
    void extern_func()//Declaring extern storage class function
    {
        int a=50;//local varible
        int b=50;
        cout<<"extern value"<<a+b<<endl;
    }
    void register_func()//Declaring register storage class function
    {
       register long int c=10000;//register storage 
       cout<<"register value is"<<c<<endl;
    }
   void static_func() //Declaring Static storage class FUnction
   {    
   static int i=0; //static variable    
   int j=0; //local variable    
   i++;    
   j++;    
   cout<<"i=" << i<<" and j=" <<j<<endl;    
   }
 
   
   void modifier() 
{
	//initialization of modifier types
	signed int i_Data=-30;
	unsigned int i_Udata=40;
	long l_Data=12345678;
	short s_Data=100;
	cout<<endl<<"  MODIFIER TYPES   "<<endl;
	cout<<"signed int idata   : "<<i_Data<<endl;
	cout<<"unsigned int uidata: "<<i_Udata<<endl;
	cout<<"long ldata         : "<<l_Data<<endl;
	cout<<"short sdata        : "<<s_Data<<endl;
}
       
};
int main(int argc,char **argv)  
{  
      if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare variable scope,modifier types & storage classes"<<endl;
    }
else
{
   Program ob;
   ob.static_func();
   ob.static_func();
   ob.extern_func();
   ob.register_func();
   ob.auto_func();
   ob.modifier();
   const Program ob1;
   ob.f=50;
   cout<<"mutable value:"<<ob.f;
}
return 0;
}
