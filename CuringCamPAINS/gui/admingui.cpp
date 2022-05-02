#include "admingui.h"
#include "ui_admingui.h"

AdminGui::AdminGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminGui)
{
    ui->setupUi(this);

    this->contactList = new ContactList("../../../../../database.sqlite");

    for (int i = 0; i < (int) contactList->masterList->size(); i++) {
        contacts->push_back(contactList->masterList->at(i));
    }

    vLayout = new QVBoxLayout();
    ui->scrollAreaWidgetContents_main->setLayout(vLayout);
    ui->scrollArea_main->setWidgetResizable(true);
}

AdminGui::~AdminGui()
{
    delete ui;
}

void AdminGui::displayList()
{
    QLabel *recName;
    QLabel *conName;
    QLabel *group;
    QLabel *logCnt;
    QHBoxLayout *layout;


//    for (int i = 0; i < (int) contacts->size(); i++) {
        recName = new QLabel();
        conName = new QLabel();
        group   = new QLabel();
        logCnt  = new QLabel();
        layout  = new QHBoxLayout();

//        recName->setText(contacts->at(i)->getRectuiterName);
        recName->setText("test");
//        conName->setText(QString::fromStdString(contacts->at(i)->firstName + " " + contacts->at(i)->firstName));
//        group->setText(QString::fromStdString(to_string(contacts->at(i)->contactListId)));
        conName->setText("name");
        group->setText("111");
        logCnt->setText("000");

        layout->addWidget(recName);
        layout->setAlignment(recName, Qt::AlignLeft);
        layout->addWidget(conName);
        layout->setAlignment(conName, Qt::AlignLeft);
        layout->addWidget(group);
        layout->setAlignment(group, Qt::AlignHCenter);
        layout->addWidget(logCnt);
        layout->setAlignment(logCnt, Qt::AlignCenter);

        vLayout->setAlignment(Qt::AlignTop);
        vLayout->addLayout(layout);
//    }
}

void AdminGui::on_pushButton_test_clicked()
{
    this->displayList();
}

