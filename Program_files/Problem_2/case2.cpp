#include<iostream>
#include<string.h>
using namespace std;
int main(int argc, char **argv)
{
    
     
    if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to  get Sum of N Natural Numbers"<<endl;
    }
    else
    {
    int n;
    cout << "Enter N: ";
    cin >> n;
    long sum = 0;
    for (int i = 1; i <= n; i++) 
    {
      sum += i * i; //square i and add it with sum
    } 
     cout << "Result is: " << sum<<endl;
    }
    


}
