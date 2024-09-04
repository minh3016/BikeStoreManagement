#ifndef COMMON_H
#define COMMON_H

#include <mysql.h>
#include <string>
#include <sstream>

using namespace std;
extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char *q;
extern string query;

typedef struct {
    int date;
    int month;
    int year;
} date;

#endif // COMMON_H
