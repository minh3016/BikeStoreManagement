#include "Purchase.h"

#include <mysql.h>
#include <iostream>
#include <sstream>

using namespace std;

extern MYSQL *conn;

void purchases::new_ord()
{
    cout << "Enter the book Id : ";
	cin >> bike_id;
	cout << "Enter Supplier Id : ";
	cin >> sup_id;
	cout << "Enter the Quantity : ";
	cin >> quantity;
	cout << "Estimated expected Delivery (in days) : ";
	cin >> eta;
	stmt.str("");
	stmt << "Insert into purchases (bike_id,sup_id,quantity,dt_ord,eta) values ( " << bike_id << "," << sup_id << "," << quantity << ",curdate(),Date_add(curdate(), INTERVAL " << eta << " DAY)" << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	cout << "New order Added!!";
}
void purchases ::view()
{
    int c;
	cout << "Select an Option" << endl;
	cout << "1. View orders not Recieved" << endl;
	cout << "2. View orders Cancelled" << endl;
	cout << "3. View orders Recieved" << endl;
	cout << "Enter Your choice : ";
	cin >> c;
	if (c == 1)
		received = 'F';
	else if (c == 2)
		received = 'C';
	else if (c == 3)
		received = 'T';
	else
		return;
	stmt.str("");
	stmt << "Select * from purchases where recieved = '" << received << "';";
	query  = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	res_set = mysql_store_result(conn);
	if (c == 1)
		cout << endl << "Orders not recieved are" << endl;
	else if (c == 2)
		cout << endl << "Orders Cancelled are" << endl;
	else if (c == 3)
		cout << endl << "Orders recieved are" << endl;
	while((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << endl;
		cout << "Order Id : " << row[0] << endl;
		cout << "Bike Id : " << row[1] << endl;
		cout << "Supplier Id :" << row[2] << endl ;
		cout << "Quantity : " << row[3] << endl;
		cout << "Date Ordered : " << row[4] << endl;
		cout << "Estimated Delivery date : " << row[5] << endl;
		cout << endl << endl << endl;
	}
	cout <<endl << endl << endl <<endl << endl;
}
void purchases::mark_reciv()
{
    cout << "Enter the order id for order recieved : ";
	cin >> ord_id;
	stmt.str("");
	stmt << "Update puchases set recieved = 'T' where ord_id = " << ord_id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	cout << "Recieved Marked successfully";
}
void purchases ::mar_cancel()
{
    cout << "Enter the order id for order cancelled : ";
	cin >> ord_id;
	stmt.str("");
	stmt << "Update puchases set recieved = 'C' where ord_id = " << ord_id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn,q);
	cout << "Cancelled Marked successfully";
}
