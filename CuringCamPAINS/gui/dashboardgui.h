#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include "contactsgui.h"
#include "loggui.h"
#include "resourcesgui.h"

namespace Ui {
class DashboardGui;
}

class DashboardGui : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardGui(QWidget *parent = nullptr);
    ~DashboardGui();

private slots:
    void on_pushButton_dashboard_clicked();

    void on_pushButton_contacts_clicked();

    void on_pushButton_resources_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_data_clicked();

    void on_pushButton_log_clicked();

private:
    Ui::DashboardGui *ui;
    ContactsGui *contactsGui = new ContactsGui();
    LogGui *logGui = new LogGui();
    ResourcesGui *resourcesGui = new ResourcesGui();
};

#endif // DASHBOARDGUI_H
