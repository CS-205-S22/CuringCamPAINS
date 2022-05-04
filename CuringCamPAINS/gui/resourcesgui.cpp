/**
 * @file: resourcesgui.cpp
 * ------------------
 * @brief Implements the GUI functionality of the resources page.
 *
 * @authors: Rory Schauder, Max Turkot
 * @version: 05/02/22
 */

#include "resourcesgui.h"
#include "ui_resourcesgui.h"
#include "QFileDialog"

ResourcesGui::ResourcesGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourcesGui)
{
    ui->setupUi(this);
    ui->stackedWidget_resources->setCurrentIndex(0);
    sm = new SavedMessages("../../../../../database.sqlite");

}

ResourcesGui::ResourcesGui(int usr,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourcesGui)
{
    cur_usr=usr;
    ui->setupUi(this);
    ui->stackedWidget_resources->setCurrentIndex(0);
    sm = new SavedMessages(usr,"../../../../../database.sqlite");
}

ResourcesGui::~ResourcesGui()
{
    delete ui;
}

/**
 * @brief ResourcesGui::getSyle gets the style of the system.
 * @return style of the sistem.
 */
QString ResourcesGui::getSyle() {
    return this->style;
}

/**
 * @brief ResourcesGui::on_pushButton_changeColor_clicked opens a color picker that is used to change the color of the system.
 */
void ResourcesGui::on_pushButton_changeColor_clicked()
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    QString colName = color.name();

    int r, g, b;
    char const *hexColor = colName.toUtf8().data();
    std::sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);
    string feed = "QStackedWidget { background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ") }\n";
    feed += "QGroupBox { background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ") }\n";
    feed += "QScrollArea { background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ") }\n";
    feed += "QWidget#scrollAreaWidgetContents_dashboard { background-color:rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ") }\n";
    QString style = QString::fromUtf8(feed.c_str());
    this->style = style;
    emit changeColorSignal();
}

/**
 * @brief ResourcesGui::on_pushButton_createMessage_clicked opens the window to save a message.
 */
void ResourcesGui::on_pushButton_createMessage_clicked()
{
    //will now prompt user to enter title and text of desired message
    ui->stackedWidget_resources->setCurrentIndex(1);
}

/**
 * @brief One viewMessage button on the resources page, the user is brought to the view message page which asks for an input title.
 */
void ResourcesGui::on_pushButton_viewMessage_clicked()
{
    ui->stackedWidget_resources->setCurrentIndex(2);
    vector<string> titles = sm->viewTitles();
    if (titles.empty()) {
        return;
    } else {
        for (int i = 0; i < (int)titles.size(); i++) {
            ui->comboBox_choices->addItem(QString::fromUtf8(titles.at(i).c_str()));
        }
    }
}

/**
 * @brief The viewButton is on the view message page. Once the view button is pressed, the title is updated to be the input string
 * on the label. If the user inputs multiple titles, then the multipleTitles function is called. The function creates a vector
 * that is set equal to the SavedMessages viewMessage function that takes the updated title. If the vector is empty,
 * the function outputs an error message informing the user of the mistake. Otherwise, the function creates a QString and
 * loops through the vector. At each iteration, the QString gets the index messsage appended to the string. After the loop breaks,
 * the QString is displayed on a label on the page. Lastly, the input is cleared.
 */
void ResourcesGui::on_pushButton_view_clicked()
{
    ui->textEdit_textOutput->clear();
    vector<string> text;
    text = sm->viewMessage(ui->comboBox_choices->currentText().toStdString());
    for (int i = 0; i < (int)text.size(); i++) {
        ui->textEdit_textOutput->append(QString::fromUtf8(text.at(i).c_str()));
    }
}

/**
 * @brief On pressing the back button on page 3, the view message page, the program clears the label and resets the view to the
 * resources page.
 */
void ResourcesGui::on_pushButton_back_clicked()
{
    ui->textEdit_textOutput->clear();
    ui->comboBox_choices->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief Upon pressing the delete message button on the resources page, the page will be set to the fourth page which is where
 * the user inputs the title of the message wanting to be deleted.
 */
void ResourcesGui::on_pushButton_deleteMessage_clicked()
{
    ui->stackedWidget_resources->setCurrentIndex(3);
    vector<string> titles = sm->viewTitles();
    if (titles.empty()) {
        return;
    } else {
        for (int i = 0; i < (int)titles.size(); i++) {
            ui->comboBox_choicesDelete->addItem(QString::fromUtf8(titles.at(i).c_str()));
        }
    }

}

/**
 * @brief The deleteButton is on the delete message page. Once the title is inserted by the user, the title variable is updated
 * to be the input string on the label. If the user inputs multiple titles, the function will seperate the substrings and delete
 * each of the input titles. The SavedMessages deleteMessage function is called on the new title(s). The function then
 * clears the label and returns the user back to the resources page.
 */
void ResourcesGui::on_pushButton_delete_clicked()
{
    this->title = ui->comboBox_choicesDelete->currentText().toStdString();
    sm->deleteMessage(this->title);
    ui->comboBox_choicesDelete->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief The saveMessage button is on the create message page. After clicking save message, the input title and text is saved to the
 * global strings.
 */
void ResourcesGui::on_pushButton_saveMessage_clicked()
{
    this->title = ui->lineEdit_title->text().toStdString();
    this->text = ui->lineEdit_text->toPlainText().toStdString();
    //call saved messages create message
    sm->createMessage(this->title, this->text);
    ui->lineEdit_title->clear();
    ui->lineEdit_text->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief ResourcesGui::on_pushButton_back2_clicked returns to the main resources page.
 */
void ResourcesGui::on_pushButton_back2_clicked()
{
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief ResourcesGui::on_pushButton_back3_clicked returns to the main resources page.
 */
void ResourcesGui::on_pushButton_back3_clicked()
{
    ui->comboBox_choicesDelete->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief ResourcesGui::on_pushButton_profileUpdate_clicked updates the profile information.
 */
void ResourcesGui::on_pushButton_profileUpdate_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Upload Picture"), "/Desktop", tr("Upload Profile Picture (*.jpeg *.png)"));
    string outputName=sm->getter("user","name", "userId",std::to_string(cur_usr));
    string fname = fileName.toStdString();
    string outputAddress="../../../../../"+outputName+".jpeg";
    if (QFile::exists(QString::fromStdString(outputAddress)))
    {
        QFile::remove(QString::fromStdString(outputAddress));
    }
        QFile::copy(QString::fromStdString(fname), QString::fromStdString(outputAddress));
}

