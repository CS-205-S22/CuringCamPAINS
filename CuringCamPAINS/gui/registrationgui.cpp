#include "registrationgui.h"
#include "ui_registrationgui.h"

registrationGUI::registrationGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationGUI)
{
    ui->setupUi(this);
}

registrationGUI::~registrationGUI()
{
    delete ui;
}

void registrationGUI::on_buttonBox_accepted()
{
    Database db("../../../../../database.sqlite");
    string new_name=(ui->name->text()).toStdString();
    string new_username=(ui->username->text()).toStdString();
    string new_password=(ui->password->text()).toStdString();
    string new_isResearcher=(ui->isResearcher->text()).toStdString();

    string new_id= std::to_string((db.getMaxId("user","userId"))+1);

    string parameters[]={"userId","name","password","userName","isResearcher"};
    string values[]={new_id, new_name,new_password,new_username,new_isResearcher};
    db.write("user",parameters,5,values);

}

