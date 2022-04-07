#include <iostream>
#include <QCoreApplication>
#include "savedmessages.h"
#include "database.h"
#include "login.h"
#include "contactlist.h"
#include "custom.h"
using namespace std;

int main(int argc, char* argv[])
{
    //    QCoreApplication a(argc, argv); //Need to initialize

    ////Used to test the database class
    //        Database db("../../database.sqlite");
    //    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
    //    string values[] = {"4", "Lita", "pluss", "litat","0"};
    //  db.write("user",parameters,5,values);
    //    db.remove("user","name","Lita");

    ////Used to test the login class
    //        Login l("../../database.sqlite");
    //        l.signUp("hounasm","look");


    ////Used to test the saved messages
    //    SavedMessages s("../../database.sqlite");
    //    s.createMessage("Test","testing this message");
    //    s.deleteMessage("Test");


    ////Used to test the contact List
    //    ContactList cl;
    //    cl.getUserInput();


    //Used to test the Custom
    Custom cust;
    //cust.displayGuide();
    //cust.addBackground();
    //cust.levelUp();
    //cust.getLevel();
    cust.updateNotification();
    return 0;
}
