#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include "contactsgui.h"
#include "loggui.h"
#include "resourcesgui.h"
#include "dynamicbutton.h"
#include "../Controller/csv.h"

using namespace std;
namespace Ui {
class DashboardGui;
}

class DashboardGui : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardGui(int userId,QWidget *parent = nullptr);
    void deleteButtons();
    void displayButtons();
    ~DashboardGui();
    Contact* con;

private slots:
    void openLogForm();

    void on_pushButton_dashboard_clicked();

    void on_pushButton_contacts_clicked();

    void on_pushButton_resources_clicked();

    void on_pushButton_logout_clicked();

    void on_pushButton_data_clicked();

    void changeColor();

private:
    Ui::DashboardGui *ui;
    vector<string> buttonList;
    vector<DynamicButton*> dynButtonList;
    int count = 1;
//    ContactsGui *contactsGui = new ContactsGui();
//    LogGui *logGui = new LogGui();
//    ResourcesGui *resourcesGui = new ResourcesGui();
    ContactsGui *contactsGui;
    LogGui *logGui;
    ResourcesGui *resourcesGui;
    int numContacts = 0;


};

#endif // DASHBOARDGUI_H
