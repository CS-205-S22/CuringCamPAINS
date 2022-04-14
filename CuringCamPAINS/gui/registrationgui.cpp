#include "registrationgui.h"
#include "ui_registrationgui.h"

registrationGUI::registrationGUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationGUI)
{
    ui->setupUi(this);
}

registrationGUI::~registrationGUI()
{
    delete ui;
}
