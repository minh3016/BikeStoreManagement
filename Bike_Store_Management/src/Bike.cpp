#include "Bike.h"
#include <mysql.h>
#include <iostream>
#include <sstream>
using namespace std;

extern MYSQL *conn;
void Bike::add_bike()
{

    cout << "Enter the name of the bike : " ;
	cin >> name;
	cout << "Enter the name of the brand : ";
	cin >> brand;
	cout << "Enter the Price : ";
	cin >> price;
	cout << "Enter the quantity Recived : ";
	cin >> quantity;
	stmt.str("");
	stmt << "Insert into bikes(name,brand,price,qty) values('" << name << "','" << brand << "'," << price << "," << quantity << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
        cout << endl << endl << "Bike Record Inserted Successfully" << endl << endl << endl;
    else
        cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
}
void Bike::update_price()
{
    char choice;
    cout << "Enter the id of the bike for update in price : ";
    cin >> id;
    stmt.str("");
    stmt << "Select name,price from bikes where id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
    if((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The Name of the bike is : " << row[0] << endl ;
        cout << "The current price of the bike is : " << row[1] << endl ;
        cout << "Do you Want to Update the Price [y/n] : " ;
    	cin >> choice;
		if (choice == 121 || choice == 89)
		{
			cout << "Enter the new price : ";
			cin >> price;
			stmt.str("");
			stmt << "Update bikes set price = " << price << " where id = " << id << ";";
			res_set = mysql_store_result(conn);
			if (!(res_set))
        		cout << endl << endl << "Bike Price Updated Successfully" << endl << endl << endl;
    		else
        		cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
		}
		else
		{
			cout << "No changes Made!!";
		}
	}
	else
	{
		cout << "No Bike found!!!";
	}

}
void Bike::update_bike()
{
    int b_id[100],qty[100],i = 0,max;
	stmt.str("");
	stmt << "Select bike_id,quantity from purchases where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	stmt.str("");
	stmt << "Update purchases set inv = 1 where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	while((row = mysql_fetch_row(res_set)) != NULL)
	{
		b_id[i] = (int) row[0];
		qty[i] = (int) row[1];
		i++;
	}
	max = i;
	for(i = 0; i <= max; i++)
	{
		stmt.str("");
    	stmt << "update bikes set quantity = " << qty[i] << " where id = " << b_id[i] << ";";
    	query = stmt.str();
    	q = query.c_str();
    	mysql_query(conn,q);
	}
	cout << "The orders recieved have been updated.";

}
void Bike::search_bike ()
{

    cout << "Enter bike id for details : ";
	cin >> id;
    stmt.str("");
    stmt << "Select * from bikes where id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn,q);
    res_set = mysql_store_result(conn);
    if((row = mysql_fetch_row(res_set)) != NULL)
    {
		cout << "The Details of Bike Id " << row[0] << endl;
        cout << "The Name of the bike is : " << row[1] << endl ;
		cout << "The Brans of " << row[1] << " is " << row[2] << endl;
        cout << "The Price of the bike is : " << row[3] << endl ;
		cout << "The inventory count is " << row[4] << endl;
	}
	else
	{
		cout << "No record Found" << endl;
	}
}
void Bike::display_bike()
{
    int i = 0;
	query = "Select * from bikes;";
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	while((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Name for bike " << ++i << " : " << row[1] << endl;
		cout << "Name of brand : " << row[2] << endl;
		cout << "Price : " << row[3] << endl;
		cout << "Quantity : " << row[4] << endl;
		cout << endl << endl << endl << endl ;
	}
}
