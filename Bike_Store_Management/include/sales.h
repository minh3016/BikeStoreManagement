#ifndef SALES_H
#define SALES_H

#include <iostream>
#include <mysql.h>
#include <sstream>
#include "common.h"  // Include a common header for shared resources

using namespace std;
class sales {
    int invoice_id;
    int member_id;
    int bike_id;
    int quantity;
    int amount;
    date date_s;
public:
    void add();
    void find_total_sales();
};

#endif // SALES_H
