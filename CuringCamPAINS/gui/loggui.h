#ifndef LOGGUI_H
#define LOGGUI_H

#include <QWidget>
#include <QMessageBox>
#include "../Controller/log.h"

namespace Ui {
class LogGui;
}

class LogGui : public QWidget
{
    Q_OBJECT

public:
    explicit LogGui(int usr,QWidget *parent = nullptr);
    ~LogGui();
    void autofill(string buttonName, string contactAge, string contactPN);

    void autofill();
    int cur_usr;

private slots:
    void on_pushButton_enter_clicked();

private:
    Ui::LogGui *ui;
    LogForm *logForm;
};

#endif // LOGGUI_H
