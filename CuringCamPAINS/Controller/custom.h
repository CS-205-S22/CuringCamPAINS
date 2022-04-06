#ifndef CUSTOM_H
#define CUSTOM_H
#include <iostream>
#include <fstream>

class Custom
{
public:
    Custom();

    void levelUp();
    void addBackground();
    void updateNotification();
    void displayGuide();
    int getLevel();
private:
    int level = 1;
};

#endif // CUSTOM_H
