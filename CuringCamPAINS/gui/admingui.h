/**
 * @file: admingui.h
 * ------------------
 * @brief Defines the GUI functionality of the admin page.
 *
 * @authors: Max Turkot, Tafita Rakotkzandry
 * @version: 05/02/22
 */

#ifndef ADMINGUI_H
#define ADMINGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include "../Controller/csv.h"
#include <QDialog>
#include <QFileDialog>
#include "../Controller/log.h"
#include "logingui.h"

class LoginGui;

namespace Ui {
class AdminGui;
}

class AdminGui : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief AdminGui Contstructs the adminGui objects.
     * @param usr_id Id of the user running the software.
     * @param parent parent class, nullptr by default.
     */
    explicit AdminGui(int usr_id,QWidget *parent = nullptr);

    /**
     * @brief Destructs the AdminGui objects.
     */
    ~AdminGui();

private slots:
    /**
     * @brief on_pushButton_logs_clicked downloads log data to a specified csv file.
     */
    void on_pushButton_logs_clicked();

    /**
     * @brief on_pushButton_contacts_clicked downloads contact data to a specified csv file.
     */
    void on_pushButton_contacts_clicked();

    /**
     * @brief on_pushButton_logout_clicked logs out of the admin account.
     */
    void on_pushButton_logout_clicked();

private:
    Ui::AdminGui *ui;
    QVBoxLayout *vLayout;
    LogForm *log;
    int cur_usrId;

    /**
     * @brief displayList displays the list of logs to the admin dashboard.
     */
    void displayList();
};

#endif // ADMINGUI_H
