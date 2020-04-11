#include <iostream> 
#include<string.h>
#include<stdlib.h>
#include<cctype>

#include<typeinfo>
#include<bits/stdc++.h>
using namespace std; 
  
int main(int argc, char** argv) 
{ 
  
    char ch;//Declaring character datatype
    int c,i;//Declaring integer datatype
    double d;//Declaring double datatype
   if(argc == 2 && strcmp(argv[1], "--help")==0)
   
    {cout<<"The main purpose of this program is to calculate the datatype,value and sizeof the value"<<endl;
            cout<<"user can give the input in integer,float/double,char and string"<<endl;

    }

   else{
    
    cout << "You have entered " << argc 
         << " arguments:" << "\n";
         
  for(i=1;i<argc;i++)//for loop to increase the i value with respect to argument counter
  {

        if(argv[i]>=0)//if condition for checking whether the value greater than zero or not
	{
		c=atoi(argv[i]);//atol function accepts a string and convert to integer
		d=atof(argv[i]);//atof function accepts a string and convert to float
		cout<<"TYPE"<<"    "<<"value"<<"  "<<"size"<<endl;
		if(c==d) //if condition for comparing the values
		{
                 cout<<"Integer"<<"   "<<c<<"   "<<sizeof(int)<<endl;
		}
		else
		{
		cout<<"Double"<<"   "<<d<<"    "<<sizeof(double)<<endl;
		}
	}
	else
	{
	 
// cout<<argv[i].size()<<endl;
ch=atoi(argv[i]);
          if((ch==1))
	   {
	   cout<<sizeof(char);
	   }
	   else
	   {
	   cout<<sizeof(wchar_t);
	   }
	}
  }
}

       

    return 0; 
} 
