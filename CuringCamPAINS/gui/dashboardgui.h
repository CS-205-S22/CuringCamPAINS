/**
 * @file: dashboardgui.h
 * ------------------
 * @brief Defines the GUI functionality of the dashboard page.
 *
 * @authors: Max Turkot, Rory Schauder
 * @version: 05/02/22
 */

#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include <QVBoxLayout>
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
    void increaseNumContacts();
    ~DashboardGui();
    Contact* con;

private slots:
    /**
     * @brief openLogForm opens a log form when one of the log buttons is clicked.
     */
    void openLogForm();

    /**
     * @brief on_pushButton_dashboard_clicked opens the dashboard page.
     */
    void on_pushButton_dashboard_clicked();

    /**
     * @brief on_pushButton_contacts_clicked opens the contacts page.
     */
    void on_pushButton_contacts_clicked();

    /**
     * @brief on_pushButton_resources_clicked opens the resources page.
     */
    void on_pushButton_resources_clicked();

    /**
     * @brief on_pushButton_logout_clicked logs out of the system.
     */
    void on_pushButton_logout_clicked();

    /**
     * @brief changeColor slot changes color of the system.
     */
    void changeColor();

private:
    Ui::DashboardGui *ui;
    vector<string> buttonList;
    vector<DynamicButton*> dynButtonList;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    int count = 1;
    ContactsGui *contactsGui;
    LogGui *logGui;
    ResourcesGui *resourcesGui;
    int numContacts = 0;

    QVBoxLayout* layout;

};

#endif // DASHBOARDGUI_H
