//project final final

/*
ANKIT KUMAR
MCA I YEAR
MCA-AB-108
0801CA211009
*/
#include <windows.h>
#include<iostream>
#include<fstream>
using namespace std;
int pc,user_status;
class pcinfo
{

    char processor[50];
    char motherboad[50];
    char memory[50];
    char graphiccard[50];
    char storage[50];
    char cabinet[50];
    char cooler[50];
    char psu[50];

public:
    int sn;
    double price;


    void setData() //function to get data
    {
        cout << "\nEnter PROCESSOR    : ";
        cin.getline(processor,50);

        cout << "Enter MOTHERBOARD    : ";
        cin.getline(motherboad,50);

        cout << "Enter MEMORY         : ";
        cin.getline(memory,50);

        cout << "Enter GRAPHIC CARD   : ";
        cin.getline(graphiccard,50);

        cout << "Enter STORAGE        : ";
        cin.getline(storage,50);

        cout << "Enter CABINET        : ";
        cin.getline(cabinet,50);

        cout << "Enter COOLER         : ";
        cin.getline(cooler,50);

        cout << "Enter PSU            : ";
        cin.getline(psu,50);

        cout << "Enter PRICE          : ";
        cin>>price;
    }

    void showData() //function to show data
    {
        cout << "\nSerial Number   : "<<sn;

        cout << "\nPROCESSOR       : "<<processor;

        cout << "\nMOTHERBOARD     : "<<motherboad;

        cout << "\nMEMORY          : "<<memory;

        cout << "\nGRAPHIC CARD    : "<<graphiccard;

        cout << "\nSTORAGE         : "<<storage;

        cout << "\nCABINET         : "<<cabinet;

        cout << "\nCooler          : "<<cooler;

        cout << "\nPSU             : "<<psu;

        cout << "\nPRICE           : "<<price<<"/-";
    }

};
class user : public pcinfo
{
    char pno[50];
    char addressl1[50];
    char addressl2[50];
    char addressl3[50];
    char city[50];
    char state[50];

public:
    char name[50];
    char uname[50];
    char upass[50];
    int pincode;
    int userpcstatus;
    user()
    {
        pincode=0;
    }
    void registeru()
    {
        system("cls");
        cout<<"\nUser Registration\n\n";
        cout<<"\nEnter User Name:";
        getchar();
        cin.getline(uname,50);
        cout<<"\nEnter Password:";
        cin.getline(upass,50);
    }
    void userinfo()
    {
        cout << "\nEnter Your Name: ";
        cin.getline(name,50);

        cout << "Enter Your Phone No.: ";
        cin.getline(pno,50);

        cout << "Enter Your Address Line 1: ";
        cin.getline(addressl1,50);

        cout << "Enter Your Address Line 2: ";
        cin.getline(addressl2,50);

        cout << "Enter Your Address Line 3: ";
        cin.getline(addressl3,50);

        cout << "Enter Your City: ";
        cin.getline(city,50);

        cout << "Enter Your State: ";
        cin.getline(state,50);

        cout << "Enter Your Pincode: ";
        cin>>pincode;

    }


};
//for admin
void write_record()
{
    int choice=1,a=0;
    ofstream outFile;
    ifstream c;
    pcinfo obj;


        if(pc==1)
        {
            c.open("lowpc.dat", ios::binary);//for serial number

            c.seekg(0);
            while(c.read((char*)&obj, sizeof(obj)))
            {
                a++;
            }
            c.close();
            outFile.open("lowpc.dat", ios::binary | ios::app);
            if(!outFile)
            {
                cout << "Cannot open file!" << endl;
                exit(0);
            }

            obj.sn=a; //assigning serial number
            obj.setData(); //geting data
            outFile.write((char*)&obj, sizeof(obj));
            cout<<"\n\nPC Added Successfully";
            outFile.close();
        }
        if(pc==2)
        {
            c.open("midpc.dat", ios::binary);
            c.seekg(0);
            while(c.read((char*)&obj, sizeof(obj)))
            {
                a++;
            }
            c.close();


            outFile.open("midpc.dat", ios::binary | ios::app);

            obj.sn=a;


            obj.setData();
            outFile.write((char*)&obj, sizeof(obj));
            cout<<"\n\nPC Added Successfully";
            outFile.close();
        }
        if(pc==3)
        {
            c.open("highpc.dat", ios::binary);
            c.seekg(0);
            while(c.read((char*)&obj, sizeof(obj)))
            {
                a++;
            }
            c.close();


            outFile.open("highpc.dat", ios::binary | ios::app);

            obj.sn=a;


            obj.setData();
            outFile.write((char*)&obj, sizeof(obj));
            cout<<"\n\nPC Added Successfully";
            outFile.close();
        }

}
void display()
{
    int choice=1;
    ifstream inFile;
    if(pc==1)
    inFile.open("lowpc.dat", ios::binary | ios::app);
    if(pc==2)
    inFile.open("midpc.dat", ios::binary | ios::app);
    if(pc==3)
    inFile.open("highpc.dat", ios::binary | ios::app);
    if(!inFile) {
      cout << "Cannot open file!" << endl;
      exit(0);
   }

    pcinfo obj;

    inFile.seekg(0);
    while(choice)
    {
        system("cls");

        inFile.read((char*)&obj, sizeof(obj));
        if(pc==1)
        cout<<"\nBUDGET FRIENDLY PC\n\n";
        if(pc==2)
        cout<<"\nMID-RANGE PC\n\n";
        if(pc==3)
        cout<<"\nHIGH-END PC\n\n";

        obj.showData();

        cout<<"\n\nPress 1 to view next else press 0:";
        cin>>choice;

    }

    inFile.close();
}

