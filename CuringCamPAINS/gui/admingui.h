#ifndef ADMINGUI_H
#define ADMINGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../Controller/contactlist.h"
#include <QMessageBox>
#include <QPixmap>
#include "../Controller/csv.h"
#include <QDialog>
#include <QFileDialog>

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

    void on_pushButton_data_clicked();

private:
    Ui::AdminGui *ui;
    ContactList *contactList;
    vector<Contact*>* contacts;
    void displayList();
    QVBoxLayout *vLayout;
};

#endif // ADMINGUI_H
