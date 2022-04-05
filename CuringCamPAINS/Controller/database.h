#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <map>
#include <filesystem>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;
#include <QtSql>

class Database
{
private:

    /// Name of the database.
    std::string db_name;

    /// Location of the database in the file structure.
    std::string db_location;

    QSqlDatabase *curr_db;

public:

//    // Constructor that if called will cause the program to exit
//    // indicating that more information should be provided.
    Database();

    // Constructors for loading a database file in the current
    // working directory.
    Database(std::string name);
    Database(const char* name);

    // Constructors for loading a database file in a specified
    // directory location.
    Database(std::string location, std::string name);
    Database(const char* location, const char* name);

    // Destructor that will cause the database to be closed storing
    // the updated contents of the sqlite file.
    ~Database();

    // Used to manually open the file, and called by each of the
    // constructors.
    int open_db();

    // prints state of database
    void print(std::ostream &sout);

    // provides a state check to determine if database is available
    bool db_open() { return curr_db ? true : false; }

    void runQuery(QString str);


    void write(string table_name, string parameters[],int param_size,string values[] );
    void read();
    void remove(string table_name,string parameters,string condition);
    void check();
    bool authenticate(QString usr, QString pwd);

};

#endif // DATABASE_H
