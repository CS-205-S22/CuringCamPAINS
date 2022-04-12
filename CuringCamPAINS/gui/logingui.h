#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QDialog>
#include "dashboard.h"
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


private slots:
    void on_submission_pressed();

    void on_registration_clicked();

private:
    Ui::LoginGUI *ui;
    Dashboard *dashBoard;
    registrationGUI *registration;

};

#endif // LOGINGUI_H
