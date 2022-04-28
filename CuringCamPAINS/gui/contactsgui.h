#ifndef CONTACTSGUI_H
#define CONTACTSGUI_H

#include <QWidget>
#include "../Controller/contactlist.h"
// #include "../Controller/database.h"

namespace Ui {
class ContactsGui;
}

class ContactsGui : public QWidget
{
    Q_OBJECT

public:
     explicit ContactsGui(int cur, QWidget *parent = nullptr);
    ~ContactsGui();
    ContactList *contactList;
    int cur_usr;

private slots:
    void on_pushButton_uploadFile_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::ContactsGui *ui;
};

#endif // CONTACTSGUI_H
