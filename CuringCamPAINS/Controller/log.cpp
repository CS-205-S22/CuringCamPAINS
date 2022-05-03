#include "log.h"

LogForm::LogForm(int id,string name):Database(name)
{
usr_id=id;
}

LogForm::LogForm(int id){
usr_id=id;
}

void LogForm::clearLogForm(){
    name = "";
    phoneNumber = "";
    numOfAttempts = "";
    methodOfContact = "";
    reaction = "";
    date = "";

    //should committed = NULL?
    committed = "";
}

void LogForm::editLogForm(){
    //this will take input from the gui and then when the organizer
    //edits the information, it will be saved back to the database
    //once the organizer has entered the phone number

    //this should also show the information that was already in the log form
    //you could convert the vector into strings and then the strings are what
    //will be saved in the database


    //EACH INTERACTION SHOULD BE ITS OWN ROW ON THE DATABASE!!!!
    //then maybe somehow you can group those for one specific person (group all of them by their phoneNumber since that is unique to each person)

    //For when we are trying to display it, save the reactions to a vector<string> as well as the database so
    //that when we have to display it, we can just use the vector instead of going through the database

    string cols[] = {"logId","methodOfContact", "numOfAttempts", "name", "age", "phoneNumber", "reaction", "date", "committed"};

    //string messages[] = {messageId, title, message};
    //write("log", cols, 9, messages);
    //this->messageId++;
}

string LogForm::boolToString(bool tof){
    if(tof){
        return "true";
    }
    else{
        return "false";
    }
    //return( "" );
}

void LogForm::saveLogForm(string fullName, string age, string phoneNumber, string numOfAttempts,
                          string methodOfContact, string reaction, string dateContacted,
                          string isCommitted){

    //NEED TO MAKE SURE THE ID IS DIFFERENT (Go through the ID's in the database


    //string logId = to_string(this->logId);
    string logId = to_string(getMaxId("logForm", "logId")+1);

    string messages[] = {logId, std::to_string(usr_id),fullName, age, phoneNumber, numOfAttempts, methodOfContact,
                         reaction, dateContacted, isCommitted};
    write("logForm", messages);
    //this->logId = getMaxId("logForm", "logId");
    this->logId++;
}

void LogForm::deleteLog(string phoneNumber){
    remove("logForm", "phoneNumber", phoneNumber);
}

//void LogGui::clearLog() {

//}

//void LogGui::enterLogForm() {

//}


void LogForm::readFromDB() {
    QSqlQuery query;
    QString  temp = QString::fromStdString(std::to_string(usr_id));
    QString str = "select * from logForm where userId = " + temp + ";";
//    QString str = "select * from contact";
    int id;
    int listId;
    int currUserId;
    string firstName;
    string lastName;
    string cellStr;
    string email;
    string homeAdd;
    int age;

    if (!query.exec(str)){
        qDebug()<<"error running query\n";
    } else {
        while (query.next()) {
            id = stoi(query.value("contactId").toString().toStdString());
            listId = stoi(query.value("treatmentId").toString().toStdString());
            currUserId = stoi(query.value("userId").toString().toStdString());
            firstName = query.value("firstName").toString().toStdString();
            lastName = query.value("lastName").toString().toStdString();
            cellStr = query.value("phoneNumber").toString().toStdString();
            email = query.value("emailAddress").toString().toStdString();
            homeAdd = query.value("homeAddress").toString().toStdString();
            age = stoi(query.value("age").toString().toStdString());

//            cerr << "NAME: " << firstName << endl;

//            if (!containsContact(cellStr)) {
//                Contact* c = new Contact(usr_id, id, listId, firstName, lastName, cellStr, email, homeAdd, age);
//                masterList->push_back(c);
//                divideIntoGroups(c);
//            }
        }
    }
}
