#ifndef CSV_H
#define CSV_H
#include "database.h"

string fileName;
string locationToBeSaved;
string data;


class Csv
{
public:
    Csv();
    void download();
    void writeFile();
};

#endif // CSV_H
