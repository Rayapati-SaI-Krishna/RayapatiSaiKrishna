#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Notes{
private:

        char cPrg[300];
        char cDir[300];
        int iKit;
        int iInstall;
        int iPNo;
        int iStatusWindow;        
        char cService[300];
        char cRecovery[200];
        int iTimezone;
        int iDst;
        int iDstlaw;
        char cFiledir[300];

        void waitForEnter(){
                cout<<"\n\n\n Press enter to go back \n\n";
                cin.get();
        }
		
		void addNotesInfo(void)
		{
                char moreRecords;  
				do{              
                        cout<<"\n----------------------------------------";
                        cout<<"\n NotesProgram= ";
                        cin>>cPrg;
                        cout<<"\n Directory= ";
                        cin>>cDir;
                        cout<<"\n KitType= ";
                        cin>>iKit;
                        cout<<"\n InstallType= ";
                        cin>>iInstall;
                        cout<<"\n PartitionNumber= ";
                        cin>>iPNo;
                        cout<<"\n showControllerStatusWindow= ";
                        cin>>iStatusWindow;
                        cout<<"\n ServiceName= ";
                        cin>>cService;                        
                        cout<<"\n FaultRecovery_Build= ";
                        cin>>cRecovery;                        
                        cout<<"\n Timezone= ";
                        cin>>iTimezone;                        
                        cout<<"\n DST= ";
                        cin>>iDst;                        
                        cout<<"\n DSTLAW= ";
                        cin>>iDstlaw;                        
                        cout<<"\n FileDlgDirectory= ";
                        cin>>cFiledir;
                        
                        cout<<"\n----------------------------------------";

                        char ch;
                        cout<<"\nEnter 'y' to save above information\n";
                        cin>>ch;
                        if(ch=='y'){
                                FILE  *file;
                                file= fopen("config.ini","a");
                                fprintf(file,"\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cPrg, cDir, iKit, iInstall, iPNo, iStatusWindow, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                                fclose(file);
                                cout<<"\n Information is added to database\n";
                        }
                        else
                        addNotesInfo();
                        waitForEnter();
                        getchar();
                        cout<<"do you want to add more records? (Y/N)";
                        cin>>moreRecords;
                }while(moreRecords=='y');
        }
        
		void listconfig(void){

                FILE *file;
                file= fopen("config.ini", "r");
                cout<<"\n\t\t      ListConfig	\n";
                
                while(fscanf(file,"\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cPrg[0], &cDir[0], &iKit, &iInstall, &iPNo, &iStatusWindow, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
				{
                	cout<<"\n----------------------------------------";
                        cout<<"\n NotesProgram= "<<cPrg;
                        cout<<"\n Directory= "<<cDir;
                        cout<<"\n KitType= "<<iKit;
                        cout<<"\n InstallType= "<<iInstall;
                        cout<<"\n PartitionNumber= "<<iPNo;
                        cout<<"\n showControllerStatusWindow= "<<iStatusWindow;
                        cout<<"\n ServiceName= "<<cService;                        
                        cout<<"\n FaultRecovery_Build= "<<cRecovery;                        
                        cout<<"\n Timezone= "<<iTimezone;                        
                        cout<<"\n DST= "<<iDst;                        
                        cout<<"\n DSTLAW= "<<iDstlaw;                        
                        cout<<"\n FileDlgDirectory= "<<cFiledir;                        
                        cout<<"\n----------------------------------------";
				}
        
                fclose(file);
                waitForEnter();
        }
 		
 		void editExisting(void)
		{
                char checkId[30];
                cout<<"\nEnter Server Name= ";
                cin>>checkId;
                char newFiledir[300];
                cout<<"\n-----------------------------";
                cout<<"\nEnter new FileDlgDirectory= ";
                cin>>newFiledir;
                
                FILE *file, *tempfile;
                file= fopen("config.ini", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file,"\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cPrg[0], &cDir[0], &iKit, &iInstall, &iPNo, &iStatusWindow, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
				{
                        if(strcmp(checkId, cService)==0)
                                fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cPrg, cDir, iKit, iInstall, iPNo, iStatusWindow, cService, cRecovery, iTimezone, iDst, iDstlaw, newFiledir);
                        else
                                fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cPrg, cDir, iKit, iInstall, iPNo, iStatusWindow, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                }
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("config.ini");
                int isRenamed= rename("temp.ini", "config.ini");
                waitForEnter();
        }
        
        void deleteConfig(void){

                char checkId[30];
                cout<<"\nEnter Server Name= ";
                cin>>checkId;
                char ch;
                cout<<"\n\n\n Confirmation\n Enter 'y' To Confirm Deletion \n";
                cin>>ch;
                if(ch=='y'){
                        FILE *file, *tempfile;
                        file= fopen("config.ini", "r");
                        tempfile= fopen("temp.ini", "w");
                        while(fscanf(file, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", &cPrg[0], &cDir[0], &iKit, &iInstall, &iPNo, &iStatusWindow, &cService[0], &cRecovery[0], &iTimezone, &iDst, &iDstlaw, &cFiledir[0])!= EOF)
                                if(strcmp(checkId, cService)!=0)
                                        fprintf(tempfile, "\n NotesProgram= %s \n Directory= %s \n KitType= %i \n InstallType= %i \n PartitionNumber= %i \n showControllerStatusWindow= %i \n ServiceName= %s \n FaultRecovery_Build= %s \n Timezone= %i \n DST= %i \n DSTLAW= %i \n FileDlgDirectory= %s \n", cPrg, cDir, iKit, iInstall, iPNo, iStatusWindow, cService, cRecovery, iTimezone, iDst, iDstlaw, cFiledir);
                                        fclose(file);
                                        fclose(tempfile);
                                        int isRemoved= remove("config.ini");
                                        int isRenamed= rename("temp.ini", "config.ini");
                                        cout<<"\nRemoved data Successfully\n";
                }
                else
                    deleteConfig();
        }
		
public:
        void options(void){
                while(true){

                        cout<<"\n\t\t\t>>>  Notes Config List  <<<";
                        cout<<"\n";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\t\t\t   1:   AddConfig";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\t\t\t   2:   listconfig";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\t\t\t   3:   editExisting";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\t\t\t   4:   deleteConfig";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\t\t\t   0:   To Exit     ";
                        cout<<"\n\t\t\t---------------------------";
                        cout<<"\n\n\t\t   Please Enter Your Choice: ";

                        int choice;
                        cin>>choice;

                        switch (choice) {
                                case 0:
                                        cout<<"\n\n Notes Domino List \n\n ";
                                        return;
                                case 1:
                                        addNotesInfo();
                                        break;
                                case 2:
                                		listconfig();
                                		break;
                                case 3:
                                		editExisting();
                                		break;
                                case 4: 
                                		deleteConfig();
                                		break;
                                default:
                                        cout<<"\n Sorry! Invalid option!!! \n";
                                        break;
                        }
                }
        }
};
        
        

int main(){
        Notes n;
        n.options();
        return 0;
}
