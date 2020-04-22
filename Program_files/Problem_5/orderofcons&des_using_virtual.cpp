#include <iostream> 
#include<string.h>
using namespace std;
 
class Container
{
public:
    Container() {};
    virtual ~Container()
    {
        cout << "Base class destructor called - not much to do." << endl;
    };
};
 
class CardboardBox: public Container {
public:
    CardboardBox() {};
    ~CardboardBox()
    {
        cout << "Sub class destructor called - let's recycle the cardboard!" << endl;
    };
};
 
int main(int argc,char **argv)
{
      if(argc == 2 && strcmp(argv[1], "-h")==0) //help command 
   
    {
        cout<<"The main purpose of this program is to how to use & Declare the Local & Global scope variable"<<endl;
    }
    else
    {
    CardboardBox* box = new CardboardBox;
 
    Container* p = box;
 
    delete p;
    }
 
    return 0;
}
