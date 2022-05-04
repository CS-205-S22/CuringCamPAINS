/**
 * @file: admingui.cpp
 * ------------------
 * @brief Implements the GUI functionality of the admin page.
 *
 * @authors: Max Turkot, Tafita Rakotkzandry
 * @version: 05/02/22
 */

#include "admingui.h"
#include "ui_admingui.h"

/**
 * @brief AdminGui::AdminGui sets up the gui, including images and scroll area.
 * @param usr_id
 * @param parent
 */
AdminGui::AdminGui(int usr_id,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminGui)
{
    ui->setupUi(this);
    cur_usrId=usr_id;
    QPixmap pix1(QString::fromStdString("../../../../../letter_logo.png"));
    int w1=ui->label_title->width();
    int h1=ui->label_title->height();
    ui->label_title->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));

    vLayout = new QVBoxLayout();
    ui->scrollAreaWidgetContents_main->setLayout(vLayout);
    ui->scrollArea_main->setWidgetResizable(true);

    Database *dbb = new Database("../../../../../database.sqlite");
    string name = dbb->getter("user", "name", "userId", std::to_string(cur_usrId));
    ui->label_name->setText(QString::fromStdString(name));
    string outFile="../../../../../"+name+".jpeg";
    QPixmap pix(QString::fromStdString(outFile));
    int w=ui->label_image->width();
    int h=ui->label_image->height();
    ui->label_image->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    log = new LogForm("../../../../../database.sqlite");
    log->readFromDB();
    this->displayList();
}

/**
 * @brief AdminGui::~AdminGui destructor.
 */
AdminGui::~AdminGui()
{
    delete ui;
}

/**
 * @brief AdminGui::displayList displays the list of logs for the admin to view. Creates a layout, sublayout, inserts labels
 * with text loaded from the database into each sublayout.
 */
void AdminGui::displayList()
{
    QLabel *recName;
    QLabel *conName;
    QLabel *method;
    QLabel *logCnt;
    QHBoxLayout *hLayout;

    // For each log in the databse.
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

/**
 * @brief AdminGui::on_pushButton_logs_clicked downloads the log data to a specified file.
 */
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

/**
 * @brief AdminGui::on_pushButton_contacts_clicked downloads the contacts data to a specified file.
 */
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

/**
 * @brief AdminGui::on_pushButton_logout_clicked logs out from the admin account.
 */
void AdminGui::on_pushButton_logout_clicked()
{
    ui->pushButton_logout->setStyleSheet("QPushButton{ background-color: yellow }");
    LoginGUI *l = new LoginGUI();
    hide();
    l->show();
}

