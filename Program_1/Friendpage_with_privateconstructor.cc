#include<iostream>
#include<string.h>
#include<map>
#include<regex>
using namespace std;
class Friendpage
{
    private:
    string *s_username=new string();
    string *s_emailid=new string();
    string *s_searchname=new string();
    multimap<string, string> *my=new multimap<string,string>();
    multimap<string, string>::iterator itr;
    Friendpage()//private constructor
    { 

        cout << "==================================" << endl;
        cout << "      Welcome to Friend Page     " << endl;
        cout << "==================================" << endl;
       
    }
   
public:

static Friendpage *constructor()
{
   return new Friendpage();
}
  void add_user();
  void display_user();
  void edit_user();
  void delete_user();
  void search_user();
  void exit_user();
};
void Friendpage::add_user()
{
               
                
                // Here input is an object of regex 
                regex input("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
                cout << "Enter username(i.e firstname_lastname):" << endl;
                 cin.ignore();
                 getline(cin, *s_username, '\n');
                cout << "Enter Email_Id With Respect to Organization(i.e abc@xyz.com):" << endl;
                cin >> *s_emailid;
                // regex_match function matches string s-email id against input regex  
                if(regex_match(*s_emailid,input))
                {
                my->insert(pair<string, string>(*s_username, *s_emailid));//// insert elements in map
                cout<<"Data Created successfully"<<endl;
                //count++;
                }
                else
                {
                    cout<<"please enter valid Email_Id for Entering the records."<<endl;
                }
                
            
            
           
}
void Friendpage::display_user()
{
            for (itr = my->begin(); itr != my->end(); ++itr)
                {
                    cout << "Username: " << itr->first << endl;
                    cout << "Email_Id: " << itr->second << endl;
                }
                for (itr = my->begin(); itr == my->end(); ++itr)
                {
                    cout<<"No user account are Present.If you Want to See the User accounts.Please Go to the Add User Section and Enter Details"<<endl;
                    break;
                } 
}
void Friendpage::edit_user()
{
        // An object of regex for pattern to be searched
     regex input("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        for (itr = my->begin(); itr != my->end(); ++itr)
        {
             cout << "Enter the Username to edit Details"<< endl;
                cin.ignore();
                 getline(cin, *s_searchname, '\n');
                itr = my->find(*s_searchname);//find function
                edit:
                if (itr != my->end())
                {
                  
                   cout<<"Enter new Email_Id"<<endl;
                    cin>>*s_emailid;
                     if(regex_match(*s_emailid,input))
                     {
                  
                
                   my->erase(*s_searchname);//// function to erase 
                   my->insert(pair<string, string>(*s_searchname,*s_emailid));
                   cout<<"The changes are made as per user requirements"<<endl;
                   }
                   else
                   {
                       cout<<"please Enter correct Email_Id"<<endl;
                   goto edit;
                   }
                }
                else
                cout<<"The username was not found in the list.Please select Username in the list to perform edit Operation"<<endl;
                
                }

    
                for (itr = my->begin(); itr == my->end(); ++itr)
                {
                 cout<<"You Searched User Details  is not Found in the Friendpage.Please add User Details Then try to perform edit Operations"<<endl;
                 break;
                 
                }    
}
// function definition outside the class
void Friendpage::delete_user()
{
        
                for (itr = my->begin(); itr != my->end(); ++itr)
                {
                     cout << "Enter the Username to Delete the Account in the  Friendpage" << endl;
                       cin.ignore();
                 getline(cin, *s_searchname, '\n');
                    if (itr->first == *s_searchname)
                    {
                        my->erase(*s_searchname);
                        cout << "The Data is Deleted" << endl;
                    }
                    else
                        cout << "The Data is Not Deleted & Data is not Present in the Friendpage" << endl;
                } 
                for (itr = my->begin(); itr == my->end(); ++itr)
                {
                    cout<<"There are no user accounts.First Enter Records."<<endl;
                    break;
                } 
}
void Friendpage::search_user()
{
                int count=0;
                 for (itr = my->begin(); itr == my->end(); ++itr)
                {
                    --count;
                    goto norecords;
                }
                 cout << "Enter the Username to Search"<<endl;
                        cin.ignore();
                 getline(cin, *s_searchname, '\n');
                for (itr = my->begin(); itr != my->end(); ++itr)
                {
                   
                    
                    if ((itr->first) == (*s_searchname))
                    {
                        count++;
                    }
                  
                    
                }
                  if(count>=1)
                    {
                        cout<<"Data is Present"<<endl;
                        
                    }
                    else if(count==0)
                    {
                        cout<<" Data is not present"<<endl;
                        
                    }
                    norecords:
                    if(count<0)
                    cout<<"No records found.first Enter the records"<<endl;
                  
                    
}
void Friendpage::exit_user()
{
    delete s_username;
    delete s_emailid;
    delete s_searchname;
    delete my;
    exit(1);
}

int main(int argc,char **argv)
{
      if (argc == 2 && strcmp(argv[1], "-h") == 0) //help command

    {
        cout << "The main purpose of this program is to how to Design an FRIENDPAGE application."<<endl;
        cout<<"a. Add a new user by asking their name and email-id"<<endl;
        cout<<"b. Edit an existing user details"<<endl;
        cout<<"c. Delete the user based on name/email-id"<<endl;
        cout<<"d. Search the entire user list by name/email-id"<<endl;
        cout<<"e. Add friends by looking up the name and email-id"<<endl;
        cout<<"f. Let them know if the selected user is already a friend"<<endl;
        cout<<"g. Use the ‘suggest Friends’ option to see if there are any mutual friends available" << endl;
    }
    else if (argc == 2 && strcmp(argv[1], "-h") != 0) //help command

    {
        cout << "You Have Given Wrong Help command.Try to give (-h) for display the description of program" << endl;
    }
  else
  {
  Friendpage* fp;
    fp=Friendpage::constructor();//prints Object created once
 
  int choice;
  
  while(1)
  {
     cout << "1.Add User" << endl;
        cout << "2.Edit an User Details" << endl;
        cout << "3.search the user by username" << endl;
        cout << "4.Remove the elements by username" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;
        cout << "==================================" << endl;
        cout << "Select an option" << endl;
      cin>>choice;
  switch(choice)
  {
      case 1:cout << "==================================" << endl;
      fp->add_user();
      cout << "==================================" << endl;
      break;
      case 2:cout << "==================================" << endl;
      fp->edit_user();
      cout << "==================================" << endl;
      break;
      case 3:cout << "==================================" << endl;
      fp->search_user();
      cout << "==================================" << endl;
      break;
      case 4:cout << "==================================" << endl;
      fp->delete_user();
      cout << "==================================" << endl;
      break;
      case 5:cout << "==================================" << endl;
      fp->display_user();
      cout << "==================================" << endl;
      break;
      case 6:cout << "==================================" << endl;
      fp->exit_user();
      delete fp;
      cout << "==================================" << endl;
      break;
  }
  }
  }
}
