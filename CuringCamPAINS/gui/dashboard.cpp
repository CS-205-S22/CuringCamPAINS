#include "dashboard.h"
#include "ui_dashboard.h"
#include "contacts.h"

using namespace std;
//ContactList cList("../../database.sqlite");

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



void Dashboard::on_pushButton_3_clicked()
{
    QWidget* widget = new QWidget(this);
    //set to size of dashboard
    widget->setGeometry(0,0,1289,729);
    QColorDialog dialog;
    QPalette pal = QPalette();
    QColor color = dialog.getColor();
    //set low alpha for transparency
    color.setAlpha(50);
    pal.setColor(QPalette::Background, color);
    dialog.setAttribute(Qt::WA_TranslucentBackground);
    widget->setAutoFillBackground(true);
    widget->setPalette(pal);
    widget->show();
}

void Dashboard::on_contactsButton_clicked()
{
    Contacts contacts;
    contacts.setModal(true);
    contacts.exec();
}

