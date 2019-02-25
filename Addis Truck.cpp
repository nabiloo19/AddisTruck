//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

int count=0,a=0,*pin=new int(),*p=new int(),D=0,No=0;	//global variables that controls the data flow of the database
char retu;
int *pass=new int(); // dynamic memory allocated for password as pointers..
void ourinfo();	// teams' information
int main(); // prototyping the main function so it can be used throught the whole program using classes


		/*********************************************************************
		****** BASE CLASS USED IN THIS PROGRAM, NAMED Record *************
		*********************************************************************/

class Record
{
	protected: // to enhance the inheritance ability

        char name[20],address[15],from[15],to[15],truckmodel[15],truckno[15];
        int phone,id;

    public:

       /*
       *
       *	Prototyped functions
       *
       */
       Record()
	   { // constructor to intilize the variables, of int type
       	phone=0,id=0,*pass=0,*p=0;
       	   }
       	   
       void get_Dinfo(int n);
       void D_display();
       void search();
       void D_modify();
       void Driver_option()
		{
       		cout<<  "\n\n\t->Admin<-\n"
			   		"\t\t1,Register\n"
       				"\t\t2,Display\n"
       				"\t\t3,Search\n"
       				"\t\t4,Modify\n"
       				"\t\t5,Sort\n"
       				"\t\t6,Client Info\n"
       				"\t\t7,Delete\n"
       				"\t\t8,Home\n"
       				"\t\t\tSelect Your Option:-";
      }

	  void sort();
	   void deleted(); // a seperate function used to delete
	   ~Record(); // deconstructer of the constructer

}D_info[100],*Dmenu; // 100 objects created & a pointer variable

void Record::get_Dinfo(int n)
{
		system("cls");
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
			cout<<"\t\t\t@      REGISTARER   @\n";
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";

   			 		a+=n; // the 'a' variable is to handle multiple, seperated insertion of data

			cout<<"\n\n\tEnter Driver's Details:\n";

		for(count=a-n;count<a;count++){

			cout<<",Driver "<<count+1<<endl;
            cout<<"Enter Driver's Name:- ";
            cin>>D_info[count].name;
           	 cout<<"Enter Driver's Phone:-# ";
            cin>>D_info[count].phone;
             cout<<"Enter Driver's Address:- ";
            cin>>D_info[count].address;
             cout<<"Enter Driver's ID:-# ";
            cin>>D_info[count].id;
            cout<<"Enter Truck Model:- ";
            cin>>D_info[count].truckmodel;
            cout<<"Enter truck Number:-# ";
            cin>>D_info[count].truckno;
             cout<<"From:- ";
            cin>>D_info[count].from;
             cout<<"\tTo:- ";
            cin>>D_info[count].to;
            cout<<"\n\n";
		}
}

void Record::D_display()
{

			cout<<"***********************************************************************************************************************";
			cout<<"\t\n,Driver "<<count+1<<endl;
            cout<<"\n\tDriver's Name- "<<name<<"\tDriver's Phone-# "<<phone
             <<"\tDriver's Address- "<<address;
			 cout<<"\n\n\t\t truck Model:- "<<truckmodel<<"\t\t truck Number:-# "<<truckno<<"\t\tDriver's ID-# "
			 <<id;
			 cout<<"\n\n\t\t\tFrom:- "<<from<<"\t\t\tTo- "<<to<<endl;
			 cout<<"***********************************************************************************************************************\n\n";

}


