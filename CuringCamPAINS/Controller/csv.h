#ifndef CSV_H
#define CSV_H
#include "database.h"
#include <sstream>

class Csv
{
public:
    Csv();
    void download(string dbName,string table_name,string parameters[],int  param_size,string outFile);
    void writeFile(string fileName);
    void readFile(string fileName);
    void printFileReading(string fileName);

private:
    string fileName;
    string locationToBeSaved;
    string data;
    vector<vector<string>> content;
};

#endif // CSV_H
