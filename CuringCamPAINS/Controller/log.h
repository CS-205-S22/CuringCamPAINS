#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>
#include <vector>
#include "database.h"
using namespace std;

class LogForm:public Database{
public:
    LogForm(string name);
    LogForm();
    //all of the get and set methods
    void clearLogForm();
    void editLogForm();
    void saveLogForm(string fullName, string age, string phoneNumber, string numOfAttempts,
                              string methodOfContact, string reaction, string dateContacted,
                              string isCommitted);
    void deleteLog(string phoneNumber);
    string boolToString(bool tof);
    int logId = 0;

//private:
    string name;
    string phoneNumber;
    string numOfAttempts;
    string age;
    string methodOfContact;
    string reaction;
    string date;
    string committed;
    string logInput[8];

    //int logId = 0;
};

//THIS MIGHT NOT BE NECESSARY SINCE WE ARE USING THE DATABASE
//class LogGui{
//public:

//    void clearLog();
//    void enterLogForm();

//private:
//    vector<LogForm> logForms;
//    int numOfContacts;
//};



//class Log
//{
//public:
//    Log();
//};

#endif // LOG_H
