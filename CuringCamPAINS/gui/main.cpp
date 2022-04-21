#include "dashboard.h"
#include "logingui.h"
#include "contacts_old.h"
#include <QApplication>
#include "dashboardgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Run this if you want to demonstrate the login
//        Dashboard w;
//        w.show();
//        return a.exec();

//    //Run this only if you want to demonstrate the Login
        LoginGUI *l ;
        l=new LoginGUI();
        l->show();
       return a.exec();
}
