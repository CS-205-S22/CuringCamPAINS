#ifndef ADMINGUI_H
#define ADMINGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Controller/contactlist.h"

namespace Ui {
class AdminGui;
}

class AdminGui : public QWidget
{
    Q_OBJECT

public:
    explicit AdminGui(QWidget *parent = nullptr);
    ~AdminGui();

private slots:
    void on_pushButton_test_clicked();

private:
    Ui::AdminGui *ui;
    ContactList *contactList;
    vector<Contact*>* contacts;
    void displayList();
    QVBoxLayout *vLayout;
};

#endif // ADMINGUI_H
