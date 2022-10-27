#include<iostream>
#include <ctime>
#include<fstream>
#include<istream>
#include<stdlib.h>
#include<cctype>
#include <cstring>
#include<iomanip>
using namespace std;

/*
         INFORMATION ABOUT PROJECT
PROJECT NAME     : BANK ACCOUNT MANAGEMENT SYSTEM
CREATED BY       : MD SHAFIKUL ISLAM
LANGUAGE         : C++
DATE OF CREATION : 22/10/2022
PLATFORM         : WINDOWS
TESTED ON        : WINDOWS 10
ABOUT PROJECT    : Bank Account Management System is a application that helps to keep track of all the customer records .
*/


//----------------------------CLASS FOR Bank-Account ---------------------------
class Bank_Account
{

	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:

	void report() const;
	int retMoney_Deposit() const;
	void create_Bank_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};

int main();
void Bank_Account::Updation()
{
	cout<<"\n\t Bank Account No. : "<<acno;
	cout<<"\n\t Updating Bank Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t Updating Type of Bank Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t Updation Balance Total-Money : ";
	cin>>Money_Deposit;
}
void Bank_Account::create_Bank_Account()
{
	system("CLS");
	cout<<"\n\t Please Enter the Bank Account No. : ";
	cin>>acno;
	cout<<"\n\n\t Please Enter the Name of the Bank Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t Please Enter Type of the Bank Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tPlease Enter The Starting Total-Money : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tBank Account Created..";
}

void Bank_Account::Display_Account() const
{
	cout<<"\n\t Bank Account No. : "<<acno;
	cout<<"\n\t Bank Account Holder Name : ";
	cout<<name;
	cout<<"\n\t Type of Bank Account : "<<type;
	cout<<"\n\t Balance Total-Money : "<<Money_Deposit;
}
int Bank_Account::retacno() const
{
	return acno;
}



char Bank_Account::rettype() const
{
	return type;
}
void Bank_Account::report() const
{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<Money_Deposit<<endl;
}
void Bank_Account::dep(int x)
{
	Money_Deposit+=x;
}
void Bank_Account::draw(int x)
{
	Money_Deposit-=x;
}
int Bank_Account::retMoney_Deposit() const
{
	return Money_Deposit;
}

//-----------------------Functions for Bank Management------------------------
void write_Bank_Account();
void display_sp(int);
void display_all();

void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updating_Bank_Account(int);

//------------------------------login functions-------------------------------
void login()
{
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;

        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)

                {
                        count=1;
                        //system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHello"<<user<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                //cin.get();
                //cin.get();
                //main();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";
                main();
        }
}
void forgot()
{
        int ch;
        system("cls");
        cout<<"Forgotten ? We're here for help\n";
        cout<<"1.Search your id by username"<<endl;
        cout<<"2.Search your id by password"<<endl;
        cout<<"3.Main menu"<<endl;
        cout<<"Enter your choice :";
        cin>>ch;
        switch(ch)
        {
                case 1:
                {
                        int count=0;
                        string searchuser,su,sp;
                        cout<<"\nEnter your remembered username :";
                        cin>>searchuser;

                        ifstream searchu("database.txt");
                        while(searchu>>su>>sp)
                        {
                                if(su==searchuser)
                                {
                                        count=1;
                                }
                        }
                        searchu.close();
                        if(count==1)
                        {
                                cout<<"\n\nHurray, account found\n";
                                cout<<"\nYour password is "<<sp;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"\nSorry, Your userID is not found in our database\n";
                                cout<<"\nPlease kindly contact your system administrator for more details \n";
                                cin.get();
                                cin.get();
                                main();
                        }
                        break;
                }
                case 2:
                {
                        int count=0;
                        string searchpass,su2,sp2;
                        cout<<"\nEnter the remembered password :";
                        cin>>searchpass;

                        ifstream searchp("database.txt");
                        while(searchp>>su2>>sp2)
                        {
                                if(sp2==searchpass)
                                {
                                        count=1;
                                }
                        }
                        searchp.close();
                        if(count==1)
                        {
                                cout<<"\nYour password is found in the database \n";
                                cout<<"\nYour Id is : "<<su2;
                                cin.get();
                                cin.get();
                                system("cls");
                                main();
                        }
                        else
                        {
                                cout<<"Sorry, We cannot found your password in our database \n";
                                cout<<"\nkindly contact your administrator for more information\n";
                                cin.get();
                                cin.get();
                                main();
                        }

                        break;
                }

                case 3:
                {
                        cin.get();
                        main();
                }
                default:
                        cout<<"Sorry, You entered wrong choice. Kindly try again"<<endl;
                        forgot();
        }
}

