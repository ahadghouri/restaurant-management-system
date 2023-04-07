#include<iostream>
#include<fstream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <algorithm>
using namespace std;

class RR{
	public:
		int vm();
		int cm();
		int review();
		int rmenu();
		void vieworderhistory();
};

int RR::rmenu()
{
	char choice;
	system("cls");
	cout<<"Welcome to Restaurant Representative Menu. Please select a menu item.\n";
	cout<<"1.View menu\n2.Change Menu\n3.View Complaints\n4.View Order History";
    cout<<"\n\nPress 0 to go to main menu.\n";
    fflush(stdin);
	cin>>choice;
/*	do
            {
		        cin>>choice;
		        if(choice<'0' || choice>'4')
		        {
			        cout<<"Incorrect option! Select again: ";
		        }
		        else
		        {
			        break;
		        }
	        }
	while(1);*/
	system("cls");
	switch(choice)
	{
		case '1':
			{
				vm();
				break;
			}
		case '2':
			{
				cm();
				break;
			}
		case '3':
			{
				review();
				break;
			}
		case '4':
		    {
			    vieworderhistory();
			    break;
			}
		case '0':
		    {
			    break;
			}
		default:
		    {
			    cout<<"Incorrect option!";
			    break;
			}	
	}
}
int RR::vm()
{
	char fileName[30], ch, k3;
	fstream fp;
	fflush(stdin);
	cout<<"Enter the Name of File: ";
	cin>>fileName;
	fp.open(fileName, fstream::in);
	if(!fp)
	{
    	cout<<"\nError Occurred!";
		exit(0);
	}
	cout<<"\nContent of "<<fileName<<":-\n";
	while(fp>>noskipws>>ch)
		cout<<ch;
		fp.close();
		cout<<endl;
		cout<<"\n\nPress any key to got back\n";
		cin>>k3;
		rmenu();
}
 
int RR::cm()
{
 	string data,newdata,word, rep; // for user input
 	char k4;
	
      fstream fin;
      char fileName[30], ch;

	cout<<"Enter the Name of File: ";
	cin>>fileName;
      cout<<"Enter Menu item to change: ";
      fflush(stdin);
      cin>>word;
      cout<<"\nEnter new menu item: ";
      fflush(stdin);
      cin>>rep;
      cout<<"*Old Menu\n";
      fin.open(fileName,ios::in);
      if(!fin)
      {
           cout<<"error opening file";
           exit(0);
      }
      while(fin)
      {
           getline(fin,data);
           cout<<data<<endl;
      }
      fin.close();
      fin.open(fileName,ios::in);
 //     newdata="";
      if(!fin)
      {
           cout << "Unable to open file";
           exit(1);
      }
      while(fin)
      {
           getline(fin,data);
           int a =(int) data.find(word,0);
           while (a != string::npos)
           {
                data.replace(a,500,rep);
                a =(int) data.find(word,(a+1));
           }
           newdata=newdata+data+"\n";
      }
      fin.close();
      fin.open(fileName,ios::out);
      if(!fin)
      {
           cout<<"error opening file";
            exit(0);
      }
      fin<<newdata;
      cout<<"Replacement successful\n";
      fin.close();
      cout<<"*New Menu*\n";
      fin.open(fileName,ios::in);
      if(!fin)
      {
           cout<<"error opening file";
           exit(0);
      }
      while(fin)
      {
           getline(fin,data);
           cout<<data<<endl;
      }
      fin.close();
    cout<<"\n\nPress any key to go back\n";
	cin>>k4;
	rmenu();
      
}
int RR::review()
{
	char ch, k5;
	fstream fp;
	
	fp.open("complaints.txt", fstream::in);
	if(!fp)
	{
    	cout<<"\nError Occurred!";
		exit(0);
	}
	cout<<"\nReviews: "<<"\n";
	while(fp>>noskipws>>ch)
		cout<<ch;
		fp.close();
		cout<<endl;
		cout<<"\n\nPress any key to got back\n";
		cin>>k5;
		rmenu();
}
void RR::vieworderhistory()
{
	char ch2, k6;
	fstream fp2;
	
	fp2.open("orderhistory.txt", fstream::in);
	if(!fp2)
	{
    	cout<<"\nError Occurred!";
    	exit(0);
	}
	cout<<"\nOrder History: "<<"\n";
	while(fp2>>noskipws>>ch2)
		cout<<ch2;
		fp2.close();
		cout<<endl;
		cout<<"\n\nPress any key to got back\n";
		cin>>k6;
		rmenu();
}

class complaints
{
	private:
		
		fstream file1;
		char comp[100], name[100], email[100];
		char k;
	public:
		
