#include "dashboard.h"
#include "ui_dashboard.h"
#include "../Controller/savedmessages.h"
//#include "contacts.h"

using namespace std;
//ContactList cList("../../database.sqlite");
SavedMessages sm("../../../../../database.sqlite");

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
    QString colName = color.name();
    int r, g, b;
    char const *hexColor = colName.toUtf8().data();
    std::sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);
    string feed = "background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ")";
    QString style = QString::fromUtf8(feed.c_str());
    setStyleSheet(style);
}


void Dashboard::on_createMessage_clicked()
{
    //will now prompt user to enter title and text of desired message
    ui->stackedWidget->setCurrentIndex(2);
}


void Dashboard::on_saveMessage_clicked()
{
    this->title = ui->inputTitle->text().toStdString();
    this->text = ui->inputText->text().toStdString();
    //call saved messages create message
    sm.createMessage(this->title, this->text);
    ui->inputTitle->clear();
    ui->inputText->clear();
    ui->stackedWidget->setCurrentIndex(1);
}


void Dashboard::on_dashboardButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dashboard::on_viewMessage_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void Dashboard::on_viewButton_clicked()
{
    this->title = ui->inputTitle_2->text().toStdString();
    vector<string> toView = sm.viewMessage(this->title);
    if (toView.empty()) {
        ui->displayText->setText("No messages with input title.");
    } else {
        QString insert;
        for (int i = 0; i < (int)toView.size(); i++) {
            insert += QString::fromUtf8(toView.at(i).c_str()) + " ";
        }
        ui->displayText->setText(insert);
    }
    ui->inputTitle_2->clear();
}


void Dashboard::on_deleteButton_clicked()
{
    this->title = ui->inputTitle_3->text().toStdString();
    sm.deleteMessage(this->title);
    ui->inputTitle_3->clear();
    ui->stackedWidget->setCurrentIndex(1);
}


void Dashboard::on_deleteMessage_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void Dashboard::on_backButton_clicked()
{
    ui->displayText->clear();
    ui->stackedWidget->setCurrentIndex(1);
}

