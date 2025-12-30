#pragma once //Directive that prevent file from being included multiple times in a single compilation
#include <string> 
using namespace std;

class Supermarket
{
protected:
	int product_id[100];
	string product_name[100];
	double product_price[100];
	int product_quantity[100];
	int count = 0;
	int total_sales = 0;
	double total_value = 0;
public:
	void addProduct(int add);
	void removeProduct();
	void sale();
	void totalSale();
	void display();
	void totalValue();
};

class User
{
private:
	string name;
	int id;
	string password;
public:
	void setName(string n);
	void setID(int i);
	void setPassword(string p);
	string getName();
	int getId();
	string getPassword();
};