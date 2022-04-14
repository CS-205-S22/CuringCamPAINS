#ifndef REGISTRATIONGUI_H
#define REGISTRATIONGUI_H

#include <QDialog>
#include "dashboard.h"

namespace Ui {
class registrationGUI;
}

class registrationGUI : public QDialog
{
    Q_OBJECT

public:
    explicit registrationGUI(QWidget *parent = nullptr);
    ~registrationGUI();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::registrationGUI *ui;
    Database *dbb;
};

#endif // REGISTRATIONGUI_H
