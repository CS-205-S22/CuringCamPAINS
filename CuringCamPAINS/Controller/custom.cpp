#include "custom.h"

Custom::Custom()
{

}

/**
 * @brief Function increments the level of the user.
 */
void Custom::levelUp()
{
    this->level++;
}

/**
 * @brief Function simply returns the private level variable of the Custom class.
 * @return integer current level of the user
 */
int Custom::getLevel() {
    return this->level;
}

void Custom::addBackground()
{
    //going to wait to implement this code within the ui slot, this allows me to user QColorDialog getColor() and
    //set color. getColor() gives the user a color wheel to allow them to choose whatever they'd like
}

/**
 * @brief updateNotification outputs an encouraging message to the user on every Sunday or Monday. The function
 * begins by creating a string array of string messages. The function then uses the c++ time functionalities and
 * gets the index of the current day, where index 0 is Sunday and 6 is Saturday. The if statements checks for a 0
 * or 1, and calculates a random int to pick from the messages array, which is then output to the user.
 */
void Custom::updateNotification()
{
    int random;
    std::string messages[] = {"Keep up the great work! Look to level up and log 5 connections this week!",
                             "Start the week off strong and get connecting!",
                              "The campaign couldn't do it without you, keep going.",
                              "You crushed it last week, what will this week look like? You got it!",
                             "Call, Recruit, Log, Repeat. You are killing it!"};
    time_t rawtime;
    tm * timeinfo;
    time(&rawtime);
    timeinfo=localtime(&rawtime);
    int wday=timeinfo->tm_wday;
    //0 = sunday ... 6 = saturday
    if (wday == 0 || wday == 1) {
        random = rand() % 4 + 0; //ignore error because arc4random doesn't work on lab machine
        std::cout << messages[random] << std::endl;
    }
}

/**
 * @brief Function displays a User Guide to the user upon request. The function uses an fstream file handler which opens
 * the text file within the project file, which contains the proper guide for each large component. If the file
 * properly opens, the function outputs each line to the user. The file is closed at the end.
 */
void Custom::displayGuide() {
    std::fstream fh;
    fh.open("../../userGuide.txt");
    if (fh.is_open()) {
        std::string line;
        while (getline(fh, line)) {
            std::cout << line << std::endl;
        }
        fh.close();
    }
}
