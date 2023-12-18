#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string>
#include<time.h>      //time,unsigned
#include<windows.h>   //sleep
using namespace std;
using std::string;


//multilevel inheritance
 
class voting               //class made for counting votes
{   public:
    	static int vote1, vote2, vote3, vote4;

		void bjp_gd()
		{
			++vote1;          //incrementing bjp votes
		}
		void congress_gd()
		{
			++vote2;          //incrementing congress votes
		}
		void bsp_gd()
		{
			++vote3;          //incrementing bahujan samaj votes
		}
		void aap_gd()
		{
			++vote4;          //incrementing aap votes
		}
	
	
	   void result()
       {
            ofstream fout1("Result.txt");
	   		if(vote1>vote2 && vote1>vote3 && vote1>vote4)
			{   fout1<<"\n BHARTIYA JANTA PARTY HAS WON THE ELECTION WITH "<<vote1<<" VOTES";
				cout<<"\n BHARTIYA JANTA PARTY HAS WON THE ELECTION WITH "<<vote1<<" VOTES";
			}
			else if(vote2>vote1 && vote2>vote3 && vote2>vote4)
			{ 
			    fout1<<"\n INDIAN NATIONAL CONGRESS HAS WON THE ELECTION WITH "<<vote2<<" VOTES";
	   			cout<<"\n INDIAN NATIONAL CONGRESS HAS WON THE ELECTION WITH "<<vote2<<" VOTES";
			}
			else if(vote3>vote1 && vote3>vote2 && vote3>vote4)
			{   fout1<<"\n BAHUJAN SAMAJ PARTY HAS WON THE ELECTION WITH "<<vote3<<" VOTES";
				cout<<"\n BAHUJAN SAMAJ PARTY HAS WON THE ELECTION WITH "<<vote3<<" VOTES";
    		}
    		else
    		{   fout1<<"\n AAM AADMI PARTY HAS WON THE ELECTION WITH "<<vote4<<" VOTES";
    			cout<<"\n AAM AADMI PARTY HAS WON THE ELECTION WITH "<<vote4<<" VOTES";
			}
			fout1.close();
		}
};
int voting::vote1;
int voting::vote2;
int voting::vote3;
int voting::vote4;


class user: public voting      // class for user details
{
	public:
		string fname,lname;
	    int vid;
	    int age;
	    char gender[6];
	    int mobile;
	    int pincode;
	    
	    void voterid()
    {
		int c,i,d;
		char vd[9],dvd[9];
		cout<<"\n\n--------------------------------------";
        cout<<"\n 1.  TO GENRATE VOTER ID"<<endl;
    	cout<<"\n 2.  TO EXIT"<<endl;
    	cout<<"\n-------------------------------------";
    	cout<<"\n Enter your Choice:";
    	cin>>d;
    	if(d==1)
    	{	
    	srand((unsigned) time(NULL)); //srand- random numbers within the parameter conditions
    	for(i=0;i<8;i++)
    	{
    	c=rand()%10 + 48;      //%10- 0-9 all ditigts  48 is min value that is ASCI value of 0
    	vd[i]=c;	
		}
		vd[i]='\0';            //storing null at the end
		cout<<"\n\tVOTER ID GENRATED!!!";
		cout<<"\n\tYOUR VOTER ID :"<<vd;
		}
		else if(d==2)
		{
			system("exit");
		}
		else
		{
			cout<<"\tINVALID CHOICE"<<endl;
			voterid();
		}
	
    }
	
	    
	    void ugd()
	    { 
	     
		  cout<<"\nEnter Name         : ";
	      cin>>fname>>lname;
	      cout<<"Enter Voter ID     : ";
	      cin>>vid;
	      cout<<"Enter Age          : ";
	      cin>>age;
	      cout<<"Enter Gender       : ";
	      cin>>gender;
	    /*  cout<<"Enter Mobile Number     : ";
	      cin>>mobile;
	      cout<<"Enter your Area Pincode : ";
	      cin>>pincode;*/
	      cout<<"\n--------------------------------------------------------------------------------------------------------------------------\n\n";
		}
		void usd()
		{   ofstream fout("votercertificate.txt",ios::app|ios::in|ios::out);
		    fout<<"\n\n-------------------------------------";
			fout<<"\nName  :"<<fname<<" "<<lname;
			fout<<"\nAge   :"<<age;
			fout<<"\nGender:"<<gender;
			fout<<"\n*YOUR VOTING PROCESS IS SUCCESSFUL*";
			fout<<"\n\n-------------------------------------";
		    cout<<"\n\n-------------------------------------";
			cout<<"\nName  :"<<fname<<" "<<lname;
			cout<<"\nAge   :"<<age;
			cout<<"\nGender:"<<gender;
			cout<<"\n*YOUR VOTING PROCESS IS SUCCESSFUL*";
			cout<<"\n\n-------------------------------------";
			fout.close();
		}
		void vote()
		{   if(age<18)
		    { 
		      cout<<"You are not Eligible to vote";
			}
			else
			{
	
		     int ch; char ch4;
			 cout<<"\nPOLITICAL PARTIES STANDING IN THE ELECTION ARE:- ";
			 cout<<"\n1. Bhartiya Janata Party";
			 cout<<"\n2. Indian National Congress";
			 cout<<"\n3. Bahujan Samaj Party";
			 cout<<"\n4. Aam Aadmi Party\n";
			 cout<<"\n\nENTER YOUR VOTING CHOICE\n";
			 cin>>ch;
			 switch(ch)
			 {
				case 1:
					cout<<"\nYou voted for Bhartiya Janta Party";
					bjp_gd();
					break;
					
				case 2:
					cout<<"\nYou voted for Indian National Congress";
					congress_gd();
					break;
						
				case 3:
					cout<<"\nYou voted for Bahujan Samaj Party";
					bsp_gd();
					break;
						
				case 4:
					cout<<"\nYou voted for Aam Aadmi Party";
					aap_gd();
					break;
				
				default:
					cout<<"\nWrong number entered"<<endl;
					vote();
			 }
		    cout<<"\n\nYOUR VOTING PROCESS HAS BEEN COMPLETED SUCCESSFULLY\n";
		    cout<<"Click 'a' to EXIT\n";
		    cin>>ch4;
		    cout<<"\n";
		    cout<<"_______________________________________________________________________________________________________________";
	        }
		
		}		
};


