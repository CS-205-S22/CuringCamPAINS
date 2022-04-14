#include "dashboard.h"
#include "ui_dashboard.h"
//#include "contacts.h"

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

void Dashboard::on_pushButton_3_clicked()
{
    //ui->stackedWidget->setCurrentIndex(1);
}

void Dashboard::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Dashboard::on_resourcesButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Dashboard::on_contactsButton_clicked()
{
    //    Contacts contacts;
    //    contacts.setModal(true);
    //    contacts.exec();
}


void Dashboard::on_changeColor_clicked()
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    //set low alpha for transparency
    color.setAlpha(50);
    QString colName = color.name();
    QString style = "background-color: " + colName;
    this->setStyleSheet(style);
}


void Dashboard::on_createMessage_clicked()
{
    //will now prompt user to enter title and text of desired message
    cout << "nice job!!" << endl;
}




