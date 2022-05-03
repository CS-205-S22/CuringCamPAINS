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
//#include "logingui.h"

namespace Ui {
class AdminGui;
}

class AdminGui : public QWidget
{
    Q_OBJECT

public:
    explicit AdminGui(QWidget *parent = nullptr);
    ~AdminGui();

private slots:
    void on_pushButton_logs_clicked();

    void on_pushButton_contacts_clicked();

    void on_pushButton_logout_clicked();

private:
    Ui::AdminGui *ui;
    void displayList();
    QVBoxLayout *vLayout;
    LogForm *log;
};

#endif // ADMINGUI_H
