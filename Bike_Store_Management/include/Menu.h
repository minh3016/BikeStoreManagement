#ifndef MENU_H
#define MENU_H

#include "Bike.h"
#include "Suppliers.h"
#include "Purchase.h"
#include "Employees.h"
#include "Members.h"
#include "sales.h"
#include "common.h"
#include <sstream>
#include <mysql.h>
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Menu
{
    public:
    void main_menu();
    void bike_menu();
    void sup_menu();
    void pur_menu();
    void em_menu();
    void mem_menu();
    void sale_menu();
    void password();


};

#endif // MENU_H