void Record::search()
{

	system("cls");

	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@      SEARCH       @\n";
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";

	int s,f;// 's' is used to ask the user to enter the options & 'f' is to ensure the data has successfully been found
	char t[20],dep[15],arriv[15]; // three variables created locally for dataset usage

	do{
			system("cls");

	cout<<"\t\t\n\n->Search By\n\n"
			"\t1,By Name\n"
			"\t2,By Id\n"
			"\t3,By Destanation --For Clients--\n"
			"\t\tSelect your Option:-";
					cin>>s;

	if(s==1)
	{
		cout<<"\n\n\t\tEnter Driver's Name to Search:- ";
		cin>>t;

		for(count=0;count<a;count++)
		{	// 'a' is the global variable of the maxium number

		if(strcmp(t,D_info[count].name)==0)
		{
				f=1;
			break;
			}
		}
	}

	else if(s==2)
	{

			cout<<"\n\n\t\tEnter Driver's ID to Search:-# ";
			cin>>s;

	for(count=0;count<a;count++)
	{

		if(D_info[count].id==s){
			f=1;// the comparing system works as follows: 1-> True , 2-> False
			break;
			}
	  }
}

	else if(s==3)
{
			cout<<"\n\n\t\tEnter Departure city(from):- ";	cin>>dep;
			cout<<"\n\n\t\tEnter Arrival city(to):- ";	cin>>arriv;

	for(count=0;count<a;count++)
	{

		if(strcmp(D_info[count].from,dep)==0 && strcmp(D_info[count].to,arriv)==0)
		{
			f=1;// the comparing system works as follows: 1-> True , 2-> False
			break;

		}
    }

}

	if(f==1)
	{ // if 'f' is =1, which means True, then it executes the following

				cout<<"\n\t\tSearch Has Been Found!!!\n\n";
		D_info[count].D_display();
			f=0;	// the data is again set to zero to ensure the searching works well
	}

	else{// if 'f' is not 1, then it show the below massege
						cout<<"\n\t***Sorry,Your Search not found!!***\n";
		}

	cout<<"To Return back press B,r or L to Leave:-";
	cin>>retu;

		if(retu=='L' || retu=='l')
		{
		 break;
		}

}while(retu=='b'|| 'B');

}

void Record::D_modify()
{

	/*
	*
	*	The user has to enter the searched number and if it was successfully found,
	*	then certain lines of code will be executed.
	*	The algorithm is nothing but the searching algorithm with some new features
	*/

	int Id,m;

	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@        EDIT       @\n";
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";


	cout<<"\n\n\t\tEnter Driver's ID  to Search:- ";
	cin>>Id;

	int f=0;

	for(count=0;count<a;count++)
	{

		if(D_info[count].id==Id)
		{
			f=1;
			break;

		}
	}


	if(f)
	{
		D_info[count].D_display();cout<<"\n";
		cout<<"\n\n\t\t->Modify Options:-Which Data do you want to Modify?\n\n"
			 		"\t1,Name\n"
			 		"\t2,Phone Number\n"
			 		"\t3,Address\n"
			 		"\t4,ID\n"
			 		"\t5,Truck model\n"
			 		"\t6,Truck Number\n"
			 		"\t7,From & To\n"
			 		"\t8,The Whole Data\n"
			 		"\t\t\tSelect Your Option:-";

			 		cin>>m;

            if(m==1)
			{

            cout<<"Enter New Driver's Name:- ";
            cin>>D_info[count].name;

			}

            else if(m==2)
			{
            	cout<<"Enter New Driver's Phone:-# ";
            cin>>D_info[count].phone;
			}

			else if(m==3)
			{
            	cout<<"Enter New Driver's Address:- ";
            cin>>D_info[count].address;
			}

			else if(m==4)
			{
             	cout<<"Enter New Driver's ID:-# ";
            cin>>D_info[count].id;
			 }

			else if(m==5)
			{
             	cout<<"Enter New Truck Model:- ";
            cin>>D_info[count].truckmodel;
			 }

			else if(m==6)
			{
            	cout<<"Enter New truck Number:-# ";
            cin>>D_info[count].truckno;
			}

			else if(m==7)
			{
            	cout<<"From:- ";
            cin>>D_info[count].from;
            cout<<"\tTo:- ";
            cin>>D_info[count].to;
			}

			else if(m==8)
			{
			system("cls");

			cout<<",Driver "<<count+1<<endl;
            cout<<"Enter New Driver's Name:- ";
            cin>>D_info[count].name;
           	 cout<<"Enter New Driver's Phone:-# ";
            cin>>D_info[count].phone;
             cout<<"Enter New Driver's Address:- ";
            cin>>D_info[count].address;
             cout<<"Enter New Driver's ID:-# ";
            cin>>D_info[count].id;
            cout<<"Enter New Truck Model:- ";
            cin>>D_info[count].truckmodel;
            cout<<"Enter New truck Number:-# ";
            cin>>D_info[count].truckno;
             cout<<"From:- ";
            cin>>D_info[count].from;
             cout<<"\tTo:- ";
            cin>>D_info[count].to;
			}

        }

	else
	{
		cout<<"\n\t***Sorry,Your Search not found!!***\n";
	}

}

