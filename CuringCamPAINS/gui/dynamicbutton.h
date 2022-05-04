/**
 * @file: dynamicbutton.h
 * ------------------
 * @brief Defines the GUI functionality of the dynamic buttons.
 *
 * @authors: Rory Schauder
 * @version: 05/02/22
 */

#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QPushButton>

class DynamicButton : public QPushButton
{
    Q_OBJECT
    public:
        explicit DynamicButton(QWidget *parent = 0);
    ~DynamicButton();
    int resID;   // A variable counter buttons rooms
    int getID();        // Function to return a local number buttons

    std::string name;

    //static function to set button IDs back to 0
    static void setID()
    {
        buttonID = 0;
    }



public slots:

private:
    static int buttonID;   // Local variable number of the button
};

#endif // DYNAMICBUTTON\_H
