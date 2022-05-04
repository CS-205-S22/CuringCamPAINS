/**
 * @file: logingui.h
 * ------------------
 * @brief Defines the GUI functionality of the login page.
 *
 * @authors: Tafita Rakotozandry
 * @version: 05/02/22
 */

#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>
#include "dashboardgui.h"
#include "admingui.h"
#include "../Controller/login.h"
#include "../Controller/database.h"
#include "registrationgui.h"

class AdminGui;

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QDialog
{
    Q_OBJECT

public:
    explicit LoginGUI(QWidget *parent = nullptr);
    ~LoginGUI();
    int curr_usrId;


private slots:
    /**
     * @brief on_submission_pressed logs the user in.
     */
    void on_submission_pressed();

    /**
     * @brief on_registration_clicked opens the registration page.
     */
    void on_registration_clicked();


private:
    Ui::LoginGUI *ui;
    DashboardGui *dashboardGui;
    AdminGui *adminGui;
    registrationGUI *registration;
    Login *s;
};

#endif // LOGINGUI_H
