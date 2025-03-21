#include<iostream>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<fstream>
using namespace std;
int i,n;
ifstream fin;
ofstream fout;
fstream fio;
void disp();
class stock
{
	char name[20],pass[10];
	float pr; int quant;
public:
	void get();
	void get2();
	void show();
    int stchk(char nm[30]);    
    void withd(int qty);
    void refil(int qty);
}st;
void stock::withd(int qty)
{
	int cash,sum;
	sum=pr*qty;
	if(quant>=qty)
	{
		quant-=qty;
		cout<<"\n\nStock updated.\n";
	    cout<<"\n\tName"<<"\tQuantity"<<"\tPrice";
	    cout<<"\n\t"<<name<<"\t"<<qty<<"\t\t"<<sum;
		cout<<"\nTotal:";
	    cout<<"\n------------------------------------------------------------------------------";
	    cout<<"\n\tQuantity= "<<qty<<"\t\tSum= "<<sum;
	    cout<<"\n------------------------------------------------------------------------------";
        pay:
	    cout<<"\n\n\t\t\t****PAYMENT SUMMARY****\n";
	    cout<<"\n\t\t\tTotal cash given: ";
	    cin>>cash;
	    if(cash>=pr*qty)
		cout<<"\n\t\t\tTotal cash repaid: "<<cash-(sum)<<'\n';
        else
	    {	
	    cout<<"\n\t\t\tCash given is less than total amount!!!";
        goto pay;
	    }
		cout<<"\n\nTotal price to be paid:"<<sum;
    }
	else 
	   cout<<"\n\nInsufficient stock";
	   getch();
}
void stock::refil(int qty)
{
		quant+=qty;
		cout<<"\n\nStock updated.";
	    getch();	
}
int stock::stchk(char nm[30])
{
	if(strcmp(nm,name)==0)
	 return 0;
	else 
	return 1;
}
void stock::get()
{
	cin>>name>>pr>>quant;
}
void stock::get2()
{
	cin>>name>>quant;
}
void stock::show()
{	
	cout<<"\n"<<name<<"\t\t\t"<<quant<<"\t\t\t"<<pr;
}
void withdraw()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the product's name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.txt",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  st.withd(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    cin.get();
    system("cls");
	 disp(); 
	getch();
}
void addnew()
{
    system("cls");	
	disp();
	getch();
	system("cls");
	
	cout<<"\nEnter the No. of Products that you wish to add: ";
    cin>>n;
	
    
    if (n!=0)
    {
	
	int j,l,sum=0;
	fout.open("shop.txt",ios::binary|ios::app);
	for(i=0;i<n;i++)
	
	{
		cout<<"\n\nInput the name, price and the quantity of item respectively\n\n";
	    st.get();
	    fout.write((char*)&st,sizeof(st));
        cout<<"\n\nitem updated";
		cin.get();
    }
    cout<<"\n\nStock Updated!!";
    fout.close();
    cin.get();
    system("cls");
    disp();
}
    else
{
	fout.close();
	cin.get();
	system("cls");
	cout<<"\n\nNo items to be added";
}
}
void disp()
{
	int i=1;
	cout<<"\n==================================================================";
	cout<<"\n\n=================\tTHE STOCK ITEMS ARE\t==================";
	cout<<"\n\n==================================================================\n";
	cout<<"\n\nPARTICULARS\tSTOCK AVAILABLE\t\t\t PRICE";
	cout<<"\n\n============================================================\n";	
	 fin.open("shop.txt",ios::binary);
     while(!fin.eof())
     {
	  fin.read((char*)&st,sizeof(st));
	  if(!fin.eof())
	  {
	     if(fin.tellg()<0)
	     {	i=0; break;}
	     st.show();
	  }
     }
     if(i==0)
     {	cout<<"\n\n\t\t\t!!Empty record room!!";
	getch();
     }
     fin.close();
}
void refill()
{
	system("cls");
	char temp[100];int qty;
	int i=0;
	long pos=0;
	disp();
	cout<<"\n\nEnter the products name \n"<<endl;
	cin>>temp;
	cout<<"\n\nEnter quantity: \n"<<endl;
	cin>>qty;
	fio.open("shop.txt",ios::binary|ios::out|ios::in);
     while(fio)
     {
	    pos=fio.tellp();
	    fio.read((char*)&st,sizeof(st));
	    if(st.stchk(temp)==0)
	    {
		  
		  st.refil(qty);
		  fio.seekp(pos);
		  fio.write((char*)&st,sizeof(st));
		  i++;break;
	    }
     }
     if(i!=1)
       cout<<"\n\n!!Record not found!!";
     fio.close();
    system("cls");
    cin.get();
	 disp(); cin.get();
}
int main()
{
	char opt, ch;
	int a=1;
	ifstream fin;
	int i,j;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n \t\t\t|============ WELCOME TO DD STORES ============|";
    system("cls");
	dealermenu:
	system("cls");
	cout<<"=================================================================";
	cout<<"\n\n\t\t\t    DEALER MENU\n1. Add item\n2. Display item\n3. Refill item \n4. Billing for customer \n5. Exit:";
	cout<<"\n\n Enter your Choice :\t";
	cin>>i;
	if(i==1)
	{
	addnew();
	getch();
	goto dealermenu;
	}

	else if(i==2)
	{
	system("cls");
	disp();
	getch();
	goto dealermenu;
	}
	else if(i==3)
	{
		disp();
		getch();
		goto dealermenu;
	}
	else if(i==4)
	{
		withdraw();
		getch();
		goto dealermenu;
	}
	else 
	{
	system("cls");
	getch();
	exit(0);
    }
    getch();
}
