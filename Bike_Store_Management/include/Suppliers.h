#ifndef SUPPLIERS_H
#define SUPPLIERS_H


#include <iostream>
#include <mysql.h>
#include <sstream>
#include <string>
#include "common.h"

using namespace std;
class Suppliers
{
    private:
    int id;				//Primary Key
	string name;
	long int phone;
	string addr_line1;
	string addr_line2;
	string addr_city;
	string addr_state;
    public:

        void add_supplier();
        void remove_supplier();
        void search_supplier();


};

#endif // SUPPLIERS_H
