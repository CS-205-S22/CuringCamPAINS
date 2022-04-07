#include "log.h"

void LogForm::clearLogForm(){
    name = "";
    phoneNumber = "";
    numOfAttempts = 0;
    methodOfContact.clear();
    reaction.clear();
    date.clear();

    //should committed = NULL?
    committed = false;
}

void LogForm::editLogForm(){
    //once the organizer has entered the phone number
    string cols[] = {"logId","methodOfContact", "numOfAttempts", "name", "age", "phoneNumber", "reaction", "date", "committed"};

    //string messages[] = {messageId, title, message};
    //write("log", cols, 9, messages);
    //this->messageId++;
}

void LogForm::saveLogForm(){
    //this will write everything to the database
    string cols[] = {"logId","methodOfContact", "numOfAttempts", "name", "age", "phoneNumber", "reaction", "date", "committed"};

    //string messages[] = {messageId, title, message};
    //write("log", cols, 9, messages);
    //this->messageId++;
}



