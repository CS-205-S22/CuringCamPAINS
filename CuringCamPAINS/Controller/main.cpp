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
    //        Database db("../../database.sqlite");
//    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
//    string values[] = {"4", "Lita", "pluss", "litat","0"};
    //  db.write("user",parameters,5,values);
    //    db.remove("user","name","Lita");
//    Login l("../../database.sqlite");
//    l.signUp("hounasm","look");

    //Saved Messages Testing:
//    SavedMessages s("../../database.sqlite");
//    s.createMessage("Test","testing this message");
//    s.deleteMessage("Test");


//    //    QCoreApplication a(argc, argv); //Need to initialize
//    //        Database db("../../database.sqlite");
//    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
//    string values[] = {"4", "Lita", "pluss", "litat","0"};
//    //  db.write("user",parameters,5,values);
//    //    db.remove("user","name","Lita");
//    Login login("../../database.sqlite");
//    login.signUp("hounasm","look");

//    ContactList cl;
//    cl.getUserInput();

    //Custom Testing:
Custom cust;
//cust.displayGuide();
//cust.addBackground();
//cust.levelUp();
//cust.getLevel();
cust.updateNotification();
    return 0;
}
