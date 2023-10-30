#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float discount;
    int quantity;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rm();
    void list();
    void receipt();
};

void shopping ::menu()
{
menuBox:
    system("cls");
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t            Supermarket Main Menu            \n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t         1) Administrator                    \n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t         2) Buyer                            \n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t         3) Exit                             \n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t         Please Select :\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t Please Login\n";
        cout << "\t\t\t\t Enter Email:\t";
        cin >> email;
        cout << "\t\t\t\t Enter Password:\t";
        cin >> password;

        if (email == "admin@gmail.com" && password == "admin@123")
        {
            system("cls");
            administrator();
        }
        else
        {
            cout << "\t\t\t\t Invalid Email/Password\n";
        }
        break;

    case 2:
    {
        system("cls");
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select from the given options\n";
    }
    }
    getchar();
    system("cls");
    goto menuBox;
}

void shopping ::administrator()
{
administratorMenu:
    int choice;
    cout << "\n\n\n";
    cout << "\t\t\t\t Administrator menu\n";
    cout << "\t\t\t\t 1) Add the product\n";
    cout << "\t\t\t\t 2) Modify the product\n";
    cout << "\t\t\t\t 3) Delete the product\n";
    cout << "\t\t\t\t 4) Review the product list\n";
    cout << "\t\t\t\t 5) Back to main menu\n\n";
    cout << "\t\t\t\t Please enter your choice:\t";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rm();
        break;
    case 4:
        list();
        getchar();
        break;
    case 5:
        system("cls");
        menu();
        break;
    default:
        cout << "\n\t\t\t\t Invalid choice!\n";
        break;
    }
    getchar();
    system("cls");
    goto administratorMenu;
}

void shopping ::buyer()
{
buyerMenu:
    int choice;
    cout << "\n\n\n";
    cout << "\t\t\t\t Buyer menu\n";
    cout << "\t\t\t\t 1) Buy product\n";
    cout << "\t\t\t\t 2) Back to main menu\n\n";
    cout << "\t\t\t\t Please enter your choice:\t";
    cin >> choice;
    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        system("cls");
        menu();
        break;
    default:
        cout << "\n\t\t\t\t Invalid choice!\n";
    }
    getchar();
    system("cls");
    goto buyerMenu;
}

void shopping ::add()
{
addMenu:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    int q;
    string n;

    cout << "\n\n\n";
    cout << "\t\t\t\t Add new product\n";
    cout << "\t\t\t\t Product code of the product:\t";
    cin >> pcode;
    cout << "\t\t\t\t Name of the product:\t";
    cin >> pname;
    cout << "\t\t\t\t Price of the product:\t";
    cin >> price;
    cout << "\t\t\t\t Quantity of the product:\t";
    cin >> quantity;
    cout << "\t\t\t\t Discount on the product:\t";
    cin >> discount;

    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << ' ' << pcode << ' ' << pname << ' ' << price << ' ' << quantity << ' ' << discount << '\n';
        data.close();
    }
    else
    {
        data >> c >> n >> p >> q >> d;
        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> q >> d;
        }
        data.close();
    }
    if (token == 1)
        goto addMenu;
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << ' ' << pcode << ' ' << pname << ' ' << price << ' ' << quantity << ' ' << discount << '\n';
        data.close();
    }
    cout << "\n\n\t\t\t\t Record Inserted !\n";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    int q;
    string n;

    cout << "\n\n\n";
    cout << "\t\t\t\t Modify the record\n";
    cout << "\t\t\t\t Product code:\t";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t File doesn't exist! \n";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> quantity >> discount;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t\t\t Product new code: \t";
                cin >> c;
                cout << "\n\t\t\t\t Name of the product: \t";
                cin >> n;
                cout << "\n\t\t\t\t Price: \t";
                cin >> p;
                cout << "\n\t\t\t\t Quantity: \t";
                cin >> q;
                cout << "\n\t\t\t\t Discount: \t";
                cin >> d;

                data1 << ' ' << c << ' ' << n << ' ' << p << ' ' << q << ' ' << d << '\n';
                cout << "\n\n\t\t\t\t Record edited!\n";
                token++;
            }
            else
            {
                data1 << ' ' << pcode << ' ' << pname << ' ' << price << ' ' << quantity << ' ' << discount << '\n';
            }
            data >> pcode >> pname >> price >> quantity >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n\t\t\t\t Record not found Sorry !";
        }
    }
}

void shopping::rm()
{

    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\n";
    cout << "\t\t\t\t Delete the record\n";
    cout << "\t\t\t\t Product code:\t";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t File doesn't exist! \n";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> quantity >> discount;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t\t\t\t Product deleted successfully\n";
                token++;
            }
            else
            {
                data1 << ' ' << pcode << ' ' << pname << ' ' << price << ' ' << quantity << ' ' << discount << '\n';
            }
            data >> pcode >> pname >> price >> quantity >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\n\t\t\t\t Record not found";
        }
    }
}

void shopping::list()
{

    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n";
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t            Supermarket Menu            \n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t                                             \n";
    cout << "\t\t\t\tProduct No.\t\tName\t\t Price\n";
    cout << "\t\t\t\t_____________________________________________\n";
    cout << "\t\t\t\t                                             \n";
    data >> pcode >> pname >> price >> quantity >> discount;
    while (!data.eof())
    {
        cout << "\t\t\t\t" << pcode << "\t\t" << pname << "\t\t" << price << '\n';
        cout << "\t\t\t\t                                             \n";
        data >> pcode >> pname >> price >> quantity >> discount;
    }
    cout << "\t\t\t\t_____________________________________________\n";
    data.close();
}
void shopping ::receipt()
{

    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t RECEIPT\n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t\t\t Empty datbase.";
    }
    else
    {
        data.close();
        list();
        cout << "\t\t\t\t_____________________________________________\n";
        cout << "\t\t\t\t                                             \n";
        cout << "\t\t\t\t           Please place the order            \n";
        cout << "\t\t\t\t                                             \n";
        cout << "\t\t\t\t_____________________________________________\n";
        do
        {
        receiptMenu:
            cout << "\t\t\t\t Enter Product code:\t";
            cin >> arrc[c];
            cout << "\t\t\t\t Enter Product quantity:\t";
            cin >> arrq[c];
            for (int i = 0; i < c; ++i)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\t\t\t\t Duplicate product code. Please try again!\n";
                    goto receiptMenu;
                }
            }
            c++;
            cout << "\n\n\t\t\t\t Do you want to buy another product (y/n):\t";
            cin >> choice;
        } while (choice == 'y');

        system("cls");
        cout << "\n\n\n\t\t\t\t___________________________RECEIPT___________________________\n";
        cout << "\n\t\tProduct No.\t Product Name\t Quantity\t Price\t Amount\t Amount with discout\n";
        for (int i = 0; i < c; ++i)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> quantity >> discount;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * discount / 100);
                    total = total + dis;
                    cout << "\n\t\t" << pcode << "\t" << pname << "\t" << arrq[i] << "\t" << price << "\t" << amount << "\t" << dis << "\n";
                }
                data >> pcode >> pname >> price >> quantity >> discount;
            }
            data.close();
        }
    }
    cout << "\n\n\n\t\t\t\t_____________________________________________________________\n";
    cout << "\n\n\t\t\t\t Total Amount: \t\t\t" << total;

    cout << "\n\n\n Please enter any key to continue...";
    getchar();
    system("cls");
}
int main()
{
    system("cls");
    shopping s;
    s.menu();
    return 0;
}