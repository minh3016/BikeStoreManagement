#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <iostream>
#include <mysql.h>
#include <sstream>
#include <string>
#include "common.h"  // Include a common header for shared resources

using namespace std;
class Employees {
    int id;
    string name;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;
    long int phone;
    date date_of_joining;
    long int salary;
    string mgr_status;
public:
    void add_emp();
    void search_emp();
    void assign_mgr_stat();
    void display();
    void update_sal();
};

#endif // EMPLOYEES_H
