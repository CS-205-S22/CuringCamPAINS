#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "../Controller/contactlist.h"
#include "../Controller/database.h"
#include <QMessageBox>
#include <QWidget>
#include "contacts.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dashboard; }
QT_END_NAMESPACE

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

     QMessageBox::StandardButton restart;

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_contactsButton_clicked();

private:
    Ui::Dashboard *ui;
};
#endif // DASHBOARD_H
