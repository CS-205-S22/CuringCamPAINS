/**
 * @file: resourcesgui.h
 * ------------------
 * @brief Defines the GUI functionality of the resources page.
 *
 * @authors: Rory Schauder, Max Turkot
 * @version: 05/02/22
 */

#ifndef RESOURCESGUI_H
#define RESOURCESGUI_H

#include <QWidget>
#include <QColorDialog>
#include <sstream>
#include "../Controller/savedmessages.h"

using namespace std;

namespace Ui {
class ResourcesGui;
}

class ResourcesGui : public QWidget
{
    Q_OBJECT

public:
    explicit ResourcesGui(QWidget *parent = nullptr);
    explicit ResourcesGui(int usr,QWidget *parent = nullptr);
    ~ResourcesGui();

    /**
     * @brief ResourcesGui::getSyle gets the style of the system.
     * @return style of the sistem.
     */
    QString getSyle();

    int cur_usr;
private slots:
    /**
     * @brief ResourcesGui::on_pushButton_changeColor_clicked opens a color picker that is used to change the color of the system.
     */
    void on_pushButton_changeColor_clicked();

    /**
     * @brief ResourcesGui::on_pushButton_createMessage_clicked opens the window to save a message.
     */
    void on_pushButton_createMessage_clicked();

    /**
     * @brief One viewMessage button on the resources page, the user is brought to the view message page which asks for an input title.
     */
    void on_pushButton_viewMessage_clicked();

    /**
     * @brief Upon pressing the delete message button on the resources page, the page will be set to the fourth page which is where
     * the user inputs the title of the message wanting to be deleted.
     */
    void on_pushButton_deleteMessage_clicked();

    /**
     * @brief The saveMessage button is on the create message page. After clicking save message, the input title and text is saved to the
     * global strings.
     */
    void on_pushButton_saveMessage_clicked();

    /**
     * @brief The viewButton is on the view message page. Once the view button is pressed, the title is updated to be the input string
     * on the label. If the user inputs multiple titles, then the multipleTitles function is called. The function creates a vector
     * that is set equal to the SavedMessages viewMessage function that takes the updated title. If the vector is empty,
     * the function outputs an error message informing the user of the mistake. Otherwise, the function creates a QString and
     * loops through the vector. At each iteration, the QString gets the index messsage appended to the string. After the loop breaks,
     * the QString is displayed on a label on the page. Lastly, the input is cleared.
     */
    void on_pushButton_view_clicked();

    /**
     * @brief On pressing the back button on page 3, the view message page, the program clears the label and resets the view to the
     * resources page.
     */
    void on_pushButton_back_clicked();

    /**
     * @brief The deleteButton is on the delete message page. Once the title is inserted by the user, the title variable is updated
     * to be the input string on the label. If the user inputs multiple titles, the function will seperate the substrings and delete
     * each of the input titles. The SavedMessages deleteMessage function is called on the new title(s). The function then
     * clears the label and returns the user back to the resources page.
     */
    void on_pushButton_delete_clicked();

    /**
     * @brief ResourcesGui::on_pushButton_back2_clicked returns to the main resources page.
     */
    void on_pushButton_back2_clicked();

    /**
     * @brief ResourcesGui::on_pushButton_back3_clicked returns to the main resources page.
     */
    void on_pushButton_back3_clicked();

    /**
     * @brief ResourcesGui::on_pushButton_profileUpdate_clicked updates the profile information.
     */
    void on_pushButton_profileUpdate_clicked();

private:
    Ui::ResourcesGui *ui;
    string title, text;
    SavedMessages *sm;
    QString style;

signals:
    void changeColorSignal();
};

#endif // RESOURCESGUI_H
