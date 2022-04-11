#ifndef REGISTRATIONGUI_H
#define REGISTRATIONGUI_H

#include <QDialog>

namespace Ui {
class registrationGUI;
}

class registrationGUI : public QDialog
{
    Q_OBJECT

public:
    explicit registrationGUI(QWidget *parent = nullptr);
    ~registrationGUI();

private:
    Ui::registrationGUI *ui;
};

#endif // REGISTRATIONGUI_H
