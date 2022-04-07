#ifndef CUSTOM_H
#define CUSTOM_H
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

class Custom
{
public:
    Custom();

    /**
     * @brief Function increments the level of the user.
     */
    void levelUp();
    /**
     * @brief Function simply returns the private level variable of the Custom class.
     * @return integer current level of the user
     */
    int getLevel();

    void addBackground();
    /**
     * @brief updateNotification outputs an encouraging message to the user on every Sunday or Monday.
     */
    void updateNotification();
    /**
     * @brief Function displays a User Guide to the user upon request.
     */
    void displayGuide();

private:
    int level = 1;
};

#endif // CUSTOM_H
