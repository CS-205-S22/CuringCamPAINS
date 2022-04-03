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
private:

};

#endif // DATABASE_H
