#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;
int main(int argc, char **argv)
{

    if (argc == 2 && strcmp(argv[1], "-h") == 0) //help command

    {
        cout << "The main purpose of this program is to how to know the size of given input" << endl;
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            cout << argv[i] << ' ';

            
            if (((strlen(argv[i])) != 1) && (atof(argv[i]))==0)
            {
                cout << " String "<< sizeof(string);
            }
            else if (((strlen(argv[i])) == 1) && (*argv[i] >= 'a' && *argv[i] <= 'z') || (*argv[i] >= 'A' && *argv[i] <= 'Z'))
            {
                cout << " Char " <<sizeof(char);
            }
            else if (floor(atof(argv[i]))-(atof(argv[i]))!=0)
            {
                cout << " Double " <<sizeof(double);
            }
            
            else if (atoi(argv[i]) >= 0 )
            {
                cout << " Integer " << sizeof(int);
            }
            cout << "\n";
        }
        return 0;
    }
