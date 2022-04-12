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
    //all of the get and set methods
    void clearLogForm();
    void editLogForm();
    void saveLogForm(string fullName, int age, string phoneNumber,
                     int numOfAttempts, string methodOfContact, string reaction,
                     string dateContacted, bool isCommitted);
    void deleteLog(string phoneNumber);
    string boolToString(bool tof);
    int logId = 0;

private:
    string name;
    string phoneNumber;
    int numOfAttempts;
    int age;
    vector<string> methodOfContact;
    vector<string> reaction;
    vector<string> date;
    bool committed;

    //int logId = 0;
};

//THIS MIGHT NOT BE NECESSARY SINCE WE ARE USING THE DATABASE
class Log{
public:

    void clearLog();
    void enterLogForm();

private:
    vector<LogForm> logForms;
    int numOfContacts;
};



//class Log
//{
//public:
//    Log();
//};

#endif // LOG_H
