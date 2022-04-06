#include "userguide.h"

UserGuide::UserGuide()
{

}


void UserGuide::displayGuide() {
    fstream fh;
    fh.open("userguide.txt");
    if (fh.is_open()) {
        string line;
        while (getline(fh, line)) {
            cout << line << endl;
        }
        fh.close();
    }
}
