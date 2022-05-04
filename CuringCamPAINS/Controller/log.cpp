#include "log.h"

/**
 * @brief LogForm::LogForm
 * @param id
 * @param name
 * logForm constructor
 */
LogForm::LogForm(int id,string name):Database(name)
{
    usr_id=id;
    logVector=new vector<vector<string>*>();
}

/**
 * @brief LogForm::LogForm
 * @param name
 * logForm constructor
 */
LogForm::LogForm(string name):Database(name){
    logVector=new vector<vector<string>*>();
}

/**
 * @brief LogForm::LogForm
 * @param id
 * logForm constructor
 */
LogForm::LogForm(int id){
    usr_id=id;
    logVector=new vector<vector<string>*>();
}

/**
 * @brief LogForm::clearLogForm
 * This method sets all of the string variables to empty
 */
void LogForm::clearLogForm(){
    name = "";
    phoneNumber = "";
    numOfAttempts = "";
    methodOfContact = "";
    reaction = "";
    date = "";
    committed = "";
}

/**
 * @brief LogForm::boolToString
 * @param tof
 * @return string
 *
 * This function takes a boolean and returns
 * the string equivalent to that boolean.
 */
string LogForm::boolToString(bool tof){
    if(tof){
        return "true";
    }
    else{
        return "false";
    }
}

/**
 * @brief LogForm::saveLogForm
 * @param fullName
 * @param age
 * @param phoneNumber
 * @param numOfAttempts
 * @param methodOfContact
 * @param reaction
 * @param dateContacted
 * @param isCommitted
 *
 * This method takes the information from the user input (the parameters) and
 * saves it to the logForm table in the database. This also makes sure the
 * logId is valid and unique and it also gets the userId.
 */
void LogForm::saveLogForm(string fullName, string age, string phoneNumber, string numOfAttempts,
                          string methodOfContact, string reaction, string dateContacted,
                          string isCommitted){

    string logId = to_string(getMaxId("logForm", "logId")+1);
    string messages[] = {logId, std::to_string(usr_id),fullName, age, phoneNumber, numOfAttempts, methodOfContact,
                         reaction, dateContacted, isCommitted};
    write("logForm", messages);
    this->logId++;
}

/**
 * @brief LogForm::deleteLog
 * @param phoneNumber
 * This method takes a phoneNumber and removes all of the entries with
 * that phoneNumber from the logForm table in the database.
 */
void LogForm::deleteLog(string phoneNumber){
    remove("logForm", "phoneNumber", phoneNumber);
}

/**
 * @brief LogForm:readFromDB
 * Read the data from the logForm Database and save them in the logVector
 */
void LogForm::readFromDB() {
    QSqlQuery query;
    QString str = "select * from logForm ;";
    if (!query.exec(str)){
        qDebug()<<"error running query\n";
    } else {
        while (query.next()) {

            string logId = query.value("logId").toString().toStdString();
            string userId=query.value("userId").toString().toStdString();
            string user_Name=getter("user","name","userId",userId);
            string fullName=query.value("fullName").toString().toStdString();
            string age=query.value("age").toString().toStdString();
            string phoneNumber=query.value("phoneNumber").toString().toStdString();
            string numOfAttempts = query.value("numOfAttempts").toString().toStdString();
            string methodOfContact= query.value("methodOfContact").toString().toStdString();
            string reaction =query.value("reaction").toString().toStdString();
            string dateContacted =query.value("dateContacted").toString().toStdString();
            vector<string>*temp = new vector<string>;

            temp->push_back(logId);
            temp->push_back(user_Name);
            temp->push_back(fullName);
            temp->push_back(age);
            temp->push_back(phoneNumber);
            temp->push_back(numOfAttempts);
            temp->push_back(methodOfContact);
            temp->push_back(reaction);
            temp->push_back(dateContacted);

            logVector->push_back(temp);
        }

    }
}

/**
 * @brief LogForm:logCount
 * Count the data in the logForm database
 */
int  LogForm::logCount() {
    QSqlQuery query;
    QString str = "select count(*) from logForm ;";
    query.exec(str);
    query.next();
    return stoi(query.value(0).toString().toStdString());
}
