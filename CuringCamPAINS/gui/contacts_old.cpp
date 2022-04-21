#include "contacts_old.h"
#include "ui_contacts.h"

Contacts::Contacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);
    contactList = new ContactList("../../../../../database.sqlite");

}

Contacts::~Contacts() {
    delete ui;
}


void Contacts::on_saveButton_clicked()
{
    contactList->addContact((ui->lineEditFirstName->text()).toStdString(), (ui->lineEditLastName->text()).toStdString(),
                            (ui->lineEditPhone->text()).toStdString(), (ui->lineEditEmail->text()).toStdString(),
                            (ui->lineEditAddress->text()).toStdString(), (ui->lineEditAge->text()).toStdString());

    ui->lineEditFirstName->clear();
    ui->lineEditLastName->clear();
    ui->lineEditPhone->clear();
    ui->lineEditEmail->clear();
    ui->lineEditAddress->clear();
    ui->lineEditAge->clear();
}


void Contacts::on_uploadFile_clicked()
{
    contactList->readFile("../../../contacts.csv");
}


void Contacts::on_cancelButton_clicked()
{
    this->close();
}

