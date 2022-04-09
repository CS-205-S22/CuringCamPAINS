#include "dashboard.h"
#include "ui_dashboard.h"

using namespace std;


Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Dashboard::~Dashboard()
{
    delete ui;
}


void Dashboard::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void Dashboard::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dashboard::on_pushButton_2_clicked()
{
//    ContactList cList("../../../../database.sqlite");
//    cList.readFile("../../../contacts.csv");

//    restart = QMessageBox::information(this, "Status update",
//                                       "Contact upload is successful!\n",
//                                       QMessageBox::Yes | QMessageBox::No );
//    if (restart == QMessageBox::Yes) {
////        cList.remove("contact", "firstName", "Oyu");
////        cList.remove("contact", "firstName", "Max");
////        cList.remove("contact", "firstName", "Josh");
////        cList.remove("contact", "firstName", "Tafita");
////        cList.remove("contact", "firstName", "Rory");
//        close();
//    }
}

