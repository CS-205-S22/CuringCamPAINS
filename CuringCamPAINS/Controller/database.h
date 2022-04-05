#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
#include <map>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

using namespace std;
#include <QtSql>

class Database
{
public:
    Database();
    void write();
    void read();
    void remove();
    void check();

    //maybe have an open? i might be confused but refer to slack for question
private:

};

#endif // DATABASE_H
