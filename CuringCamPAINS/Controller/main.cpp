#include <iostream>
#include <QCoreApplication>
#include "savedmessages.h"
#include "database.h"
#include "login.h"
#include "contactlist.h"
#include "custom.h"
#include "log.h"
#include "csv.h"
using namespace std;

int main(int argc, char* argv[])
{

    ////Used to test the Log Class
    //LogForm log = LogForm();
    //log.saveLogForm("Joshua Garcia", 19, "1111111", 3, "text", "happy", "April 7th, 2022", false);

    //void LogForm::saveLogForm(string fullName, int age, string phoneNumber, int numOfAttempts,
    //string methodOfContact, string reaction, string dateContacted,
    //bool isCommitted){
    //        QCoreApplication a(argc, argv); //Need to initialize
    //        Database db("../../database.sqlite");



    LogForm log = LogForm("../../database.sqlite");
    log.readFromDB();

    for(int i=0;i<log.logCount();i++){
        for (int j=0;j<6;j++){
            string temp=log.logVector->at(i)->at(j);
            cout<<temp<<" ";
        }
        cout<<""<<endl;
    }

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
    //Database db("../../database.sqlite");
    //            int out=db.getMaxId("savedmessages","messageId");
    //            cout<<out<<endl;
    //    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
    //    string values[] = {"4", "Lita", "pluss", "litat","0"};
    //  db.write("user",parameters,5,values);
    //    db.remove("user","name","Lita");
    //    Login l("../../database.sqlite");
    //    l.signUp("hounasm","look");

    ///Saved Messages Testing:
    //        SavedMessages s(1,"../../database.sqlite");
    //        s.createMessage("Test","testing this message");
    //        vector<string> temp=s.readTitle("savedmessages","1","messageTitle");
    //        cout<<temp.at(0)<<endl;
    //        s.deleteMessage("Test");


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
    //            ContactList cl;
    //        cl.getUserInput();
    //            ContactList cl("../../database.sqlite");
    //            cl.remove("contact", "firstName", "Oyu");
    //            cl.remove("contact", "firstName", "Max");
    //            cl.remove("contact", "firstName", "Josh");
    //            cl.remove("contact", "firstName", "Tafita");
    //            cl.remove("contact", "firstName", "Rory");
    //            cl.remove("contact", "firstName", "Justin");
    //    cl.getUserInput();
    //    ContactList cl("../../test.sqlite");
    //    cl.remove("contact", "firstName", "Justin");
    //    cl.remove("contact", "firstName", "Matt");
    //    cl.remove("contact", "firstName", "Steve");


    //Used to test the Custom
    //Custom cust;
    //cust.displayGuide();
    //cust.addBackground();
    //cust.levelUp();
    //cust.getLevel();
    // cust.updateNotification();


    //    //Used to test the table to csv method
    //    Database db("../../database.sqlite");
    //    string parameters[]={"userId","name","password","userName","isResearcher"};
    //    int param_size=5;
    //    string outFile="../../test.csv";
    //    db.tableToCsv("user",parameters,param_size,outFile);

    //Used to test the csv table
    //    Csv test=Csv();
    //    string dbbName="../../database.sqlite";
    //    string parameters[]={"userId","name","password","userName","isResearcher"};
    //    int param_size=5;
    //    string outFile="../../test2.csv";
    ////    test.download(dbbName,"user",parameters,param_size,outFile);


    //    Database db("../../database.sqlite");
    //    cout<<db.getter("user","name","userId","1")<<endl;
    ////    db.updateColumn("user");
    //    db.tableToCsv("savedmessages","../../savedmessages.csv");

    //        Login db("../../database.sqlite");
    //        cout<<db.getUserId("rex")<<endl;


    //        QFile::copy("/Users/tafitarakoto/Desktop/_MG_3441.jpeg", "../../test.jpeg");
    //        QString fileName = QFileDialog::getOpenFileName(this,
    //                tr("Upload Picture"), "/Desktop", tr("Upload Profile Picture (*.jpeg *.png)"));
    //            string fname = fileName.toStdString();

    return 0;
}