		void work()
		{
		    system("cls");
		    file1.open("complaints.txt", ios::app);
	        if(!file1)
	        {
		        cout<<"Error!";
		        exit(0);
	        }
	        else
	        {
		        cout<<" ----------------------------------------------\n";
                cout<<"|                                              |\n";
                cout<<"|                   Complain                   |\n";
                cout<<"|                                              |\n";
                cout<<" ----------------------------------------------\n";
    
	            cout<<"This is our complaint center. We are extremely sorry you faced a problem with our services, however we assure you we will do everything to resolve your complain. Please fill the form below.\n";
	            cout<<"\nPlease enter your name: ";
	            cin>>name;
	            cout<<"\nPlease enter your email: ";
	            cin>>email;
	            cout<<"\nPlease describe your complain: ";
	            cin>>comp;
	            
	            fflush(stdin);
		        file1<<"Name: "<<name<<endl<<"Email: "<<email<<endl<<"Complaint: "<<comp<<endl<<endl<<endl;
		        file1.close();
		        cout<<"\n\nWe have recieved your complain. We will contact you regarding your issue shortly.\n\n";
		        cout<<"Press any key to go to main menu.\n";
		        cin>>k;
	        }
		}
};

class FAQ
{
	public:
		char k1, select;
		void work()
		{			
			system("cls");
	        cout<<endl<<endl<<endl;
	        cout<<"Please select one of the following options: \n\n\n";
	        cout<<"1. Can I place an order for someone else?\n\n";
	        cout<<"2. Will my meals be labelled?\n\n";
	        cout<<"3. What is the expected delivery time?\n\n";
	        cout<<"4. What are your delivery timings?\n\n";
	        cout<<"5. Is there a minimum order value?\n\n\n";
	        cout<<"Press 0 to go to main menu.\n";
	        cout<<"Enter your choice: ";
	        fflush(stdin);
	        do
	        {
		        cin>>select;
		        if(select<'0' || select>'5')
		        {
			        fflush(stdin);
			        cout<<"\nIncorrect option! Select again: ";
		        }
		        else
		        {
			        break;
		        }
	        }
	        while(1);
	        cout<<endl<<endl;
	        
	        switch(select)
	        {
	        	case '1':
	        		{
	        			system("cls");
		                cout<<"Yes. During checkout, just update the name and delivery address of the person you're ordering for.\n\n";
		                cout<<"\n\nPress any key to go back.\n";
		                cin>>k1;
		                FAQ::work();
		                break;
					}
				case '2':
					{
						system("cls");
		                cout<<"You can request that your meals be labeled in `special instructions`. However, depending on the restaurant and how busy they are, they might not be able to carry out your request. If you want your meals labeled for allergy reasons, specify this in your instructions.";
		                cout<<"\n\nPress any key to go back.\n";
		                cin>>k1;
		                FAQ::work();
		                break;
					}
				case '3':
					{
						system("cls");
		                cout<<"We try to deliver your food as quickly as possible. We can usually deliver between 30 and 60 minutes from when you place your order.";
		                cout<<"\n\nPress any key to go back.\n";
		                cin>>k1;
		                FAQ::work();
		                break;
					}
				case '4':
					{
						system("cls");
		                cout<<"9am to 2am.";
		                cout<<"\n\nPress any key to go back.\n";
		                cin>>k1;
		                FAQ::work();
		                break;
					}
				case '5':
					{
						system("cls");
		                cout<<"No.";
		                cout<<"\n\nPress any key to go back.\n";
		                cin>>k1;
		                FAQ::work();
		                break;
					}
				case '0':
					{
						break;
					}
					
			}
		}
		
};

class aboutus
{
	public:
		void work()
		{
			system("cls");
	        cout<<"THIS PROJECT IS MADE BY: \n\n";
	        cout<<"      Muhammad Abdul Ahad Ghouri\n\n";
	        cout<<"      Umer Iqbal\n\n";
	        cout<<"      Danish Fakih\n\n\n";
	        cout<<"Press any key to go to main menu.\n";
		}
};

class orderplacement
{
	public:

