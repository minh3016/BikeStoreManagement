#include "sales.h"
#include <mysql.h>
#include <iostream>
#include <sstream>
using namespace std;

extern MYSQL *conn; // Declaring external MYSQL connection object

void sales::add() {
    // Implement the add method
    cout << "Enter Menber id :";
	cin >> member_id;
	cout << "Enter the book id : ";
	cin  >> bike_id;
	cout << "Enter the quantity : ";
	cin  >> quantity;
	stmt.str("");
	stmt << "select price*" << quantity << " from books where id = " << bike_id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The bill amount : " << row[0] << endl << endl;
		amount = (int) row[0];
	}
	else
	{
		cout << "Bike Id invalid!!" << endl;
		getch();
		return;
	}
	stmt.str("");
	stmt << "insert into sales(mem_id,bike_id,quantity,amt,sales_date) values (" << member_id << "," << bike_id << "," << quantity << "," << amount << ",curdate());";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	// fetching invoice id...
	stmt.str("");
	stmt << "select inv_id from sales where mem_id = " << member_id << " AND book_id = " << bike_id << " AND qty = " << quantity << " AND sales_date = curdate();";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Invoice id for the bill is " << row[0] << endl << endl << endl;
	}
	else
	{
		cout << "The entered details maybe wrong." << endl << "Please Recheck and Enter again" << endl << endl << endl;
	}
}

void sales::find_total_sales()
{
    query = "select sum(amt) from sales where year(sales_date) = year(curdate());";
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Total sales this year : " << row[0] << endl << endl << endl << endl;
	}
}
