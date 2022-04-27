#include "dynamicbutton.h"

DynamicButton::DynamicButton(QWidget *parent) :
    QPushButton(parent)
{
    ResID++;            // Increment of counter by one
    buttonID = ResID;   /* Assigning a button number which will be further work with buttons
                         * */

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

/* Initialize static class variable.
 * Static class variable must be initialized without fail
 * */
int DynamicButton::ResID = 0;
