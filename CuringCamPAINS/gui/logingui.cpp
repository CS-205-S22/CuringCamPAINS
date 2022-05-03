#include "logingui.h"
#include "ui_logingui.h"
#include <QMessageBox>
#include <QPixmap>
LoginGUI::LoginGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
    QPixmap pix("../../../../../CuringCamPAINS.png");
    int w=ui->logo->width();
    int h=ui->logo->height();
    ui->logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->logo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

//    ui->logo->setPixmap(pix.scaled(w,h));

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
    if(s->signUp(username, password) == true) {
        curr_usrId = s->getUserId(username);
//        if (s->getIsResearcher()) {
//            adminGui = new AdminGui();
//            hide();
//            adminGui->show();
//        } else {
            dashboardGui = new DashboardGui(curr_usrId);
            hide();
            dashboardGui->show();
//        }
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}

void LoginGUI::on_registration_clicked()
{
    registration = new registrationGUI(this);
    registration->show();
}

void LoginGUI::on_test_clicked()
{

}