void Record::sort()
{

						// using a friend function, with an object variable of the parent class
 						//  simply re-arranging the data by using the object 'temp' as the temporary for the data
						// untill successfully arranged

	int r;	// this one is to hold the comparison process, since we are comparing 'char' datatypes

	for(int i=0; i<a; i++)
        {
                for(int j=i+1; j<a; j++)
                {
                        int r = strcmp(D_info[i].name,D_info[j].name);
                        if(r>0)	// as long as the data is greater than 0, which means 1 that is correct, then it works
                        {
                                *Dmenu=D_info[i];
                                D_info[i]=D_info[j];
                                D_info[j]=*Dmenu;
                        }
                    }
            }
           cout<<"\n\n\t\t**Successfully Sorted!!!**\n";
}


void Record::deleted()
{

	/*
	*
	*	Ironically, you can't simply delete data in c++, but you can use a trick
	*	the trick is to re-arrange the array of data entered so the c++ program assumes that the data eneterd
	*	was deleted, though it is still exisiting
	*/

	int d,l;

	l=a; // look the comment below

// the global variable 'a' which takes care of data looping inside the objects created
// is now assigned to a new local variable calls 'l'.

	system("cls");

	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@      DELETE       @\n";
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";
	
	cout<<"\n\n\t\tEnter an Id to delete the record!\n";
	cout<<"\t\t\t#";

	cin>>d;



	for(int i=0;i<l;i++)
	{ // two for loops, the outer is for searching, and the other one is for re-arranging

		if(D_info[i].id==d)
		{

			for(int j=i;j<(l-1);j++)
			{ 						// the inner loop's job is to push the deleted data one data to the front
									  // while also subtracting one position for the data that was after the deleted one
									  // the user will not figure this trick, since in the display function,
									  // it updates the data entred by subtracting one and send it using the variable 'a'
				D_info[j]=D_info[j+1];
			}
			
			a=a-1; // re-arranging by putting the data that is after the deleted data a one position back
		count++;
		break;
	}
}

	if(count==0)
	{
	cout<<"no Record found!\n";
	}

	cout<<"**Successfully Deleted!!!**\n";

}


Record::~Record()
{
	delete pass;  // deleting the allocated memory for the password variable
}

		/*********************************************************************
		****** CHILD CLASS USED IN THIS PROGRAM NAMED Client*************
		*********************************************************************/

class Client:public Record // inheritance occurance
{
	private:
		
		int c;
		char product_name[15],product_weight[10], product_type[10];
		
    public:

		void account();
		void login(int *p);
		void client_info();
		friend void client_display(Client);// friend function used for displaying client info
		~Client()
			{
				delete pin;
				delete p; // eventually, if nothing worked, then the allocated memory for 'pin' is deleted
			}
}*Cl=new Client(),Info;


