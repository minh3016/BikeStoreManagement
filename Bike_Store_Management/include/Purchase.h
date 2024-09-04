#ifndef PURCHASE_H
#define PURCHASE_H

#include <iostream>
#include <mysql.h>
#include <sstream>
#include "common.h"  // Include a common header for shared resources

using namespace std;
class purchases {
    int ord_id;
    int bike_id;
    int sup_id;
    int quantity;
    date dt_ordered;
    int eta;
    char received;
    int inv;
public:
    void new_ord();
    void view();
    void mar_cancel();
    void mark_reciv();
};

#endif // PURCHASES_H
