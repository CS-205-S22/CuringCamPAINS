#ifndef CONTACTS_H
#define CONTACTS_H

#include <QDialog>
#include "../Controller/contactlist.h"

namespace Ui {
class Contacts;
}

class Contacts : public QDialog
{
    Q_OBJECT

public:
    explicit Contacts(QWidget *parent = nullptr);
    ~Contacts();
    ContactList *contactList;

private slots:

    void on_pushButton_3_clicked();

private:
    Ui::Contacts *ui;
};

#endif // CONTACTS_H
