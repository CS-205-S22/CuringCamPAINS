#ifndef LOGGUI_H
#define LOGGUI_H

#include <QWidget>
#include "../Controller/log.h"

namespace Ui {
class LogGui;
}

class LogGui : public QWidget
{
    Q_OBJECT

public:
    explicit LogGui(QWidget *parent = nullptr);
    ~LogGui();

private slots:
    void on_pushButton_enter_clicked();

private:
    Ui::LogGui *ui;
};

#endif // LOGGUI_H
