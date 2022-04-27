#include "resourcesgui.h"
#include "ui_resourcesgui.h"

SavedMessages sm("../../../../../database.sqlite");

ResourcesGui::ResourcesGui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourcesGui)
{
    ui->setupUi(this);
    ui->stackedWidget_resources->setCurrentIndex(0);
}

ResourcesGui::~ResourcesGui()
{
    delete ui;
}

void ResourcesGui::on_pushButton_changeColor_clicked()
{
    QColorDialog dialog;
    QColor color = dialog.getColor();
    QString colName = color.name();

    int r, g, b;
    char const *hexColor = colName.toUtf8().data();
    std::sscanf(hexColor, "#%02x%02x%02x", &r, &g, &b);
    string feed = "background-color: rgb(";
    feed += to_string(r) += ", ";
    feed += to_string(g) += ", ";
    feed += to_string(b) += ", ";
    feed += to_string(25) += ")";
    QString style = QString::fromUtf8(feed.c_str());
    setStyleSheet(style);
}

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
    vector<string> titles = sm.viewTitles();
    if (titles.empty()) {
        ui->label_titlesOutput->setText("No saved messages.");
    } else {
        QString display = "Saved Titles: ";
        for (int i = 0; i < (int)titles.size() - 1; i++) {
            display += QString::fromUtf8(titles.at(i).c_str()) += ",  ";
        }
        display += QString::fromUtf8(titles.at(titles.size() -1).c_str());
        ui->label_titlesOutput->setText(display);
    }
}

/**
 * @brief Upon pressing the delete message button on the resources page, the page will be set to the fourth page which is where
 * the user inputs the title of the message wanting to be deleted.
 */
void ResourcesGui::on_pushButton_deleteMessage_clicked()
{
    ui->stackedWidget_resources->setCurrentIndex(3);
    vector<string> titles = sm.viewTitles();
    if (titles.empty()) {
        ui->label_titleDeleteMessage->setText("No saved messages.");
    } else {
        QString display = "Saved Titles: ";
        for (int i = 0; i < (int)titles.size() - 1; i++) {
            display += QString::fromUtf8(titles.at(i).c_str()) += ",  ";
        }
        display += QString::fromUtf8(titles.at(titles.size() -1).c_str());
        ui->label_allTitles->setText(display);
    }
}

/**
 * @brief The saveMessage button is on the create message page. After clicking save message, the input title and text is saved to the
 * global strings.
 */
void ResourcesGui::on_pushButton_saveMessage_clicked()
{
    this->title = ui->lineEdit_title->text().toStdString();
    this->text = ui->lineEdit_text->text().toStdString();
    //call saved messages create message
    sm.createMessage(this->title, this->text);
    ui->lineEdit_title->clear();
    ui->lineEdit_text->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief The viewButton is on the view message page. Once the view button is pressed, the title is updated to be the input string
 * on the label. The function creates a vector that is set equal to the SavedMessages viewMessage function that takes the
 * updated title. If the vector is empty, the function outputs an error message informing the user of the mistake. Otherwise,
 * the function creates a QString and loops through the vector. At each iteration, the QString gets the index messsage appended
 * to the string. After the loop breaks, the QString is displayed on a label on the page. Lastly, the input is cleared.
 */
void ResourcesGui::on_pushButton_view_clicked()
{
    this->title = ui->lineEdit_titleView->text().toStdString();
    vector<string> toView = sm.viewMessage(this->title);
    if (toView.empty()) {
        ui->label_displayText->setText("No messages with input title.");
    } else {
        QString insert;
        for (int i = 0; i < (int)toView.size(); i++) {
            insert += QString::fromUtf8(toView.at(i).c_str()) + " ";
        }
        ui->label_displayText->setText(insert);
    }
    ui->lineEdit_titleView->clear();
}

/**
 * @brief On pressing the back button on page 3, the view message page, the program clears the label and resets the view to the
 * resources page.
 */
void ResourcesGui::on_pushButton_back_clicked()
{
    ui->label_displayText->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

/**
 * @brief The deleteButton is on the delete message page. Once the title is inserted by the user, the title variable is updated
 * to be the input string on the label. The SavedMessages deleteMessage function is called on the new title. The function then
 * clears the label and returns the user back to the resources page.
 */
void ResourcesGui::on_pushButton_delete_clicked()
{
    this->title = ui->inputTitle_3->text().toStdString();
    sm.deleteMessage(this->title);
    ui->inputTitle_3->clear();
    ui->stackedWidget_resources->setCurrentIndex(0);
}