void modify(int temp)
{
    int flag=0;
    fstream f;
    if(pc==1)
    f.open("lowpc.dat", ios::binary | ios::in | ios::out);
    if(pc==2)
    f.open("midpc.dat", ios::binary | ios::in | ios::out);
    if(pc==3)
    f.open("highpc.dat", ios::binary | ios::in | ios::out);
    if(!f)
    {
      cout << "Cannot open file!" << endl;
      exit(0);
    }
    pcinfo obj;
    while(f.read((char*)&obj, sizeof(obj)))
    {
        if(obj.sn==temp)
        {
            flag=1;
            cout<<"\n\nExisting Detaiils\n";
            obj.showData();

            cout<<"\n\nEnter the new price:";
            cin>>obj.price;

            f.seekp(-sizeof(obj),ios::cur);
            f.write((char*)&obj, sizeof(obj));

            cout<<"\n\nPrice Updated Successfully";
            f.close();
        }

    }
    if(flag==0)
        cout<<"\n\nNOT FOUND";

}

void deletepc(int temp)
{
    int flag=0;
    fstream f,f1;
    f1.open("tempfile.dat", ios::binary | ios::out);

    if(pc==1)
    f.open("lowpc.dat", ios::binary | ios::in);
    if(pc==2)
    f.open("midpc.dat", ios::binary | ios::in);
    if(pc==3)
    f.open("highpc.dat", ios::binary | ios::in);
    if(!f || !f1)
    {
      cout << "Cannot open file!" << endl;
      exit(0);
    }
    pcinfo obj;

    while(f.read((char*)&obj, sizeof(obj)))
    {
        if(obj.sn!=temp)
        {
            flag=1;
            f1.write((char*)&obj, sizeof(obj));
        }
        else
        {   flag=1;
            cout<<"\n\nDeleting PC\n";
            obj.showData();
        }

    }
    if(flag==0)
        cout<<"\n\nNOT FOUND";
    else
        cout<<"\n\nDeleted";

    f.close();
    f1.close();

    if(pc==1)
    {
        remove("lowpc.dat");
        rename("tempfile.dat","lowpc.dat");
    }
    if(pc==2)
    {
        remove("midpc.dat");
        rename("tempfile.dat","midpc.dat");
    }
    if(pc==3)
    {
        remove("highpc.dat");
        rename("tempfile.dat","highpc.dat");
    }

}
void sellpc(int temp)
{

	 int flag=0;
	 char c;
    fstream f,sell;
    if(pc==1)
    f.open("lowpc.dat", ios::binary | ios::in);
    if(pc==2)
    f.open("midpc.dat", ios::binary | ios::in);
    if(pc==3)
    f.open("highpc.dat", ios::binary | ios::in);

	sell.open("sell.dat",ios::binary | ios::app);


    if(!f)
    {
      cout << "Cannot open file!" << endl;
      exit(0);
    }
    pcinfo obj;
    while(f.read((char*)&obj, sizeof(obj)))
    {
        if(obj.sn==temp)
        {
            flag=1;
            cout<<"\n\nDetails of PRE-BUILD PC\n\n";
            obj.showData();

            cout<<"\n\nDo you want to sell[y/n]:";
            cin>>c;

			if(c=='y' || c=='Y')
			{
				sell.write((char*)&obj, sizeof(obj));
				cout<<"\n\nProduct Sold Successfully";
			}

            sell.close();
            f.close();

        }

    }
    if(flag==0)
        cout<<"\n\nNOT FOUND";

}
void show_total_sales()
{
	fstream sell;
	double total_price=0;
	sell.open("sell.dat",ios::binary | ios::in);


	system("cls");
	cout<<"\nTotal Sales:"<<"\n\n";

	pcinfo obj;
    while(sell.read((char*)&obj, sizeof(obj)))
	{
		obj.showData();
		total_price=total_price+obj.price;

		cout<<"\n";
	}

	cout<<"\n\nTotal Sales:"<<total_price;

}
void admin()
{
    int choice,c1,se;


    char ch,x,pass[50]="admin@123";
    system("cls");
    cout<<"\nADMIN PANEL\n\n";
    cout<<"\n\nEnter the password:";
    getchar();
    cin.getline(pass,50);

    if(strcmp(pass,"admin@123")!=0)
    {
        cout<<"\n\nIncorrect Password Terminating Program";
        exit(0);
    }
    do
    {
        system("cls");
        cout<<"\nADMIN PANEL\n\n";
        cout<<"\n1.ADD NEW PRE-BUILD PC";
        cout<<"\n2.DISPLAY EXISTING PRE-BUILD PC";
		cout<<"\n3.SELL PRE-BUILD PC";
		cout<<"\n4.TOTAL SALES";
        cout<<"\n5.GIVE DISCOUNT on PRE-BUILD PC";
        cout<<"\n6.DELETE PRE-BUILD PC";
        cout<<"\n7.LOGOUT";

        cout<<"\n\nEnter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1://add record
                    p:
                    system("cls");
                    cout<<"\nADD NEW PRE-BUILD PC\n\n";
                    cout<<"\n1.Add BUDGET FRIENDLY PC";
                    cout<<"\n2.Add MID-RANGE PC";
                    cout<<"\n3.Add HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;
                    getchar();
                    switch(c1)
                    {
                        case 1:
                                cout<<"\nBUDGET FRIENDLY PC\n\n";
                                pc=1;
                                write_record();
                                cout<<"\n\nWant to add more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p;
                                break;
                        case 2:
                                cout<<"\nMID-RANGE PC\n\n";
                                pc=2;
                                write_record();
                                cout<<"\n\nWant to add more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p;
                                break;
                        case 3:
                                cout<<"\nHIGH-END PC\n\n";
                                pc=3;
                                write_record();
                                cout<<"\n\nWant to add more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p;
                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;

            case 2: //display
                    system("cls");
                    cout<<"\nPRE-BUILD PC\n\n";
                    cout<<"\n1.BUDGET FRIENDLY PC";
                    cout<<"\n2.MID-RANGE PC";
                    cout<<"\n3.HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;

                    switch(c1)
                    {
                        case 1: pc=1;
                                display();
                                break;
                        case 2: pc=2;
                                display();
                                break;
                        case 3: pc=3;
                                display();
                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;
			case 3://sellpc
						 p1:
                    system("cls");
                    cout<<"\nSELL PRE-BUILD PC\n\n";
                    cout<<"\n1.BUDGET FRIENDLY PC";
                    cout<<"\n2.MID-RANGE PC";
                    cout<<"\n3.HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;
                    getchar();
                    switch(c1)
                    {
                        case 1:
                                cout<<"\nBUDGET FRIENDLY PC\n\n";
                                pc=1;
								cout<<"\n\nEnter the serial number:";
                                cin>>se;
                               sellpc(se);
                                cout<<"\n\nWant to sell more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p1;
                                break;
                        case 2:
                                cout<<"\nMID-RANGE PC\n\n";
                                pc=2;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                               sellpc(se);
                                cout<<"\n\nWant to sell more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p1;
                                break;
                        case 3:
                                cout<<"\nHIGH-END PC\n\n";
                                pc=3;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                               sellpc(se);
                                cout<<"\n\nWant to sell more [y/n]:";
                                cin>>x;
                                if(x=='y'||x=='Y')
                                    goto p1;
                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;
			case 4://total sales
						show_total_sales();
						break;
            case 5: //modify
                    system("cls");
                    cout<<"\nGIVE DISCOUNT on PRE-BUILD PC\n\n";
                    cout<<"\n1.On BUDGET FRIENDLY PC";
                    cout<<"\n2.On MID-RANGE PC";
                    cout<<"\n3.On HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;

                    switch(c1)
                    {
                        case 1: pc=1;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                modify(se);
                                break;
                        case 2: pc=2;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                modify(se);
                                break;
                        case 3: pc=3;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                modify(se);
                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;
            case 6://delete
                    system("cls");
                    cout<<"\nDelete PRE-BUILD PC\n\n";
                    cout<<"\n1.BUDGET FRIENDLY PC";
                    cout<<"\n2.MID-RANGE PC";
                    cout<<"\n3.HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;

                    switch(c1)
                    {
                        case 1: pc=1;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                deletepc(se);
                                break;
                        case 2: pc=2;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                deletepc(se);
                                break;
                        case 3: pc=3;
                                cout<<"\n\nEnter the serial number:";
                                cin>>se;
                                deletepc(se);
                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;
            case 7:break;

            default:cout<<"\nEnter valid choice\n\n";

        }

        cout<<"\n\n\nDo you want to see the Admin menu[y/n]:";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
}
//for user
void registeruser()
{
    ofstream uf;

    uf.open("user.dat",ios::binary | ios::app);
     if(!uf)
    {
        cout << "Cannot open file!" << endl;
        exit(0);
    }
    user u;

    u.registeru();
    uf.write((char*)&u, sizeof(u));

    cout<<"\n\nRegister Successfully";
    cout<<"\n\nGo back to main-menu to login";
    uf.close();
}
void login(void);

int main()
{

    int choice;
    char c;
    COORD ci;
    ci.X=40;
    ci.Y=8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),ci);
    cout<<"WELCOME TO AKKI's COMPUTERS\n";
    for(int i=0;i<110;i++)
    {
        cout<<"-";
            Sleep(100);
    }
    do
    {

        system("cls");
        cout<<"\nAKKI's COMPUTERS\n\n";
        cout<<"\n1.Login User";
        cout<<"\n2.Register (For new users)";
        cout<<"\n3.Admin Panel";
        cout<<"\n4.Exit";


        cout<<"\n\nEnter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1: login();
                    break;
            case 2: registeruser();
                    break;
            case 3: admin();
                    break;
            case 4:exit(0);
            default:cout<<"\n\nPlease enter valid choice";
        }
        cout<<"\n\nDo you want to see the main-menu [y/n]:";
        cin>>c;

    }while(c=='y'||c=='Y');

    return 0;
}
void login()
{
    char un[50],p[50];
    fstream f,f1,fpc,cf;
    user u;
    system("cls");
    cout<<"\nUser Login\n\n";
    cout<<"\nUsername:";
    getchar();
    cin.getline(un,50);
    cout<<"\nPassword:";
    cin.getline(p,50);

    f.open("user.dat", ios::binary | ios::in | ios::out);

    while(f.read((char*)&u, sizeof(u)))
    {
        if(strcmp(u.uname,un)==0 && strcmp(u.upass,p)==0)
        {
            system("cls");
            cout<<"\n\nLogin Successfully";

            if(u.pincode==0)
            {

                cout<<"\n\nYou Login for the First time Please fill these details-\n\n";
                u.userinfo();
                strcpy(u.uname,un);
                strcpy(u.upass,p);

                f.seekp(-sizeof(u),ios::cur);
                f.write((char*)&u, sizeof(u));

                cout<<"\n\nYour Information Added Successfully Login again";

                f.close();


            }
            else
            {

                int choice,x=0,serial,a=0,c1;
                char c,pcchoice;
                do
                {   system("cls");
                    cout<<"\n\nHello "<<u.name<<"\n\n";
                    cout<<"\nYour Options\n";
                    cout<<"\n1.View Pre Build PC's";
                    cout<<"\n2.Customize Pre Build PC's";
                    cout<<"\n3.Go Back to main menu";
                    cout<<"\n4.Logout";

                    cout<<"\n\nEnter your choice:";
                    cin>>choice;

                    switch(choice)
                    {
                    case 1://showpc
                            system("cls");
                            cout<<"\nPRE-BUILD PC\n\n";
                            cout<<"\n1.BUDGET FRIENDLY PC";
                            cout<<"\n2.MID-RANGE PC";
                            cout<<"\n3.HIGH-END PC";
                            cout<<"\n\nEnter your choice:";
                            cin>>c1;

                            switch(c1)
                            {
                                case 1: pc=1;
                                        user_status=1;
                                        display();

                                        f1.close();
                                        fpc.close();
                                        cf.close();
                                        f.close();




                                        break;
                                case 2: pc=2;
                                        user_status=1;
                                        display();
                                        break;
                                case 3: pc=3;
                                        user_status=1;
                                        display();
                                        break;
                                default:cout<<"\nEnter valid choice\n\n";



                            }


                            break;
                    case 2://addpc
                            system("cls");
                            cout<<"\nCustomize Your NEW PRE-BUILD PC\n\n";
                    cout<<"\n1.BUDGET FRIENDLY PC";
                    cout<<"\n2.MID-RANGE PC";
                    cout<<"\n3.HIGH-END PC";
                    cout<<"\n\nEnter your choice:";
                    cin>>c1;
                    getchar();
                    switch(c1)
                    {
                        case 1:
                                cout<<"\nBUDGET FRIENDLY PC\n\n";
                                pc=1;
                                write_record();

                                break;
                        case 2:
                                cout<<"\nMID-RANGE PC\n\n";
                                pc=2;
                                write_record();

                                break;
                        case 3:
                                cout<<"\nHIGH-END PC\n\n";
                                pc=3;
                                write_record();

                                break;
                        default:cout<<"\nEnter valid choice\n\n";

                    }
                    break;

                    case 3://status
                            break;
                    case 4: exit(0);

                    default:cout<<"\n\nEnter valid choice";

                    }
                    if(x==0)
                    {
                    cout<<"\n\nDo you want to see the your options[y/n]:";
                    cin>>c;
                    }
                    else
                    {
                        c='n';
                    }
                }while(c=='y'||c=='Y');
            }
        }
        else
        {
            cout<<"\n\nDeatils not Found please retry";
        }
    }
    f.close();
}