void Client::account()
		{
			home:
			system("cls");

			cout<<"\n\n\t\t\t#Create Account#\n"
				"\t\t\t1,Sign up\n"
				"\t\t\t2,Login\n"
				"\t\t\t\tSelect your option:- ";
			cin>>c;
			if(c==1)
			{ // FIRST OPTION, simply creating an account using simple requierments
				system("cls");

			    cout<<"\n\n\t\t\tEnter your Phone:-# ";cin>>Info.phone;

		again: // a lable used for the pin entrance

		cout<<"\t\t\tEnter your Pin:-# ";

					try{ // an exception handler
						cin>>*pin;

						if(*pin==0000)
						{
							goto proceed;
						}

						if(*pin<1000 || *pin>9999)
						{ // if the pin is not a four digit number, then it throws a 'catch'
							throw 0;
						}

						}catch(...)
						{
							cout<<"\t!?ERROR,please Enter only a four digit number as a Pin!!\n";
							goto again; // if the user entered any wrong data, then it goes back all again
						}
						proceed:

				cout<<"\n\t**CONGRATULATION!YOUR ACCOUNT HAS BEEN CREATED!!**\n";
				system("pause");
					goto home;

			}

		else if(c==2)
			{
				system("cls");
				cout<<"\n\n\t\tEnter your Pin to continue:-";
				cout<<"#";cin>>*p;
				login(p);
			}
		else{
			cout<<"\n\t\tIncorrect choice!!,press any key\n";
			getch();
			goto home;
		}
	}

void Client::login(int *p){

		if(*pin==*p)
	{

			do{
				system("cls");

		    cout<<"\n\n\t\t->Your Menu<-\n"
       				"\t\t\t1,Fill Your Info\n"
       				"\t\t\t2,Driver's List\n"
       				"\t\t\t3,Search Drivers\n"
       				"\t\t\t4,Home\n"

       				"\t\t\t\t\tSelect Your Choice:- ";
			        cin>>c;

   					switch(c)
					   {
				case 1:
					Cl->client_info();
					break;
			    case 2:

   			 		system("cls");

			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
			cout<<"\t\t\t@      DISPLAY      @\n";
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";


				cout<<"\n\n\t\t\tDriver's Details:\n";
				
			for(count=0;count<a;count++)
			{
			  		D_info[count].D_display();
			  	}
			  		cout<<"\n\t:-Which Driver's Info will You Choice?\n";
			  		cout<<"\tPlease, Enter Drivers' Id Number:-# ";cin>>D;
			  		cout<<"# Your Choice Has been Transfered, We will Call You Soon!! #"<<endl;
       			 break;

				case 3:

			  		Dmenu->search();
				  break;

				case 4:

			  	 main();
				  break;

			}

			cout<<"\nto return press R key or 'h' to return to home\n";
				  cin>>retu;

				  if(retu=='H' || retu=='h')
				  {
				  	main();
				  }

			}while(retu=='R'|| retu=='r');
	}

	else {
		cout<<"\n\n\t\tPlease, Enter The Correct PIN!,if you don't have one Signup now!\n"
		"press any key";
		getch();
	account();
	}
}


void Client::client_info()
{
	system("cls");
	
		No=1;
		
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@ Enter Your Info   @\n";
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";
	cout<<"\t\tEnter Your Name:- ";cin>>Info.name;cout<<endl;
	cout<<"\t\tEnter Your Address:- ";cin>>Info.address;cout<<endl;
	cout<<"\t\tEnter Product Name:- ";cin>>Info.product_name;cout<<endl;
	cout<<"\t\tEnter Product Weight:- ";cin>>Info.product_weight;cout<<endl;
	cout<<"\t\tEnter Product Type:- ";cin>>Info.product_type;cout<<endl;
}

void client_display(Client fr){
			
	system("cls");
	
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
	cout<<"\t\t\t@    Client Info    @\n";
	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";
cout<<"\t#############################################\n\n";
	cout<<"\t# Name: "<<fr.name<<endl
	<<"\t# Phone Number: "<<fr.phone<<endl
	<<"\t# Address: "<<fr.address<<endl;
	cout<<"\t# Product Name: "<<fr.product_name<<endl
	<<"\t# Product Weight: "<<fr.product_weight<<endl
	<<"\t# Product Type: "<<fr.product_type<<endl;
cout<<"\t#############################################\n\n";
			
}


		/**********************************
		****** MAIN FUNCTION *************
		**********************************/