		void work()
		{
			int x , y , z , s1=0 , s2=0 , ts=0 , s3=0 , ts2=0 , wait , nb , i , r1=0 , r2=0;
			char end , close , key , ch2 , k6 , ch3 , k7;
			ofstream fp , fp1 , fp2;
			fstream fp3 , fp4;
			fp.open("orderhistory.txt" , ios::app);
			char str[1000] = "YOUR ORDER:- \n";
			fp.write((char*)&str, sizeof(str));
			
			
			do
			{ 
				cout<<"1. RESTAURANT A.\n";
            	cout<<"2. RESTAURANT B.\n";
	            cout<<"\n\n\n";
	            cout<<"ENTER RESTAURANT NUMBER: ";
	            cin>>x;
	            cout<<("\n\n\n");
	            if(x == 1) // x represent the number assigned to restaurants. 
	{ 
		system("cls");
//		for(wait=0;wait<=50000;wait++)
//	{
//		cout<<"\rIn progress : "<<wait/500;
//	}
	system("cls");
	do // After selecting an item, this loops brings you back here to order another item if you like.
	{ 	
	cout<<"\nMENU\n";
//	cout<<"1. Item no. 1        Rs. 500\n2. Item no. 2        Rs. 100"; // viewing menu A
    fp3.open("menua.txt", fstream::in);
	if(!fp3)
	{
    	cout<<"\nError Occurred!";
    	exit(0);
	}
	cout<<"\nRESTAURANT A MENU: \n"<<"\n";
	while(fp3>>noskipws>>ch2)
		cout<<ch2;
		fp3.close();
		cout<<endl;
	fflush(stdin);
	cout<<"\nSelect item number please: ";
	cin>>y;
	
		if(y <= 2) // y represent the number assigned to items, as to understand which item does the user select.
	{ 
	cout<<"Quantity of item required: ";
	cin>>z;
	}
		else
	{ 
		cout<<"\n";
	}
	if(y==1)
	{ 
		s1 = 500 * z; // z represent the quantity of items required.
		cout<<"sum = "<<s1<<endl;
		char str[] = "\nRESTAURANT 1 : ITEM NO. 1 ";
		fp.write((char*)&str, sizeof(str));
		fp<<"\nQuantity = "<<z<<endl;
		fp<<"\nBill = "<<s1<<endl;
//		fp.close();
		s1 = s1;
    }
		else if(y==2) // y represent the number assigned to items, as to understand which item does the user select.
	{ 
		s2 = 100 * z;
		cout<<"sum = "<<s2<<endl;
		char str[] = "\nRESTAURANT 1 : ITEM NO. 2 ";
		fp.write((char*)&str, sizeof(str));
		fp<<"\nQuantity = "<<z<<endl;
		fp<<"\nBill = "<<s2<<endl;
//	    fp.close();
		s2 = s2;
	}
	else 
	{
		cout<<"item not available.\n";
	}
	ts = s1 + s2; // s1, s2 = amount when price is multiplied by quantity of product
	cout<<"press 'y' to check out or press any other letter to continue placing your order: \n";
	cin>>end; // if Y is pressed, the program will proceed to check out, otherwise, the program will take you back to select another item.
}
	 while(end != 'y');
    system("cls");
    cout<<"total sum = "<<ts<<endl;
    }
    else if(x == 2) // x represent the number assigned to restaurants. 
    {
    	system("cls");
//    for(wait=0;wait<=50000;wait++)
//	{
//		cout<<"\rIn progress : "<<wait/500;
//	}
	system("cls");
    do // After selecting an item, this loops brings you back here to order another item if you like.
	{
	cout<<"MENU\n";
//	cout<<"1. Item no. 1        Rs. 5000\n2. Item no. 2        Rs. 2000"; // viewing menu B

    fp4.open("menub.txt", fstream::in);
	if(!fp4)
	{
    	cout<<"\nError Occurred!";
    	exit(0);
	}
	cout<<"\nRESTAURANT B MENU: "<<"\n";
	while(fp4>>noskipws>>ch3)
		cout<<ch3;
		fp4.close();
		cout<<endl;


	fflush(stdin);
	cout<<"\nSelect item number please: ";
	cin>>y;
	if (y <= 2) // y represent the number assigned to items, as to understand which item does the user select.
	{
	cout<<"Quantity of item required: ";
	cin>>z;
	}
	else
	{
		cout<<"\n";
	}
	if(y==1) // y represent the number assigned to items, as to understand which item does the user select.
	{
		s1 = 5000 * z; // z represent the quantity of items required.
		cout<<"sum = "<<s1<<endl;
		char str[] = "\nRESTAURANT 2 : ITEM NO. 1 ";
		
		fp.write((char*)&str, sizeof(str));
		fp<<"\nQuantity = "<<z<<endl;
		fp<<"\nBill = "<<s1<<endl;
	}
		else if(y==2) // y represent the number assigned to items, as to understand which item does the user select.
	{
		s3 = 2000 * z;
		cout<<"sum = "<<s3<<endl;
		char str[] = "\nRESTAURANT 2 : ITEM NO. 2 ";
		fp.write((char*)&str, sizeof(str));
		fp<<"\nQuantity = "<<z<<endl;
		fp<<"\nBill = "<<s3<<endl;
//		fp.close();
		s3=s3;
    }
    else 
	{
		cout<<"item not available.\n";
	}
	ts2 = s1 + s3; // s1, s3 = amount when price is multiplied by quantity of product
	cout<<"press 'y' to check out or press any other letter to continue placing your order: \n";
	cin>>end;  // if Y is pressed, the program will proceed to check out, otherwise, the program will take you back to select another item.
    }
    while(end != 'y');
    cout<<"total sum = "<<ts2;
    
    }	
    else 
    {
    	cout<<"ERROR.\n";
	} 
	cout<<"\npress 'c' to close program or press any other letter to choose another restaurant."; 
    cin>>close; // if C key is pressed, the program will be closed and a final bill will be generated, otherwise, the user will be given the option to order from another restaurant or re-order from the same place.
}
	while(close != 'c');
	nb = ts + ts2; //  ts = total sum for first restaurant , ts2 = total sum for 2nd restaurant , nb = net bill
	for(i=0 ; i<5 ; i++)
	{
		cout<<"\n";
	}
	system("cls");

	cout<<"your total bill is "<<nb<<endl;// displaying total bill
	cout<<"YOUR ORDER HAS BEEN PLACED.\n";
	cout<<"THANKS FOR USING OUR PROGRAM. GIVE US A REVIEW, SUGGESTION OR FILE ANY COMPLAINT IN OUR COMPLAINT BOX.";
	fp.close();
	
	
	fp1.open("revenueA.txt", ios::app);//revenue of restaurant A will be updated in this file
	if(fp1 == NULL)
	{
		char str[] = "error file empty:( ";
		fp1.write((char*)&str, sizeof(str));

        fp1.close();
        }
	else
	{
		r1+=ts;
		char str[] = "\nThe revenue for restaurant A is as following:\n ";
		fp1.write((char*)&str, sizeof(str));
		fp1<<""<<r1<<endl;
		fp1.close();
    }
    fp2.open("revenueB.txt", ios::app);//revenue of restaurant B will be updated in this file
	if(fp2 == NULL)
	{
		char str[] = "file empty ;) ";
		fp2.write((char*)&str, sizeof(str));
//		fcout<<(fp, "%d", ts2);
		fp2.close();
	}
	else
	{
		r2+=ts2;
		char str[] = "\nThe revenue for restaurant B is as following:\n ";
		fp2.write((char*)&str, sizeof(str));
		fp2<<""<<r2<<endl;
		fp2.close();
	}
			
	
	//getch();
	cout<<"\n\nPress any key to go back to main menu.\n";
	cin>>key;
	}
	

};

