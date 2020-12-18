#include<iostream>
#include<windows.h>
#include<fstream>

void createac();
void cashin();
void cashout();
void sendmoney();
void buyair();
void checkblnc();
void deleteac();
void editpin();
void logo();
void loading();

using namespace std;

int main()
{
    int select;
    logo();
    //loading();
    do
        {
		system("cls");
		cout<<"\n\t\t     *** Bkash System ***          \n\n";
		cout<<"\n\t\t\t\t\tMain Menu";
		cout<<"\n\n\t      => Type (1) to Create Account.";
		cout<<"\n\n\t\t => Type (2) to Cash in.";
		cout<<"\n\n\t\t     => Type (3) to Cash out.";
		cout<<"\n\n\t\t       => Type (4) to Send money.";
		cout<<"\n\n\t\t          => Type (5) to Buy Airtime.";
		cout<<"\n\n\t\t        => Type (6) to Check Balance.";
		cout<<"\n\n\t\t     => Type (7) to Delete Account.";
		cout<<"\n\n\t\t  => Type (8) to Change PIN.";
		cout<<"\n\n\t      => Type (0) to Exit.";
        hi:
        cout<<"\n\n\n\t\t\t\t Enter Your selection: ";
		cin>>select;

		switch(select)
		{
		case 1:
		    createac();
			break;
		case 2:
		    cashin();
			break;
		case 3:
		    cashout();
			break;
		case 4:
		    sendmoney();
			break;
        case 5:
            buyair();
            break;
		case 6:
		    checkblnc();
			break;
		case 7:
		    deleteac();
			break;
		 case 8:
            editpin();
			break;
		 case 0:
			cout<<"\n\n\tThanks for using Bkash...\n\n";
			break;
		 default:
		     cout<<"\n\t\t\tInvalid Number...";
		     goto hi;
		}
		cin.ignore();
		cin.get();
    }
    while(select<=9);

	return 0;
}


void createac()
{
    int ac,deposit,pin;
    char name[50];

    ofstream out;
    out.open("acno.txt");
    cout<<"\n\n\tEnter Mobile number : ";
	cin>>ac;
	out<<ac<<" ";

	ofstream out1;
	out1.open("acname.txt");
	cout<<"\n\n\tEnter name :";
	cin.ignore();
	cin.getline(name,50);
	out1<<name<<" ";

	ofstream out2;
	out2.open("acdep.txt");
	cout<<"\n\n\tEnter star up amount : ";
	cin>>deposit;
	out2<<deposit<<" ";

	ofstream out3;
    out3.open("pin.txt");
    cout<<"\n\n\tEnter PIN : ";
	cin>>pin;
	out3<<pin<<" ";

	cout<<"\n\n\tBkash Account Created...";
    cout<<"\n\n\tPress Enter to Return Main Menu ";
}


void cashin()
{
    int ac,ac1,cash,cash2,p,pin;
    ifstream in;
    in.open("acno.txt");
    ifstream in5;
    in5.open("pin.txt");
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    while(!in.eof())
    {
        in>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
            cout<<"\n\tEnter the amount to Cash in : ";
            cin>>cash;

            ifstream in1;
            in1.open("acdep.txt");
            in1>>cash2;

            ofstream out;
            out.open("acdep.txt");
            out<<cash+cash2;
            cout<<"\n\tAmount Added\n\tTotal Amount : "<<cash+cash2;
            cout<<"\n\n\tPress Enter to Return Main Menu ";
            break;
        }
        else
        {
            cout<<"\n\tRecord not Found";
            break;
        }
    }
}


void cashout()
{
    int ac,ac1,acdep,cash,a,b,pin,p;
    char name[50];
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    ifstream in5;
    in5.open("pin.txt");
    ifstream in0;
    in0.open("acno.txt");
    while(!in0.eof())
    {
        in0>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
            ifstream in;
            in.open("acname.txt");
            in.getline(name,50);

            ifstream in1;
            in1.open("acdep.txt");
            in1>>acdep;

            cout<<"\n\tAccount Name : "<<name<<"\n\tAccount number : "<<ac<<"\n\tTotal amount : "<<acdep;
            cout<<"\n\tEnter Agent Number : ";
            cin>>b;
            cout<<"\n\tEnter the amount to Cash out : ";
            cin>>cash;
            if(cash<=acdep)
            {
                a=acdep-cash;
                cout<<"\n\tCash out Successful \n\tTotal Amount : "<<a;

                ofstream out1;
                out1.open("acdep1.txt");
                out1<<a;
                cout<<"\n\n\tPress Enter to Return Main Menu ";
                break;
            }
            else
            {
                cout<<"\n\tInsufficient Balance.\n";
                cout<<"\n\tPress Enter to Return Main Menu ";
                break;
            }
        }
        else
        {
            cout<<"\n\tRecord not Found";
            break;
        }
    }

}

