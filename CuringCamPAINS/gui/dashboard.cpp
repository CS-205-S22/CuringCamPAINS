#include "dashboard.h"
#include "ui_dashboard.h"

using namespace std;
ContactList cList("../../database.sqlite");

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

}

