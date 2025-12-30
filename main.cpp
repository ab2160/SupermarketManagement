#include "Supermarket.h"
#include <iostream>
#include <iomanip>   // Library for set width(column)
#include <algorithm> // Library for changing letters to lower case
using namespace std;

int main()
{
    Supermarket S;
    int i, choice;
    string choose;
    string n, p;
    int id;

    User U;
    cout << "Enter name: ";
    cin >> n;
    transform(n.begin(), n.end(), n.begin(), ::tolower);
    U.setName(n);
    cout << "Enter Id: ";
    cin >> id;
    U.setID(id);
    cout << "Enter password: ";
    cin >> p;
    U.setPassword(p);

    if (U.getName() == "abebe" && U.getId() == 11 && U.getPassword() == "as1234")
    {
        cout << "===================Admin's page=====================" << endl;
        do
        {
            cout << "Supermarket Management System" << endl;
            cout << "1. Add product" << endl;
            cout << "2. Remove product" << endl;
            cout << "3. Sale product" << endl;
            cout << "4. Total sales" << endl;
            cout << "5. Total values of product" << endl;
            cout << "6. Exit" << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter the amount of product you want to add: ";
                cin >> i;
                S.addProduct(i);
                S.display();
                break;
            case 2:
                S.removeProduct();
                S.display();
                break;
            case 3:
                S.sale();
                S.display();
                break;
            case 4:
                S.totalSale();
                break;
            case 5:
                S.totalValue();
                break;
            case 6:
                cout << "Thanks for using our system!!" << endl;
                break;
            default:
                cout << "Invalid choice!!" << endl;
                break;
            }

        } while (choice != 6);
    }
    else
    {
        cout << "======================Employee's page==========================" << endl;
        do
        {
            cout << "Supermarket Management System" << endl;

            cout << "1. Sale product" << endl;
            cout << "2. Total sales" << endl;
            cout << "3. Total values of product" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                S.sale();
                S.display();
                break;
            case 2:
                S.totalSale();
                break;
            case 3:
                S.totalValue();
                break;
            case 4:
                cout << "Thanks for using our system!!" << endl;
                break;
            default:
                cout << "Invalid choice!!" << endl;
                break;
            }

        } while (choice != 4);
    }
}
