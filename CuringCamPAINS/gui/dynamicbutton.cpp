#include "dynamicbutton.h"
int DynamicButton::buttonID = 0;
DynamicButton::DynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    resID = ++buttonID;// Increment of counter by one
}

DynamicButton::~DynamicButton()
{

}

/* Method to return the value of the button numbers
 * */
int DynamicButton::getID()
{
    return buttonID;
}
