#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
//class declaration
class bank
{
private:
	//declaration of variables in private 
    int *iAc_No;               
    char cName[20]; 
public:
	//default constructor
    bank()   
    {
        cout<<"Default Constructor :"<<endl;
        
    }
    //parameterised constructor                                                          
     bank(int *i_no,char *cname)  
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
         iAc_No=i_no;
        strcpy(cName,cname);
    }
    //copy constructor
     bank(const bank& ob)
    {
    	iAc_No=new int;
        strcpy(cName,ob.cName);
        //copying variables
        *iAc_No=*ob.iAc_No;
    }
    /*function name : Acc_Details
     parameters     : *ino,cname[]
     */
 void Acc_Details(int *ino,char cname[])
    {   
        iAc_No=ino;
        strcpy(cName,cname);
    }
    void display()
    {
        cout<<"ID Number :"<<*iAc_No<<endl<<"Name:"<<cName<<endl;
        cout<<endl;
    }
     //Assignment Operator Overloading
    void operator =(const bank& t)
    {
        strcpy(cName,t.cName);
        *iAc_No=*t.iAc_No;
    }
    // destructor
    ~bank()
    {
        cout<<"Deallocating Memory"<<endl;
       
    }
   
};
int main(int argc,char* argv[])
{
	// condition for the arguments to display -h file
    if(argc>=2) 
   {
   	if(strcmp(argv[1],"-h"))
   	        
    {
     cout<<"Usage :"<<endl;
     cout<<"Enter the integer and char variables "<<endl;
        }
    }
    else
    {
    	//object creation for class 
        bank b; 
		int iNum;
        char cNme[20];
         cout<<"Enter Acc No of the A/C Holder:";
        cin>>iNum;
        cout<<"Enter Name of the A/c Holder:";
       // cin>>cNme;
         getchar();
        cin.get(cNme,100,'\n');
        b.Acc_Details(&iNum,cNme);
        b.display();
        //Parameterised Constructor
         cout<<endl<<"Using Parameterized Constructor :"<<endl;
         bank b1(&iNum,cNme);    
        b1.display();
        //copy Constructor
        bank b2=b;
        cout<<"After Using Copy Constructor"<<endl;
         b2.display();
        cout<<"Assignment Operator is Invoked"<<endl;
         b2=b1;
         b2.display();
         b2=b;
         b2.display();
      
	 }
    return 0;
}
