#include "csv.h"

Csv::Csv()
{

}
/**
 * @brief Csv::download
 * Download a table on a specified database to the desired output file
 * @param dbName: name of the database
 * @param table_name : name of the table
 * @param parameters[]: name of the table headers
* @param param_size: size of the parameters
 * @param outFile: Address of the output file
 */
void Csv::download(string dbName, string table_name, string *parameters, int param_size, string outFile){
    Database temp(dbName);
    temp.tableToCsv(table_name, outFile);
}
void Csv::readFile(string fname){
    content.empty();
    vector<string> row;
    string line, word;

    fstream file (fname, ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout<<"Could not open the file\n";
}


    void Csv::printFileReading(string fname){
    readFile( fname);
 // print the array
    for(int i=0;i<content.size();i++)
    {
        for(int j=0;j<content[i].size();j++)
        {
            cout<<content[i][j]<<" ";
        }
        cout<<"\n";
    }

    }




