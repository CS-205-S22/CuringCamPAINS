#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>
#include "dashboardgui.h"
#include "admingui.h"
#include "../Controller/login.h"
#include "../Controller/database.h"
#include "registrationgui.h"

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
    void on_submission_pressed();

    void on_registration_clicked();


private:
    Ui::LoginGUI *ui;
    DashboardGui *dashboardGui;
    AdminGui *adminGui;
    registrationGUI *registration;
    Login *s;
};

#endif // LOGINGUI_H
