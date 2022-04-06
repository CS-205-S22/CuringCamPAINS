#include <iostream>
#include <QCoreApplication>
#include "database.h"
#include "login.h"
#include "contactlist.h"
using namespace std;

int main(int argc, char* argv[])
{
//    //    QCoreApplication a(argc, argv); //Need to initialize
//    //        Database db("../../database.sqlite");
//    string parameters[] = {"userId", "name", "password", "userName","isResearcher"};
//    string values[] = {"4", "Lita", "pluss", "litat","0"};
//    //  db.write("user",parameters,5,values);
//    //    db.remove("user","name","Lita");
//    Login l("../../database.sqlite");
//    l.signUp("hounasm","look");

    ContactList cl;
    cl.getUserInput();

    return 0;
}
