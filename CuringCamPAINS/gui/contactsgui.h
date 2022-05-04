/**
 * @file: contactsgui.h
 * ------------------
 * @brief Defines the GUI functionality of the contacts page.
 *
 * @authors: Max Turkot, Oyu Gantumur
 * @version: 05/02/22
 */

#ifndef CONTACTSGUI_H
#define CONTACTSGUI_H

#include <QWidget>
#include <QMessageBox>
#include <QFileDialog>
#include "../Controller/contactlist.h"

namespace Ui {
class ContactsGui;
}

/**
 * @brief The ContactsGui class defines the functionality of the contacts GUI page.
 */
class ContactsGui : public QWidget
{
    Q_OBJECT

public:
     explicit ContactsGui(int cur, QWidget *parent = nullptr);
    ~ContactsGui();
    ContactList *contactList;
    int cur_usr;

private slots:
    /**
     * @brief on_pushButton_uploadFile_clicked saves contacts from a file.
     */
    void on_pushButton_uploadFile_clicked(); //when uploading a file

    /**
     * @brief on_pushButton_save_clicked saves a single manually entered contact.
     */
    void on_pushButton_save_clicked(); //when entering information manually

private:
    Ui::ContactsGui *ui;
};

#endif // CONTACTSGUI_H
