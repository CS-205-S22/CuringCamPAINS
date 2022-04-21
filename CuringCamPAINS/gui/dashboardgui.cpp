#include "dashboardgui.h"
#include "ui_dashboardgui.h"

DashboardGui::DashboardGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGui)
{
    ui->setupUi(this);

    ui->stackedWidget_main->addWidget(contactsGui);
    ui->stackedWidget_main->addWidget(resourcesGui);
    ui->stackedWidget_main->addWidget(logGui);
}

DashboardGui::~DashboardGui()
{
    delete ui;
}

void DashboardGui::on_pushButton_dashboard_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(0);
}

void DashboardGui::on_pushButton_contacts_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(1);
}

void DashboardGui::on_pushButton_resources_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(2);
}

void DashboardGui::on_pushButton_data_clicked()
{

}

void DashboardGui::on_pushButton_logout_clicked()
{
    this->close();
}

void DashboardGui::on_pushButton_log_clicked()
{
    ui->stackedWidget_main->setCurrentIndex(3);
    logGui->autofill();
}

