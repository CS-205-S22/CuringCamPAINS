#include "csv.h"

Csv::Csv()
{

}
/**
 * @brief Csv::download
 * Download a table on a specified database to the desired output file
 * @param dbName: name of the database
 * @param table_name : name of the table
 * @param outFile: Address of the output file
 */
void Csv::download(string dbName, string table_name, string outFile){
    temp=new Database(dbName);
    temp->tableToCsv(table_name, outFile);
}

/**
 * @brief Csv::readFile
 * Read csv file and save the reading into a vector
 * @param fname: name of the file
 */
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

/**
 * @brief Csv::printFileReading
 * Print the file reading from the vector
 * @param fname: name of the file
 */
void Csv::printFileReading(string fname){
    readFile( fname);
    // print the array
    for(int i = 0; i < (int)content.size(); i++)
    {
        for(int j = 0; j < (int)content[i].size(); j++)
        {
            cout << content[i][j] << " ";
        }
        cout << "\n";
    }

}

/**
 * @brief Csv::writeFile
 * Write the designated file with the desired input
 * @param fileName: name of the file
 * @param input: the information entered
 */
void Csv::writeFile(string fileName,string input){
    std::ofstream myfile;
    myfile.open (fileName);
    myfile <<input;
    myfile.close();

}



