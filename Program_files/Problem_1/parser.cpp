#include <iostream> 
#include<string.h>
#include<stdlib.h>
#include<cmath>
using namespace std; 
int main(int argc, char** argv) 
{ 
    
     if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare Different way to initialize the private member variables in a class"<<endl;
    }
    else {
	for (int i = 1; i < argc; ++i) {
		cout << argv[i]<<' ' ;
		
    
   if(((strlen(argv[i]))==1) && (*argv[i]>='a'&& *argv[i]<='z') || (*argv[i]>='A' && *argv[i]<='Z'))
   {
       cout<<sizeof(char);
   }
   else if((strlen(argv[i]))!=1)
   {
       cout<<sizeof(string);
   }
    
   else if(atoi(argv[i])>=0 && atoi(argv[i])<=9)
   {
       cout<<sizeof(int);
   }
   else if((atoi(argv[i]))==(atof(argv[i])) )
   {
       cout<<sizeof(double);
   }
   cout << "\n" ;
	}
	return 0; 
}
} 
