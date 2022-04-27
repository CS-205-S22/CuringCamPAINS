#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QPushButton>

class DynamicButton : public QPushButton
{
    Q_OBJECT
    public:
        explicit DynamicButton(QWidget *parent = 0);
    ~DynamicButton();
    static int ResID;   // A static variable counter buttons rooms
    int getID();        // Function to return a local number buttons


public slots:

private:
    int buttonID = 0;   // Local variable number of the button
};

#endif // DYNAMICBUTTON\_H
