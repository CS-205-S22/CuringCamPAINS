#include "admingui.h"
#include "ui_admingui.h"

AdminGui::AdminGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminGui)
{
    ui->setupUi(this);

    QPixmap pix1(QString::fromStdString("../../../../../letter_logo.png"));
    int w1=ui->label_title->width();
    int h1=ui->label_title->height();
    ui->label_title->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));

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
    QHBoxLayout *hLayout;


//    for (int i = 0; i < (int) contacts->size(); i++) {
        recName = new QLabel();
        conName = new QLabel();
        group   = new QLabel();
        logCnt  = new QLabel();
        hLayout  = new QHBoxLayout();

//        recName->setText(contacts->at(i)->getRectuiterName);
        recName->setText("test");
//        conName->setText(QString::fromStdString(contacts->at(i)->firstName + " " + contacts->at(i)->firstName));
//        group->setText(QString::fromStdString(to_string(contacts->at(i)->contactListId)));
        conName->setText("name");
        group->setText("111");
        logCnt->setText("000");

        hLayout->addWidget(recName);
        hLayout->setAlignment(recName, Qt::AlignLeft);
        hLayout->addWidget(conName);
        hLayout->setAlignment(conName, Qt::AlignLeft);
        hLayout->addWidget(group);
        hLayout->setAlignment(group, Qt::AlignHCenter);
        hLayout->addWidget(logCnt);
        hLayout->setAlignment(logCnt, Qt::AlignCenter);

        vLayout->setAlignment(Qt::AlignTop);
        vLayout->addLayout(hLayout);
//    }
}

void AdminGui::on_pushButton_test_clicked()
{
    this->displayList();
}


void AdminGui::on_pushButton_data_clicked()
{
    Csv *c=new Csv();
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Download Data"), "/Desktop", tr("Data File (*.csv)"));
    string fname = fileName.toStdString();
    if(fname != ""){
        cerr << "CSV FILE NAME: " << fname << endl;

        if (fname.compare("") != 0) {
            c->download("../../../../../database.sqlite", "logForm", fname);
            QMessageBox::warning(this,"Download", "The csv file is downloaded in main file");
        }
    }
}

