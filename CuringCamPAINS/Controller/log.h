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
    LogForm();
    void clearLogForm();
    void saveLogForm(string fullName, string age, string phoneNumber, string numOfAttempts,
                     string methodOfContact, string reaction, string dateContacted,
                     string isCommitted);
    void deleteLog(string phoneNumber);
    string boolToString(bool tof);

    /**
     * @brief LogForm:readFromDB
     * Read the data from the logForm Database and save them in the logVector
     */
    void readFromDB();
    int logId = 0;
    int usr_id;
    /**
     * @brief LogForm:logCount
     * Count the data in the logForm database
     */
    int logCount();
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
};

#endif // LOG_H