void sendmoney()
{
    int ac,ac1,acdep,cash,a,b,pin,p;
    char name[50];
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    ifstream in5;
    in5.open("pin.txt");
    ifstream in0;
    in0.open("acno.txt");
    while(!in0.eof())
    {
        in0>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
            ifstream in;
            in.open("acname.txt");
            in.getline(name,50);

            ifstream in1;
            in1.open("acdep.txt");
            in1>>acdep;

            cout<<"\n\tAccount Name : "<<name<<"\n\tAccount number : "<<ac<<"\n\tTotal amount : "<<acdep;
            cout<<"\n\tEnter Number where to send : ";
            cin>>b;
            cout<<"\n\tEnter the amount to be send : ";
            cin>>cash;
            if(cash<=acdep)
            {
                a=acdep-cash;
                cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;

                ofstream out1;
                out1.open("acdep1.txt");
                out1<<a;
                cout<<"\n\tPress Enter to Return Main Menu ";
                break;
            }
            else
            {
                cout<<"\n\tInsufficient Balance.\n";
                cout<<"\n\tPress Enter to Return Main Menu ";
                break;
            }
        }
        else
        {
            cout<<"\n\tRecord not Found";
            break;
        }
    }

}


void buyair()
{
    int ac,ac1,acdep,cash,a,n,pin,p,flag=1;
    string b;
    char name[50];
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    ifstream in5;
    in5.open("pin.txt");
    ifstream in0;
    in0.open("acno.txt");
    while(!in0.eof())
    {
        in0>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
            ifstream in1;
            in1.open("acdep.txt");
            in1>>acdep;

            cout<<"\n\tAccount Name : "<<name<<"\n\tAccount number : "<<ac<<"\n\tTotal amount : "<<acdep;
            cout<<"\n\n\t\t => Type 1 for Robi.\n";
            cout<<"\n\t\t    => Type 2 for Airtel.\n";
            cout<<"\n\t\t       => Type 3 for Teletalk.\n";
            cout<<"\n\t\t    => Type 4 for Banglalink.\n";
            cout<<"\n\t\t => Type 5 for Grameenphone.\n\n";
            cout<<"\n\t\t\t Enter Your selection: ";
            cin>>n;
            switch(n)
            {
            case 1:
                cout<<"\n\tEnter Robi number : ";
                cin>>b;
                cout<<"\n\tEnter Amount : ";
                cin>>cash;
                if(cash<=acdep)
                {
                    a=acdep-cash;
                    cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    flag=0;
                    break;
                }
                else
                {
                    cout<<"\n\tInsufficient Balance.\n";
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    break;
                }

                case 2:
                cout<<"\n\tEnter Airtel number : ";
                cin>>b;
                cout<<"\n\tEnter Amount : ";
                cin>>cash;
                if(cash<=acdep)
                {
                    a=acdep-cash;
                    cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    flag=0;
                    break;
                }
                else
                {
                    cout<<"\n\tInsufficient Balance.\n";
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    break;
                }
                case 3:
                cout<<"\n\tEnter Teletalk number : ";
                cin>>b;
                cout<<"\n\tEnter Amount : ";
                cin>>cash;
                if(cash<=acdep)
                {
                    a=acdep-cash;
                    cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    flag=0;
                    break;
                }
                else
                {
                    cout<<"\n\tInsufficient Balance.\n";
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    break;
                }
                case 4:
                cout<<"\n\tEnter Banglalink number : ";
                cin>>b;
                cout<<"\n\tEnter Amount : ";
                cin>>cash;
                if(cash<=acdep)
                {
                    a=acdep-cash;
                    cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    flag=0;
                    break;
                }
                else
                {
                    cout<<"\n\tInsufficient Balance.\n";
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    break;
                }
                case 5:
                cout<<"\n\tEnter Grameenphone number : ";
                cin>>b;
                cout<<"\n\tEnter Amount : ";
                cin>>cash;
                if(cash<=acdep)
                {
                    a=acdep-cash;
                    cout<<"\n\tSuccessfully send. \n\tTotal Amount : "<<a;
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    flag=0;
                    break;
                }
                else
                {
                    cout<<"\n\tInsufficient Balance.\n";
                    cout<<"\n\tPress Enter to Return Main Menu ";
                    break;
                }
            default:
                cout<<"bye";
                }
                if(flag==0)
                    break;
            }
            else
            {
                cout<<"\n\tRecord not Found";
                break;
            }
    }
}