int main()
{

	int cho;
	Dmenu=new Record();

	Client M;
	home:

    	system("cls");

		ourinfo();

		system("cls");

	cout<<"\n\n\t\t\t->Who Are You<-\n\n"
			"\t\t\t1,Admin\n"
			"\t\t\t2,Client\n"
			"\t\t\t3,Exit\n\n";

		cout<<"\t\t\t\tSelect:-";
		cin>>cho;

	if(cho==1)
	{
		system("cls");
		for (int i=4;i>0;i--)
				{
			cout<<"\n\tPlease, Enter The Password?\n";
       				cout<<"\t#";cin>>*pass;
       				
		if(*pass==12345)
		{

			do {
				dhome: system("cls");
            Dmenu->Driver_option();
			cin>>cho;

		switch(cho)
		{

   			 case 1:

   			 	system("cls");
   			 	cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
			cout<<"\t\t\t@      REGISTARER   @\n";
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";

		cout << "\n\t\tHow Many Drivers You Want To Register?\n" ;
							cout<<"\t\t\t#";cin>>cho;
   			 	D_info[count].get_Dinfo(cho);
			  	break;

			case 2:
			  		system("cls");

			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n";
			cout<<"\t\t\t@      DISPLAY      @\n";
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@\n\n";

			cout<<"There "<<a<<" Drivers In The Database!\n";
        cout<<"\n\n\t\t\tDriver's Details:\n";
			for(count=0;count<a;count++){
			  		D_info[count].D_display();
			  	}
			  		break;

			case 3:

				  	system("cls");

			  	Dmenu->search();
				 break;

			case 4:

				  	system("cls");

			  	  Dmenu->D_modify();
				  break;

			case 5:
				system("cls");
				Dmenu->sort();

				break;

			case 6:
			    	system("cls");
			    	
			    	if(No==1)
					{
			    			client_display(Info);
				cout<<"\t->This Customer Choice The Driver with ID "<<D<<".\n";
					}
					
			   else{
			   	cout<<"\n\n\t\t->No Customers Info yet!!\n\n";
			   }
						
				break;

			case 7:
				system("cls");
			  Dmenu->deleted();
				break;
			case 8:
				goto home;
				break;
			default:
				cout<<"->Incorrect Choice,Try Again!\n";
				break;

				  }

				cout<<"\nTo Return back press R key or 'h' to return to home\n";
				  cin>>retu;
				  if(retu=='h')
				  {
				  	goto home;
				  }

			}while(retu=='R'|| retu=='r');

}

	else{
		cout<<"You Have "<<i-1<<" Chances!\n";

			if(i==0)

			{

			exit(0);

			}
	    }
 	}
}

	else if(cho==2)
	{

		system("cls");
		Cl->account();


}


	else if(cho==3)
	{
			exit(0);
	}

	else
	{
		cout<<"\n!!!Incorrect Choice!!!\n";
		cout<<"Press H to return:-";
		cin>>retu;
		if(retu=='h'|| retu=='H')
		{
			goto home;
		}
	}

	delete Dmenu;
	delete Cl;

	getch();
    return 0;

}

void ourinfo()
{
	cout<<"\n";
	system("color 80");

			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
			cout<<"\t\t\t@ 	WELCOME          @\n";
			cout<<"\t\t\t@      	  TO 	 	 @\n";
			cout<<"\t\t\t@      ADDIS TRUCK       @\n";
			cout<<"\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@\n\n\n";

			cout<<"\t#Admin password is 12345#\n\n";

			cout<<"\t\tGROUP MEMBERS\n"
				"\tName:-\t\t\t\t\tID:-\n"

				"\t1,Natnael Abebaw\t\t\t18/11,726\n"
				"\t2,Nabil Mohammed\t\t\t18/11,763\n"
				"\t3,Abel Gizachew\t\t\t\t18/11,746\n"
				"\t4,Minilik Seyoum\t\t\t18/11,722\n"
				"\t5,Birhan Tsegaye\t\t\t18/11,708\n"
				"\t6,Natnael Alemzewd\t\t\t18/11,796\n"
				"\t7,Mubarek Getachew\t\t\t18/11,793\n"
				"\t8,Nebyu Gizaw\t\t\t\t18/##\n"
				"\t9,Sufyan Mohammed\t\t\t18/11,736\n"
				"\t10,Yegnasew Inbiale\t\t\t19/1427\n";
		cin.get();
}
