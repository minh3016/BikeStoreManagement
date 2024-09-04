#ifndef MEMBERS_H
#define MEMBERS_H

#include <iostream>
#include <mysql.h>
#include <sstream>
#include <string>
#include "common.h"  // Include a common header for shared resources

using namespace std;
class Members {
    int id;
    string name;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;
    long int phone;
    date beg_date;
    date end_date;
    string valid;
public:
    void add_mem();
    void refresh();
    void search_mem();
};

#endif // MEMBERS_H
