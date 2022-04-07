#include "custom.h"

Custom::Custom()
{

}

void Custom::levelUp()
{
    this->level++;
}

int Custom::getLevel() {
    return this->level;
}

void Custom::addBackground()
{
    //qt palette
}

void Custom::updateNotification()
{
    //clock notifc
}

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
