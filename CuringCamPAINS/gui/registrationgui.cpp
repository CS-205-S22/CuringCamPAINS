/**
 * @file: registrationgui.cpp
 * ------------------
 * @brief Implements the GUI functionality of the registration page.
 *
 * @authors: Tafita Rakotozandry
 * @version: 05/02/22
 */

#include "registrationgui.h"
#include "ui_registrationgui.h"
#include <QDialog>
#include"QFileDialog"

registrationGUI::registrationGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationGUI)
{
    ui->setupUi(this);
     QPixmap pix("../../../../../CuringCamPAINS.png");
     int w=ui->logo->width();
     int h=ui->logo->height();
     ui->logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
     ui->logo->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
}

registrationGUI::~registrationGUI()
{
    delete ui;
}

/**
 * @brief on_buttonBox_accepted saves the new contact.
 */
void registrationGUI::on_buttonBox_accepted()
{
    dbb=new Database("../../../../../database.sqlite");
    string new_name=(ui->name->text()).toStdString();
    string new_username=(ui->username->text()).toStdString();
    string new_password=(ui->password->text()).toStdString();
    string temp=(ui->isResearcher->currentText()).toStdString();
    string new_isResearcher;
    if(temp=="researcher"){new_isResearcher=std::to_string(1);}
    else{new_isResearcher=std::to_string(0);}
    string new_id= std::to_string((dbb->getMaxId("user","userId"))+1);

    string parameters[]={"userId","name","password","userName","isResearcher"};
    string values[]={new_id, new_name,new_password,new_username,new_isResearcher};
    dbb->write("user",values);

}


/**
 * @brief on_buttonBox_accepted saves the new contact.
 */
void registrationGUI::on_uploadPhoto_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Upload Picture"), "/Desktop", tr("Upload Profile Picture (*.jpeg *.png)"));
    string outputName=(ui->name->text()).toStdString();
    string fname = fileName.toStdString();
    string outputAddress="../../../../../"+outputName+".jpeg";

        QFile::copy(QString::fromStdString(fname), QString::fromStdString(outputAddress));

}

