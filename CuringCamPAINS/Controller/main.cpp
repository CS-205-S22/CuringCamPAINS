#include <iostream>
#include <QCoreApplication>
#include "savedmessages.h"
#include "database.h"
#include "login.h"
#include "contactlist.h"
#include "custom.h"
#include "log.h"
using namespace std;

int main(int argc, char* argv[])
{

    ////Used to test the Log Class
    //LogForm log = LogForm();
    //log.saveLogForm("Joshua Garcia", 19, "1111111", 3, "text", "happy", "April 7th, 2022", false);

    //void LogForm::saveLogForm(string fullName, int age, string phoneNumber, int numOfAttempts,
                              //string methodOfContact, string reaction, string dateContacted,
                              //bool isCommitted){
        QCoreApplication a(argc, argv); //Need to initialize
        Database db("../../database.sqlite");

        //LogForm log = LogForm("../../database.sqlite");
        //log.saveLogForm("Joshua Garcia", 19, "1111112", 3, "text", "unsure", "April 7th, 2022", false);
        //log.saveLogForm("Oyu Gantumur", 21, "2222222", 8, "text", "excited", "March 7th, 2022", false);
        //log.saveLogForm("Max Turkot", 20, "3333333", 1, "text", "happy", "January 5th, 2022", false);
        //log.saveLogForm("Tafita", 21, "4444444", 1, "text", "happy", "January 5th, 2022", true);
        //log.deleteLog("2222222");



//        db.remove("contact", "firstName", "Tafita");
//    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
//    string values[] = {"4", "Lita", "pluss", "litat","0"};
    //    QCoreApplication a(argc, argv); //Need to initialize

    ////Used to test the database class
    //        Database db("../../database.sqlite");
    //    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
    //    string values[] = {"4", "Lita", "pluss", "litat","0"};
    //  db.write("user",parameters,5,values);
    //    db.remove("user","name","Lita");
//    Login l("../../database.sqlite");
//    l.signUp("hounasm","look");

    ///Saved Messages Testing:
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
//Custom cust;
//cust.displayGuide();
//cust.addBackground();
//cust.levelUp();
//cust.getLevel();
//cust.updateNotification();

    ////Used to test the login class
//            Login l("../../database.sqlite");
//            l.signUp("hounasm","look");


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
    //Custom cust;
    //cust.displayGuide();
    //cust.addBackground();
    //cust.levelUp();
    //cust.getLevel();
   // cust.updateNotification();

    return 0;
}
