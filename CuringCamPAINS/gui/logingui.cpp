#include "logingui.h"
#include "ui_logingui.h"
#include "dashboard.h"
#include <QMessageBox>

LoginGUI::LoginGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
}

LoginGUI::~LoginGUI()
{
    delete ui;
}

void LoginGUI::on_submission_pressed()
{
    QString usr = ui->lineEdit_usr->text();
    QString pwd = ui->lineEdit_pwd->text();
    string username=usr.toStdString();
    string password=pwd.toStdString();

    s = new Login("../../../../../database.sqlite");
    //        s.signUp("hounasm","look");
    //        s.close();

    //    if(username ==  "test" && password == "test") {
    if(s->signUp(username,password)==true) {
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        dashBoard=new Dashboard(this);
        dashBoard->show();

    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}

void LoginGUI::on_registration_clicked()
{
    registration=new registrationGUI(this);
    registration->show();

}

