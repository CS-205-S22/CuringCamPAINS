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
<<<<<<< HEAD
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
//cust.updateNotification();
=======

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
    //    ContactList cl("../../database.sqlite");
    //    cl.remove("contact", "firstName", "Oyu");
    //    cl.remove("contact", "firstName", "Max");
    //    cl.remove("contact", "firstName", "Josh");
    //    cl.remove("contact", "firstName", "Tafita");
    //    cl.remove("contact", "firstName", "Rory");
    //    cl.remove("contact", "firstName", "Justin");
    //    cl.getUserInput();


    //Used to test the Custom
    Custom cust;
    //cust.displayGuide();
    //cust.addBackground();
    //cust.levelUp();
    //cust.getLevel();
    cust.updateNotification();

>>>>>>> f1f34014cb719353bd70cb62627426f4670f6e5f
    return 0;
}
