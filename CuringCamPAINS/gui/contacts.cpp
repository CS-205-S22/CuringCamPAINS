#include "contacts.h"
#include "ui_contacts.h"

Contacts::Contacts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contacts)
{
    ui->setupUi(this);
    contactList = new ContactList;

}

Contacts::~Contacts()
{
    delete ui;
}


void Contacts::on_pushButton_3_clicked()
{
    contactList->addContact((ui->lineEditFirstName->text()).toStdString(), (ui->lineEditLastName->text()).toStdString(),
                            (ui->lineEditPhone->text()).toStdString(), (ui->lineEditEmail->text()).toStdString(),
                            (ui->lineEditAddress->text()).toStdString(), (ui->lineEditAge->text()).toStdString());
}

