#ifndef CSV_H
#define CSV_H
#include "database.h"




class Csv
{
public:
    Csv();
    void download();
    void writeFile();
private:
    string fileName;
    string locationToBeSaved;
    string data;
};

#endif // CSV_H
