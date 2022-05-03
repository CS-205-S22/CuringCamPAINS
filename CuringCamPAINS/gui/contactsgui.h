#ifndef CONTACTSGUI_H
#define CONTACTSGUI_H

#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include "../Controller/contactlist.h"

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
    void on_pushButton_uploadFile_clicked(); //when uploading a file

    void on_pushButton_save_clicked(); //when entering information manually

private:
    Ui::ContactsGui *ui;
};

#endif // CONTACTSGUI_H
