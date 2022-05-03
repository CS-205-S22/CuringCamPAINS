#include "logingui.h"
#include <QApplication>
#include "dashboardgui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    //Run this only if you want to demonstrate the Login
        LoginGUI *l ;
        l=new LoginGUI();
        l->show();
       return a.exec();
}
