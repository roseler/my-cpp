#include <iostream>
#include <stdio.h>
#include <process.h>
#include <fstream>
#include <string>

using namespace std;

string indent = "\t\t\t\t\t";
string mindent = "\t\t\t";

class item
{
	int itemNum;
	char iName[100];
	float price, quantity, discount;

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

	void getShowData()
	{
		system("cls");
		cout << "\n The item number of the item : " << itemNum;
		cout << "\n The name of the item : " << iName;
		cout << "\n The price of the item : " << price;
		cout << "\n Discount : " << discount;
	}

	int retitemNum()
	{
		return itemNum;
	}

	float retprice()
	{
		return price;
	}

	char *retiName()
	{
		return iName;
	}

	int retdis()
	{
		return discount;
	}
};

fstream f;
item i;

void write_to_file()
{
	f.open("store.txt", ios::out | ios::app);
	i.getdata();
	f.write((char *)&i, sizeof(i));
	f.close();
	cout << "\n The item has been created";
	system("pause");
}

void disp_all()
{
	system("cls");
	f.open("store.txt", ios::in);
	if (!f)
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN \n\n\n Go to Admin Menu to create new file";
		cout << "\n\n\n Program is closing...";
		exit(0);
	}

	cout << endl
		 << endl
		 << indent << "\t DISPLAY ALL RECORDS \n\n";
	cout << mindent << "----------------------------------------------------------\n";
	cout << mindent << "ITEM CODE \t\t NAME \t\t PRICE \n";
	cout << mindent << "-----------------------------------------------------------\n";

	while (f.read((char *)&i, sizeof(i)))
	{
		cout << mindent << i.retitemNum() << "\t\t\t " << i.retiName() << "\t\t " << i.retprice() << endl;
	}
	system("pause");
	f.close();
}

void modify()
{
	int no, found = 0;
	system("cls");
	cout << "\n\n\t To Modify ";
	cout << "\n\n\t Enter enter the item number of the product ";
	cin >> no;
	f.open("store.txt", ios::in | ios::out);
	while (f.read((char *)&i, sizeof(i)) && found == 0)
	{
		if (i.retitemNum() == no)
		{
			i.getShowData();
			system("cls");

			cout << "\n Please enter the new details of the item" << endl;
			i.getdata();
			int pos = -1 * ((int)sizeof(i));
			f.seekp(pos, ios::cur);
			f.write((char *)&i, sizeof(i));
			cout << "\n\n Record updated";
			found = 1;
		}
	}
	f.close();
	if (found == 0)
		cout << "\n\n Record not found ";
}

void deleterec()
{
	int no;
	system("cls");
	cout << "\n\n\n Delete Record";
	cout << "\n\n Please enter the item number of the product you want to delete";
	cin >> no;
	f.open("store.txt", ios::in | ios::out);
	fstream f2;
	f2.open("temp.dat", ios::out);
	f.seekg(0, ios::beg);
	while (f.read((char *)&i, sizeof(i)))
	{
		if (i.retitemNum() != no)
		{
			f2.write((char *)&i, sizeof(i));
		}
	}
	f2.close();
	f.close();
	remove("store.txt");
	rename("temp.dat", "store.txt");
	cout << "\n\n Record Deleted ..";
}

void menu()
{
	system("cls");
	f.open("store.txt", ios::in);
	if (!f)
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN \n\n\n Go to Admin Menu to create new file";
		cout << "\n\n\n Program is closing.....";
		exit(0);
	}

	cout << endl
		 << endl
		 << indent << "\t ITEM MENU \n\n";
	cout << mindent << "----------------------------------------------------------\n";
	cout << mindent << "ITEM CODE \t\t NAME \t\t PRICE \n";
	cout << mindent << "-----------------------------------------------------------\n";

	while (f.read((char *)&i, sizeof(i)))
	{
		cout << mindent << i.retitemNum() << "\t\t\t " << i.retiName() << "\t\t " << i.retprice() << endl;
	}
	system("pause");
	f.close();
}

