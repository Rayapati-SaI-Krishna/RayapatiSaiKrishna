
#include<iostream>
#include<string.h>
using namespace std;
int x=0;
void operation(int m,int n,char **a,int choice,int diag)
{
    int t[n],i,j,r,c,r1,c1,rows;
    if(diag == 2)
        rows=2;
    else
        rows=m;
    for (i = 0; i < rows; i++) //for loop
    {
        for (j = 0; j < n; j++)
	    {
	        t[j] = j;
	    }
	    for (j = 0; j < n - 1; j++)
	    {
	        if(choice==0) //If condition
	        {
	            r = i;
	            c = t[j];     //assigning values
	            r1 = i;
	            c1 = t[j + 1];
	        }
	        else
	        {
	            c = i;
	            r = t[j];
	            c1 = i;
	            r1 = t[j + 1];
	        }
	        if (a[r][c] == a[r1][c1])
	    	{
		        t[j + 1] = j;
		    }
	    }

        int p = 0;
        for (j = 0; j < n; j++)
	    {
	        if (t[j] == j)
	       {
	           if(choice==0)
	                a[i][p] = a[i][j];
	           else
	                a[p][i] = a[j][i];
	            p++;
	       }
	    }
        while (p != n)
	    {
	        x=1;
	        if(choice==0)
	            a[i][p] = '*';
	       else
	        a[p][i] = '*';
	        p++;

	    }
    }
}


void print(char **a,int m,int n) //Print Function
{
    int i,j;
    for (i = 0; i < m; i++)
	{
	  for (j = 0; j < n; j++)
	    {
	      cout << a[i][j] <<" ";
	    }
	    cout << "\n";
	}
}

int main (int argc,char **argv)
{
       if (argc == 2 && strcmp(argv[1], "-h") == 0) //help command

    {
        cout<<"To Perform Row.Column& Diagonal of a Given  matrix of size M*N with only 0s and 1s"<<endl;
    }
    else if (argc == 2 && strcmp(argv[1], "-h") != 0) //help command

    {
        cout << "You Have Given Wrong Help command.Try to give (-h) for display the description of program" << endl;
    }
    else
    {
    int n,m,choice;
    cout<<"Enter the no.of rows:"<<endl;
   //Entering the size of rows
    cin >> m;
    cout<<"Enter the no.of columns"<<endl;
   //Entering the size of colums
    cin>>n;
   //Entering the choice of operation
    cout<<"Enter your choice to do the operation"<<endl<<"0.Row operation\n1.Column operation\n2.Diagonal operation"<<endl;
    cin >> choice;// 0 for row,1 for column, 2 for diagnol
    if(choice>=0&&choice<=2)
    {
        if((choice==0 && n>1) || (choice==1 && m>1) || (choice==2 && (m==n))){
    char **a;//pointer to pointer character array
    int i, j;
    a = new char *[n];//allocate n objects of type char
//Entering the input values//
    for (i = 0; i < m; i++)
    {
        a[i] = new char[n];
        for(j=0;j<n;j++)
        {
         cout << "Enter " << i << j << " element:\n";
            cin >> a[i][j];
        }
    }
    cout << "Input is \n";
    print(a,m,n);//call the print function to display input
    if(choice == 2)
    {
        char *b[2];
        b[0] = new char[n];
        b[1] = new char[n];
        int p0=0,p1=0;
        for (i = 0; i < m; i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                    b[0][p0++] = a[i][j];
                if((i + j) == (n - 1))
                    b[1][p1++] = a[i][j];
            }
        }
        operation(m,n,b,0,2);//call to perform operation
        p0=0;p1=0;
        for (i = 0; i < m; i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==j)
                     a[i][j] = b[0][p0++];
                if((i + j) == (n - 1))
                    a[i][j] = b[1][p1++];
            }
        }
    }
    else
        operation(m,n,a,choice,1);
    cout << "\nOutput is \n";
    //cout<<x<<"\n";
    if(x==0){
        cout<<"There is nothing to change.Because consecutive numbers are not present.";
    }
    else{
        print(a,m,n);
    }
    }
    else
    {
        cout<<"Invalid Request";
    }
    }
    }
  return 0;
}
