#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>
#include "dashboardgui.h"
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

    void on_test_clicked();

private:
    Ui::LoginGUI *ui;
    DashboardGui *dashboardGui;
    registrationGUI *registration;
    Login *s;

};

#endif // LOGINGUI_H
