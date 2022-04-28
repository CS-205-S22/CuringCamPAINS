#include "contactsgui.h"
#include "ui_contactsgui.h"

ContactsGui::ContactsGui(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ContactsGui) {
    ui->setupUi(this);
    ui->stackedWidget_contacts->setCurrentIndex(0);
    contactList = new ContactList("../../../../../database.sqlite");
}

ContactsGui::~ContactsGui() {
    delete ui;
}

void ContactsGui::on_pushButton_uploadFile_clicked() {
    contactList->readFile("../../../../contacts.csv");
}

void ContactsGui::on_pushButton_save_clicked() {
    contactList->addContact((ui->lineEdit_firstName->text()).toStdString(), (ui->lineEdit_lastName->text()).toStdString(),
                            (ui->lineEdit_phone->text()).toStdString(), (ui->lineEdit_email->text()).toStdString(),
                            (ui->lineEdit_address->text()).toStdString(), (ui->lineEdit_age->text()).toStdString());

    ui->lineEdit_firstName->clear();
    ui->lineEdit_lastName->clear();
    ui->lineEdit_phone->clear();
    ui->lineEdit_email->clear();
    ui->lineEdit_address->clear();
    ui->lineEdit_age->clear();
}

