#ifndef DYNAMICBUTTON_H
#define DYNAMICBUTTON_H

#include <QPushButton>

class DynamicButton : public QPushButton
{
    Q_OBJECT
    public:
        explicit DynamicButton(QWidget *parent = 0);
    ~DynamicButton();
    int ResID;   // A static variable counter buttons rooms
    int getID();        // Function to return a local number buttons
    std::string name;

public slots:

private:
    static int buttonID;   // Local variable number of the button
};

#endif // DYNAMICBUTTON\_H
