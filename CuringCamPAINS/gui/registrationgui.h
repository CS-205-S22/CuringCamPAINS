/**
 * @file: registrationgui.h
 * ------------------
 * @brief Defines the GUI functionality of the registration page.
 *
 * @authors: Tafita Rakotozandry
 * @version: 05/02/22
 */

#ifndef REGISTRATIONGUI_H
#define REGISTRATIONGUI_H

#include <QDialog>
#include "../Controller/database.h"

namespace Ui {
class registrationGUI;
}

class registrationGUI : public QDialog
{
    Q_OBJECT

public:
    explicit registrationGUI(QWidget *parent = nullptr);
    ~registrationGUI();

private slots:
    /**
     * @brief on_buttonBox_accepted saves the new contact.
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_uploadPhoto_clicked opens a window to choose a file and uploads the photo.
     */
    void on_uploadPhoto_clicked();

private:
    Ui::registrationGUI *ui;
    Database *dbb;
};

#endif // REGISTRATIONGUI_H
