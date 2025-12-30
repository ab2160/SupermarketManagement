#include "Supermarket.h"
#include <iostream>
#include <iomanip>   // Library for set width(column)
#include <algorithm> // Library for changing letters to lower case
using namespace std;

void Supermarket::addProduct(int add) {
    for (int i = count; i < count + add && i < 100; i++)
    {
        cout << "Enter the name of the product: ";
        cin >> product_name[i];

        do
        {
            cout << "Enter the Id of the product: ";
            cin >> product_id[i];
            if (product_id[i] <= 0)
            {
                cout << "Invalid id!!" << endl;
            }
        } while (product_id[i] <= 0);
        do
        {
            cout << "Enter the price of the product: ";
            cin >> product_price[i];
            if (product_price[i] <= 0)
            {
                cout << "Invalid price input!!" << endl;
            }
        } while (product_price[i] <= 0);
        do
        {
            cout << "Enter the quantity of the product: ";
            cin >> product_quantity[i];
            if (product_quantity[i] <= 0)
            {
                cout << "Invalid quantity input!!" << endl;
            }
        } while (product_quantity[i] <= 0);
    }
    count = count + add;

    cout << "You have successfully added a product." << endl;
}

void Supermarket::removeProduct() {
    int r;
    int index = -1;
    cout << "Enter the product id you want to remove: ";
    cin >> r;
    for (int i = 0; i < count; i++)
    {
        if (product_id[i] == r)
        {
            index = i;
        }
    }

    if (index == -1)
    {
        cout << "Invalid product id." << endl;
        return;
    }

    for (int i = index; i < count - 1; i++)
    {
        product_id[i] = product_id[i + 1];
        product_name[i] = product_name[i + 1];
        product_price[i] = product_price[i + 1];
        product_quantity[i] = product_quantity[i + 1];
    }
    count--;
    cout << "You have successfully removed a product." << endl;
}

void Supermarket::sale()
{
    string name;
    int id, q;
    cout << "Enter the product name you want to sell: ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    cout << "Enter the product id you want to sell: ";
    cin >> id;

    bool found = false; // track if we found a match
    for (int i = 0; i < count; i++)
    {
        string stored_name = product_name[i];
        transform(stored_name.begin(), stored_name.end(), stored_name.begin(), ::tolower);
        if (product_id[i] == id && stored_name == name)
        {
            cout << "Enter the quantity of the product you want to sell: ";
            cin >> q;
            if (q <= product_quantity[i])
            {
                total_sales += product_price[i] * q;
                product_quantity[i] = product_quantity[i] - q;

                cout << "You have successfully sold a product." << endl;
            }
            else if (q > product_quantity[i])
            {
                cout << "Insufficient quantity. Available quantity is: " << product_quantity[i] << endl;
            }
            found = true;
            break; // stop once we’ve handled the sale
        }
    }

    if (!found)
    {
        cout << "Product not found!!" << endl;
    }
}

void Supermarket::totalSale()
{
    cout << "Total sale: " << total_sales << endl;
}

void Supermarket::display()
{
    cout << "=====================Products are========================" << endl;
    cout << left << setw(15) << "Product name" << setw(12) << "Product id"
        << left << setw(12) << "Price" << right << setw(7) << "Quantity" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << left << i + 1 << ". " << left << setw(15) << product_name[i]
            << setw(10) << product_id[i] << left << setw(10) << product_price[i]
            << right << setw(5) << product_quantity[i] << endl;
    }
}

void Supermarket::totalValue()
{
    total_value = 0; // Reset the value or it'll add up the price of the sold product too
    for (int i = 0; i < count; i++)
    {
        total_value += product_quantity[i] * product_price[i];
    }
    cout << "Total amount of price: " << total_value << endl;
}

void User::setName(string n)
{
    name = n;
}

void User::setID(int i)
{
    id = i;
}

void User::setPassword(string p)
{
    password = p;
}

string User::getName()
{
    return name;
}

int User::getId()
{
    return id;
}

string User::getPassword()
{
    return password;
}