class EC: public user
{ 
  public: 
    int choose ;
   
    void login(){
			int ch;
			string id;
			string Password;
			system("cls");
			cout<<"Enter your id and password to proceed:\n";
			cout<<" ID: ";
			cin>>id;
			cout<<"Password: ";
			ch=getch();
			while(ch!=13){
				Password.push_back(ch);
				cout<<'*';
				ch=getch();
			}
			if(id=="EC" && Password=="EC123"){
				cout<<"\nWelcome!\n";
				ec_choice();
				
			}	
			else{
				cout<<"Invalid login";
			}
		}
	
	/*	void result_call()
	{
  		result();
	}*/
	void ec_choice()
	{ cout<<"\nCLICK\n";
	  cout<<"1. To view how many users voted\n";
	  cout<<"2. To view the result\n";
	  cin>>choose;
	  switch(choose)
	  {
	  	case 1: 
	  	 cout<<"\nVIEWING TOTAL VOTES\n";
	  	 total_user();
	  	 ec_choice();
	  	 break;
	  	
	  	case 2:
	  		cout<<"\nVIEWING THE RESULT\n";
	  		result();
	  		system("exit");
	  		break;
	  	default:
	  		exit;
	  }
	}
	
	void total_user()
	{
		int sum;
		sum=vote1+vote2+vote3+vote4;
		cout<<"\nTotal users who voted are:-"<<sum<<"\n";
	}
};

int main()
{  
    EC a;
	user u; 
    int ch2,ch3;
    cout<<"\n\n";
    cout<<"\t\t\t\t\t::::::::WELCOME TO THE VOTING SYSTEM::::::\n";
    cout<<"\t\t\t\t\t_________________________________________\n";
    cout<<"\t\t\t\t\t|       |          CLICK                 |\n";
    cout<<"\t\t\t\t\t|     1.| User                           |\n";
    cout<<"\t\t\t\t\t|     2.| Election Comissioner           |\n";
    cout<<"\t\t\t\t\t|     3.| To Genrate Voter ID            |\n";
    cout<<"\t\t\t\t\t|     4.| Exit                           |\n";
    cout<<"\t\t\t\t\t|_______|________________________________|\n\n";
    cout<<"\t LOGIN AS:- ";
    cin>>ch2;
    cout<<"___________________________________________________________________________________________________________________________________\n";
	switch(ch2)
  {
  	case 1:
  		cout<<"\nLOGGED IN AS USER\n";
		  u.ugd();
		  u.vote();
	//	  fstream inout1("votercertificate.txt",ios::in|ios::out|ios::binary);
		  u.usd();
	//	  inout1.write((char*)&u,sizeof(u));
	//	  inout1.close();
		  system("cls");
	    main();
	    break;
	
	case 2:
		cout<<"LOGGING IN AS ELECTION COMISSIONER";
		a.login();
		//a.ec_choice();
		break;
		system("exit");
	case 3:
		a.voterid();
		Sleep(5500);
		system("cls");
		main();
	case 4:
		exit(0);
	default:
		main();
		
	}
  return 0;
}