class mainmenu: public orderplacement, public aboutus, public complaints, public FAQ, public RR
{
	private:
		char choice;
	    char key;
	    int result;
	    char password[100];
	public:
			
		void menu()
		{
			system("cls");
	        cout<<"               ----------------------------------------------\n";
	        cout<<"                                  WELCOME!\n";
	        cout<<"               ----------------------------------------------\n\n\n";
	        cout<<"Please select one of the following options: \n\n\n";
	        cout<<"      1. Order Placement\n\n";
	        cout<<"      2. Restaurant Admin\n\n";
	        cout<<"      3. FAQ\n\n";
	        cout<<"      4. Complaints\n\n";
	        cout<<"      5. About us\n\n";
	        cout<<"      6. Exit\n\n\n";
	        cout<<"Enter your choice: ";
	        
	        do
            {
		        cin>>choice;
		        if(choice<'1' || choice>'6')
		        {
			        cout<<"Incorrect option! Select again: ";
		        }
		        else
		        {
			        break;
		        }
	        }
	        while(1);//In this loop, we are making sure user only inputs number from 1-6.
	        
	        switch(choice)
	{
		case '1':
			{
				system("cls");
				//friend void orderplacement::order();
				orderplacement::work();
				menu();
				break;
			}
		case '2':
			{
					system("cls");
					fflush(stdin);
	                cout<<"Enter password: ";
	                gets(password);
	                result = strcmp(password, "ooplab2021");// Comparing password entered by the user to the correct password.
	
	                do
	                {
		                if(result == 0)
		                {
			                break;
		                }
		                else
		                {
			                cout<<"Password incorrect. Press any key to go back to the main menu.\n";
			                cin>>key;
			                menu();
			                break;
		                }
	                }
	                while(1);// if the user enters a wrong password, this loop will taken him back to the main menu.
				    RR::rmenu();
				    menu();
				    break;
			}
		case '3':
			{
				FAQ::work();
				menu();
				break;
			}
		case '4':
			{
				system("cls");
				complaints::work();
				menu();
				break;
			}
		case '5':
			{
				system("cls");
				aboutus::work();
				cin>>key;
				menu();
				break;
			}
		case '6':
			{
				exit(0);
				break;
			}
		default:
			{
				printf("Incorrect option!");
				break;
			}
	}
	
		}
		
};

int main()
{
	mainmenu mm;

	mm.menu();
}
