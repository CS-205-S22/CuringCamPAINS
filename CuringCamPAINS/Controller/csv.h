#ifndef CSV_H
#define CSV_H
#include "database.h"
#include <sstream>

class Csv
{
public:
    Csv();
    /**
     * @brief Csv::download
     * Download a table on a specified database to the desired output file
     * @param dbName: name of the database
     * @param table_name : name of the table
     * @param outFile: Address of the output file
     */
    void download(string dbName,string table_name,string outFile);

    /**
     * @brief Csv::writeFile
     * Write the designated file with the desired input
     * @param fileName: name of the file
     * @param input: the information entered
     */
    void writeFile(string fileName,string input);

    /**
     * @brief Csv::readFile
     * Read csv file and save the reading into a vector
     * @param fname: name of the file
     */
    void readFile(string fileName);
    /**
     * @brief Csv::printFileReading
     * Print the file reading from the vector
     * @param fname: name of the file
     */
    void printFileReading(string fileName);
    vector<vector<string>> content;

private:
    string fileName;
    string locationToBeSaved;
    string data;
    Database *temp;

};

#endif // CSV_H
