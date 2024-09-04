#include <iostream>
#include <sstream>
#include <string>
#include <mysql.h>
#include <windows.h>
#include "Menu.h"

#define HOST "127.0.0.1"
#define USER "root"
#define PASS "123456"/*put the password of MySQL in here between ""*/
#define DATABASE "bike store managemnet"
#define PORT 3306

using namespace std;

int main()
{
    pass();
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0);
	int choice;
	if(conn)
    {
		while(1)
		{
			system("cls");
			main_menu();
		}
    }
	else
	{
	    system("cls");
		cout << "Error While connection to database." << endl << "Contact Tech Expert." << endl;
		getch();
	}
	return 0;
}
