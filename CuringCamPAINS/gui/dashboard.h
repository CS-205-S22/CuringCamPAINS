#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "../Controller/contactlist.h"
#include "../Controller/database.h"
#include <QMessageBox>
#include <QWidget>
#include <QColorDialog>


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

    //void on_pushButton_clicked();

    //void on_pushButton_3_clicked();
    void on_contactsButton_clicked();

    void on_createMessage_clicked();

    void on_resourcesButton_clicked();

    void on_changeColor_clicked();

    void on_saveMessage_clicked();

    void on_dashboardButton_clicked();

    void on_viewMessage_clicked();

    void on_viewButton_clicked();

    void on_deleteButton_clicked();

    void on_deleteMessage_clicked();

    void on_backButton_clicked();

private:
    Ui::Dashboard *ui;

    string title, text;
};
#endif // DASHBOARD_H