void checkblnc()
{
    int ac,ac1,acdep,cash,a,pin,p;
    char name[50];
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    ifstream in5;
    in5.open("pin.txt");
    ifstream in0;
    in0.open("acno.txt");
    while(!in0.eof())
    {
        in0>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
            ifstream in;
            in.open("acname.txt");
            in.getline(name,50);

            ifstream in1;
            in1.open("acdep.txt");
            in1>>acdep;

            cout<<"\n\n\tAccount Name : "<<name<<"\n\n\tAccount number : "<<ac<<"\n\n\tTotal amount : "<<acdep;
            break;
        }
        else
        {
            cout<<"\n\tRecord not Found";
            break;
        }
    }
}


void deleteac()
{
    int ac,ac1,p,pin;
    cout<<"\n\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\n\tEnter PIN Number : ";
    cin>>pin;
    ifstream in5;
    in5.open("pin.txt");
    ifstream in0;
    in0.open("acno.txt");
    while(!in0.eof())
    {
        in0>>ac1;
        in5>>p;
        if(ac==ac1&&p==pin)
        {
        in0.close();
        in5.close();
        remove("acno.txt");
        remove("acname.txt");
        remove("acdep.txt");
        remove("acdep1.txt");
        remove("pin.txt");
        cout<<"\n\tRecord Deleted ...";
        cout<<"\n\n\tPress Enter To Return Main Menu.";
        break;
        }
        else
        {
            cout<<"\n\n\tRecord not Found";
            break;
        }

    }
}



void editpin()
{
    int ac,p,pin,ac1,p1;
    cout<<"\n\tEnter Account Number : ";
    cin>>ac;
    cout<<"\n\tEnter old PIN : ";
    cin>>p;
    ifstream in;
    in.open("pin.txt");
    ifstream in2;
    in2.open("acno.txt");
    while(!in.eof())
    {
        in>>pin;
        in2>>ac1;
    if(p==pin&&ac==ac1)
    {
        cout<<"\n\tEnter New PIN : ";
        cin>>p1;

        ofstream out;
        out.open("pin.txt");
        out<<p1;
        cout<<"\n\tPress Enter To Return Main Menu.";
        break;
    }
    else
        {
            cout<<"\n\tRecord not Found";
            break;
        }
    }
}


void logo()
{
    cout<<"\n                  _____________            ";
    cout<<"\n                 |____     ____|              ";
    cout<<"\n   !----------!       |   |       !----------!";
    cout<<"\n   !---!  !---!       |   |       !---!  !---!";
    cout<<"\n       !  !    _______|___|_______    !  !       ";
    cout<<"\n       !  !   |   ____     ____   |   !  !       ";
    cout<<"\n       !  !   |__|    |   |    |__|   !  !       ";
    cout<<"\n       !  !           |   |           !  !       ";
    cout<<"\n       !  !      B    |   |     A     !  !       ";
    cout<<"\n       !  !           |   |           !  !       ";
    cout<<"\n       !  !         __|   |__         !  !       ";
    cout<<"\n       !  !        |_________|        !  !       ";
    cout<<"\n       !  !           |   |           !  !       ";
    cout<<"\n       !  !___________|   |___________!  !       ";
    cout<<"\n       !______________|   |______________!       ";
    cout<<"\n                  ____|   |____                  ";
    cout<<"\n                 |_____________|                 \n\n\n\n";
    cout<<"\t\t=>> Md. Jahid Hasan Anik\n\n\t\t   =>> ID: 17203010\n\n\t\t      =>> Sec: B\n\n\t\t\t =>> Program: BCSE\n";
    cin.get();
}


void loading()
{
    int i;
    char a=177,b=219;
    system("Cls");
    cout<<"\n\n\n\n\t\tPlease! Be patient...";
    cout<<"\n\n\t\t\                          loading... ^_^  >_<  *_*  loading... ";
    for(i=0;i<=39;i++)
    {
        cout<<a;
        Sleep(150);
        cout<<"\r";
        cout<<"\t\t\t\t\t";}
        for(i=0;i<=39;i++)
        {
            cout<<b;
            Sleep(200);
        }
        cout<<"\n\n\n\t\t\t\t\t\tPress ENTER ";
        system("pause>0");
}
