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

}

void LogForm::saveLogForm(){
    //this will write everything to the database
}



