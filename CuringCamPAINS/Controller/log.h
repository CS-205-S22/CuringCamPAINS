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
    LogForm(int usr_id,string name);
    LogForm(int usr_id);
    //all of the get and set methods
    void clearLogForm();
    void editLogForm();
    void saveLogForm(string fullName, string age, string phoneNumber, string numOfAttempts,
                     string methodOfContact, string reaction, string dateContacted,
                     string isCommitted);
    void deleteLog(string phoneNumber);
    string boolToString(bool tof);
    void readFromDB();
    int logId = 0;
    int usr_id;

    vector<vector<string>*> *logVector;
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

#endif // LOG_H