void registr()
{

        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;

        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        main();


}


//main function start
main()
{

	char ch;
	int num;

	//add

	int choice;
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "\n\t The Local Date and Time is: " << dt << endl;
        cout<<"\n\t                    BANK ACCOUNT MANAGEMENT SYSTEM                      \n\n";
        cout<<"\t***********************************************************************\n\n";
        cout<<"\t                      Welcome to login page                               \n\n";
        cout<<"\t******************        MENU        ********************************\n\n";
        cout<<"1.LOGIN\n";
        cout<<"2.REGISTER\n";
        cout<<"3.FORGOT PASSWORD (or) USERNAME\n";
        cout<<"4.Exit\n";
        cout<<"\nEnter your choice : ";
        cin >> choice;
        cout<<endl;

        switch(choice)
        {       system("CLS");
                case 1:
                        login();
                        break;
                case 2:
                        registr();
                        break;
                case 3:
                        forgot();
                        break;
                case 4:

                        cout<<"Thanks for using this program\nThis program is created by @Thestral9\n\n";
                        break;
                default:
                        system("cls");
                        cout<<"Wrong Choice Intered\n"<<endl;
                        main();
        }


	//end


	do
	{

	system("CLS");
    cout << "\n\t The Local Date and Time is: " << dt << endl;
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

	cout<<"\t\t    BANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;

		cout<<"\t\t     ::MAIN MENU::\n";
		cout<<"\n\t\t1. NEW Bank_Account";
		cout<<"\n\t\t2. Money_Deposit Total-Money";
		cout<<"\n\t\t3. WITHDRAW Total-Money";
		cout<<"\n\t\t4. BALANCE ENQUIRY";
		cout<<"\n\t\t5. ALL Bank_Account HOLDER LIST";
		cout<<"\n\t\t6. CLOSE AN Bank_Account";
		cout<<"\n\t\t7. Updating AN Bank_Account";
		cout<<"\n\t\t8. EXIT";
		cout<<"\n\n\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_Bank_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			delete_Bank_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tPlease Enter The Bank_Account No. : "; cin>>num;
			Updating_Bank_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tBrought To You By code-projects.org";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;

}



void write_Bank_Account()
{
	Bank_Account ac;
	ofstream outFile;
	outFile.open("Bank_Account.dat",ios::binary|ios::app);
	ac.create_Bank_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
	outFile.close();
}
void delete_Bank_Account(int n)
{
	Bank_Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Bank_Account.dat");
	rename("Temp.dat","Bank_Account.dat");
	cout<<"\n\nRecord Deleted ..";
}

void display_sp(int n)
{
	Bank_Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tBank_Account number does not exist";
}


void display_all()
{
	system("CLS");
	Bank_Account ac;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\t Bank_Account HOLDER LIST\n\n";
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	cout<<"\t\t A/c no.      NAME           Type  Balance\n";
	cout<<"\t!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
	    cout<<"\t\t";
		ac.report();
        cout<<"\t---------------------------------------------------------------\n";
	}
	inFile.close();
}
void Updating_Bank_Account(int n)
{
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			cout<<"\n\n\tPlease Enter The New Details of Bank_Account"<<endl;
			ac.Updation();
			int pos=(-1)*static_cast<int>(sizeof(Bank_Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		    cout<<"\n\n\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}

void Money_Deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			if(option==1)
			{
				cout<<"\n\n\tTO Money_DepositSS Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be Money_Deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW Total-Money";
				cout<<"\n\n\tPlease Enter The Total-Money to be withdraw: ";
				cin>>amt;
				int bal=ac.retMoney_Deposit()-amt;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
			cout<<"\n\n\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord Not Found ";
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