void place_order()
{
	system("cls");

	int order_arr[100], quantity, c = 0;
	float amt, damt, total = 0;
	char ch = 'Y';
	menu();
	cout << mindent << "-----------------------------------------------------------";
	cout << endl
		 << indent << "      PLACE YOUR ORDER";
	cout << endl
		 << mindent << "-----------------------------------------------------------\n";
	do
	{
		cout << endl
			 << indent << "Enter the item code of the product: ";
		cin >> order_arr[c];
		c++;
		cout << endl
			 << indent << "Quantity in number: ";
		cin >> quantity;
		c++;
		cout << endl
			 << indent << "Do you want to order another item? (y/n): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << "\n\n Thank you for placing your order!";
	system("cls");
	cout << endl
		 << endl
		 << indent << "\t\t INVOICE\n";
	cout << "-------------------------------------------------------------";
	cout << "-----------------------------------------------------------";
	cout << "| Item Number \t| Name \t | Quantity | Price \t | Amount | Amount after discount | \n";
	cout << "-------------------------------------------------------------";
	cout << "-----------------------------------------------------------";
	for (int x = 0; x <= c; x++)
	{
		f.open("store.txt", ios::in);
		f.read((char *)&i, sizeof(i));
		while (!f.eof())
		{
			if (i.retitemNum() == order_arr[x])
			{
				amt = i.retprice() * quantity;
				damt = amt - (amt * i.retdis() / 100);
				cout << "\n " << order_arr[x] << "\t\t " << i.retiName() << "\t  " << quantity << "\t     "
					 << i.retprice() << "\t\t   " << amt << "\t\t   " << damt;
				total += damt;
			}
			f.read((char *)&i, sizeof(i));
		}
		f.close();
	}
	cout << endl
		 << "-------------------------------------------------------------";
	cout << "-----------------------------------------------------------";
	cout << "\n\t\t\t\t\t\t   TOTAL = " << total << endl;
	cout << endl
		 << indent << "\t";
	system("pause");
}

void admin_menu()
{

string pass = "roselerlangmalakas";
    string input;
    cout << "Enter admin password: ";
    cin >> input;
    if (input==pass){
        cout << "Correct" << endl;
    }else{
        cout << "Access denied!" << endl;
		exit(0);
    }
system("pause"); f.close();
	system("cls");
	char ch2;
	cout << "\n\n\t ADMIN MENU";
	cout << "\n\n\t 1. CREATE ITEM";
	cout << "\n\n\t 2. DISPLAY ALL ITEMS";
	cout << "\n\n\t 3. MODIFY ITEM";
	cout << "\n\n\t 4. DELETE ITEM";
	cout << "\n\n\t 5. BACK TO MAIN MENU";
	cout << "\n\n\t Please enter your choice (1-5) \t";
	cin >> ch2;

	switch (ch2)
	{
	case '1':
		system("cls");
		write_to_file();
		break;
	case '2':
		disp_all();
		disp_all;
		break;
	case '3':
		modify();
		break;
	case '4':
		deleterec();
		break;
	case '5':
		"\a";
		break;
	}
}

int main()
{

	system("title Store Management System by Group 9");
	system("cls");
	system("color 0A");

	char ch;

	do
	{
		system("cls");
		cout << "\n\n"
			 << indent << "\t\tMAIN MENU";
		cout << endl
			 << mindent << "\t\t=============================================";
		cout << "\n\n"
			 << mindent << "\t\t 1) CUSTOMER";
		cout << "\n\n"
			 << mindent << "\t\t 2) ADMINISTRATOR";
		cout << "\n\n"
			 << mindent << "\t\t 3) EXIT";
		cout << "\n\n"
			 << indent << " Please select your desired option (1-3):  ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			system("cls");
			place_order();
			break;

		case '2':
			admin_menu();
			break;

		case '3':
			exit(0);
			break;
		default:
			cout << "\a";
		}
	} while (ch != '3');

	return 0;
}
//       .__(.)< (MEOW)
//        \___)   
