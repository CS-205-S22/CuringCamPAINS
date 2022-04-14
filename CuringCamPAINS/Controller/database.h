#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <map>
#include <filesystem>
#include <vector>
#include <string>
#include <stdlib.h>
#include <QtSql>
#include <QDir>

using namespace std;

class Database
{
protected:

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

    /**
     * @brief Database:write
     * Method to write file in the database
     * @param table_name : name of the table in the database
     * @param parameters: string array about the column names in the table
     * @param param_size number of columns in the table
     * @param values: string array about the values to be put into each column
     */
    void write(string table_name, string parameters[],int param_size,string values[] );
    vector<string> read(string table_name,string parameter,string conditions);
    /**
     * @brief Database:remove
     * Method to remove a row in the database based on a given condition
     * @param table_name : name of the table in the database
     * @param parameters: column name in the table
     * @param condition: values of the condition
     * Example: DELETE * FROM user where name="Tafita"
     * In this specific example table_name="user" , parameter=name , condition = "Tafita"
     */
    void remove(string table_name,string parameter,string condition);
    void check();
    /**
     * @brief Database:authenticate
     * Method to verify if a user with a certain username and passwrd is in the database
     * @param usr : the username
     * @param pwd : password
     */

    bool authenticate(QString usr, QString pwd);

    int getMaxId(string table_name,string id_name);
};

#endif // DATABASE_H
