#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <string>
#include <vector>
#include "database.h"
using namespace std;

class LogForm{
public:
    //all of the get and set methods
    void clearLogForm();
    void editLogForm();
    void saveLogForm();
private:
    string name;
    string phoneNumber;
    int numOfAttempts;
    vector<string> methodOfContact;
    vector<string> reaction;
    vector<string> date;
    bool committed;
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
