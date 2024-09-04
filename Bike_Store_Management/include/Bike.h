#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <mysql.h>
#include <sstream>
#include <string>
#include "common.h"
#include "Suppliers.h"
using namespace std;
class Bike
{
    private:
    int id;			// Primary Key
	string name;
	string brand;
	long int price;
	int quantity;
    public:
        void add_bike();
        void update_price();
        void search_bike();
        void update_bike();
        void display_bike();
};

#endif // BIKE_H
