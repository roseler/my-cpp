#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>

using namespace std;

class item
{
	int itemNum;
	char iName[100];
	float price, quantity, tax, discount;
	
public:
	void getdata()
	{
		system("cls");
		cout << "\n PLease enter the item number of the item --> \t";
		cin >> itemNum;
		cout << "\n Please enter the name of the item --> \t";
		cin >> iName;
		cout << "\n Please enter the price of the item --> \t";
		cin >> price;
		cout << "\n Please enter discount(%) of the item --> \t";
		cin >> discount;
	
	}
	fstream f;
item i;

	void getShowData()
	{
		system("cls");
		cout << "\n The item number of the item : " << itemNum;
		cout << "\n The name of the item : " << iName;
		cout << "\n The price of the item : " << price;
		cout << "\n Discount : " << discount;
	
	}
	
	int retitemNum()
	{return itemNum;}
	
	float retprice()
	{return price;}
	
	char* retiName()
	{return iName;}
	
	int retdis()
	{return discount;}
	
	int rettax()
	{return tax;}

};

fstream f;
item i;

void write_to_file()
{
	f.open("store.dat", ios::out|ios::app);
	i.getdata();
	f.write((char*)&i, sizeof(i));
	f.close();
	cout << "\n The item has been created";
}

void display_all()
{
	system("cls");
	cout << "\n\n\n\t\t Display All Records!!!\n\n"; //print	
	f.open("store.dat", ios::in);
	while(f.read((char*)&i, sizeof(i)));
	{
		i.getShowData();
		cout << "\n\n --------------------------\n";
	}
	f.close();
}

void display_sp(int n)
{
	int flag=0;
	f.open("store.dat", ios::in);
	while(f.read((char*)&i, sizeof(i)))
	{
		if(i.retitemNum()==n)
		{
			system("cls");
			i.getShowData();
			flag=0;	
		}
	}
	f.close();
	if(flag==0)
		cout << "\n\n Record does not exist";
}

void modify()
{
	int no, found=0;
	system("cls");
	cout << "\n\n\t To Modify ";
	cout << "\n\n\t Enter enter the item number of the product ";
	cin >> no;
	f.open("store.dat", ios::in|ios::out);
	while(f.read((char*)&i, sizeof(i)) && found==0)
	{
		if(i.retitemNum()==no)
		{
			i.getShowData();
			system("cls");
			
			cout << "\n Please enter the new details of the item" << endl;
			i.getdata();
			int pos=-1*((int)sizeof(i));
			f.seekp(pos, ios::cur);
			f.write((char*)&i, sizeof(i));
			cout << "\n\n Record updated";
			found=1;
		}
	}
	f.close();
	if(found==0)
	cout << "\n\n Record not found ";
}

void deleterec()
{
	int no;
	system("cls");
	cout << "\n\n\n Delete Record";
	cout << "\n\n Please enter the item number of the product you want to delete";
	cin >> no;
	f.open("store.dat", ios::in|ios::out);
	fstream f2;
	f2.open("temp.dat", ios::out);
	f.seekg(0,ios::beg);
	while(f.read((char*)&i, sizeof(i)))
	{
		if(i.retitemNum()!=no)
		{
			f2.write((char*)&i, sizeof(i));
		}
	}
	f2.close();
	f.close();
	remove("store.dat");
	rename("temp.dat", "store.txt");
	cout << "\n\n Record Deleted ..";
}

void menu()
{
	system("cls");
	f.open("store.dat", ios::in);
	if(!f)
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN \n\n\n Go to Admin Menu to create new file";
		cout << "\n\n\n Program is closing.....";
		exit(0);
	}
	
	cout << "\n\n\t\t ITEM MENU \n\n";
	cout << "-----------------------------\n";
	cout << "ITEM NUMBER \t NAME \t\t PRICE \n";
	cout << "-----------------------------\n";
	
	while(f.read((char*)&i, sizeof(i)))
	{
		cout << i.retitemNum() << "\t\t" << i.retiName() << "\t\t" << i.retprice() << endl;
	}
	f.close();
}

void place_order()
{
	system("cls");
	
	int order_arr[100], quantity[100], c=0;
	float amt, damt, total=0;
	char ch='Y';
	menu();
	cout << "-----------------------------";
	cout << "\n-------------------------";
	cout << "PLACE YOUR ORDER";
	cout << "-------------------------\n";
	do{
		cout << "\n\n Enter the item number of the product :\n";
		cin >> order_arr[c];
		cout << "\n Quantity in number : \n";
		cin >> quantity[c];
		c++;
		cout << "\n Do you want to order another item? (y/n) \t";
		cin >> ch;
	}
	while(ch=='y' ||ch=='Y');
	cout << "\n\n Thank you for placing your order!";
	system("cls");
	cout << "\n\n ************INVOICE************\n";
	cout << "\n Item Number \t Name \t Quantity \t Price \t Amount \t Amount after discount \t Tax \n";
	for(int x=0; x<=c; x++)
	{
		f.open("store.dat", ios::in);
		f.read((char*)&i, sizeof(i));
		while(!f.eof())
		{
			if(i.retitemNum()==order_arr[x])
			{
				amt=i.retprice()*quantity[x];
				damt=amt-(amt*i.retdis()/100);
				cout << "\n" << order_arr[x] << "\t" << i.retiName() << "\t" << quantity[x] << "\t\t" << i.retprice() << "\t" << amt << "\t\t" << damt;
				total+=damt;
			}
			f.read((char*)&i, sizeof(i));
		}
		f.close();
	}
	cout << "\n\n\t\t\t\t\t TOTAL = " << total;
}

void admin_menu()
{
	system("cls");
	char ch2;
	cout << "\n\n\t ADMIN MENU";
	cout << "\n\n\t 1. CREATE ITEM";
	cout << "\n\n\t 2. DISPLAY ALL ITEMS";
	cout << "\n\n\t 3. QUERY";
	cout << "\n\n\t 4. MODIFY ITEM";
	cout << "\n\n\t 5. DELETE ITEM";
	cout << "\n\n\t 6. BACK TO MAIN MENU";
	cout << "\n\n\t Please enter your choice (1-6) \t";
	cin >> ch2;
	switch(ch2)
	{
		case '1': system("cls");
			write_to_file();
			break;
		case '2': display_all();
			display_all;
			break;
		case '3':
			int num;
			system("cls");
			cout << "\n\n\t Please enter the item number ";
			cin >> num;
			display_sp(num);
			break;
		case '4': modify();
			break;
		case '5': deleterec();
			break;
		case '6': menu();
			break;
		default:cout << "\a"; admin_menu;
			}
}

int main()
{
	 system ("title Basic Students' Database by Group 9");
   system ("cls");
   system ("color 0A");
	
	char ch;
	
	do
	{
		system("cls");
		cout << "\n\n\t MAIN MENU";
		cout << "\n\n\t 1. CUSTOMER";
		cout << "\n\n\t 2. ADMINISTRATOR";
		cout << "\n\n\t 3. EXIT";
		cout << "\n\n\t Please select your desire option (1-3) \t";
		cin >> ch;
	switch(ch)
	{
		case '1': system("cls");
			place_order();
			break;
		case '2': admin_menu();
			break;
		case '3': exit(0);
			break;
		default: cout << "\a";
	}	  
	}while(ch!='3');
	return 0;
}
