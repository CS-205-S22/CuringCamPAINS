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

    vLayout = new QVBoxLayout();
    ui->scrollAreaWidgetContents_main->setLayout(vLayout);
    ui->scrollArea_main->setWidgetResizable(true);

    log = new LogForm("../../../../../database.sqlite");
    log->readFromDB();
    this->displayList();
}

AdminGui::~AdminGui()
{
    delete ui;
}

void AdminGui::displayList()
{
    QLabel *recName;
    QLabel *conName;
    QLabel *method;
    QLabel *logCnt;
    QHBoxLayout *hLayout;


    for (int i = 0; i < (int) log->logVector->size(); i++) {
        recName = new QLabel();
        conName = new QLabel();
        method   = new QLabel();
        logCnt  = new QLabel();
        hLayout  = new QHBoxLayout();

        recName->setText(QString::fromStdString(log->logVector->at(i)->at(1)));
        conName->setText(QString::fromStdString(log->logVector->at(i)->at(2)));
        method->setText(QString::fromStdString(log->logVector->at(i)->at(6)));
        logCnt->setText(QString::fromStdString(log->logVector->at(i)->at(5)));

        hLayout->addWidget(recName);
        hLayout->setAlignment(recName, Qt::AlignLeft);
        hLayout->addWidget(conName);
        hLayout->setAlignment(conName, Qt::AlignLeft);
        hLayout->addWidget(method);
        hLayout->setAlignment(method, Qt::AlignHCenter);
        hLayout->addWidget(logCnt);
        hLayout->setAlignment(logCnt, Qt::AlignCenter);

        vLayout->setAlignment(Qt::AlignTop);
        vLayout->addLayout(hLayout);
    }
}

void AdminGui::on_pushButton_logs_clicked()
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


void AdminGui::on_pushButton_contacts_clicked()
{
    Csv *c = new Csv();
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Download Data"), "/Desktop", tr("Data File (*.csv)"));
    string fname = fileName.toStdString();
    if(fname != ""){
        cerr << "CSV FILE NAME: " << fname << endl;

        if (fname.compare("") != 0) {
            c->download("../../../../../database.sqlite", "contact", fname);
            QMessageBox::warning(this,"Download", "The csv file is downloaded in main file");
        }
    }
}


void AdminGui::on_pushButton_logout_clicked()
{
    ui->pushButton_logout->setStyleSheet("QPushButton{ background-color: yellow }");
    LoginGUI *l = new LoginGUI();
    hide();
    l->show();
}

