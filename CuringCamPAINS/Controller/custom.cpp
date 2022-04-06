#include "custom.h"

Custom::Custom()
{

}

void Custom::levelUp()
{
    this->level++;
}

void Custom::addBackground()
{

}

void Custom::updateNotification() {

}

void Custom::displayGuide() {
    std::fstream fh;
    fh.open("userguide.txt");
    if (fh.is_open()) {
        std::string line;
        while (getline(fh, line)) {
            std::cout << line << std::endl;
        }
        fh.close();
    }
}
