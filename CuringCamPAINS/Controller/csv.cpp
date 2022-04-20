#include "csv.h"

Csv::Csv()
{

}
void Csv::readFile(string fileName){
    vector<string> w; // vector container

    try{
        ifstream file( fileName); //read the file
        string line;
        srand((unsigned int)time(NULL)); //seed for the random

        while (getline(file, line)) {
            w.push_back(line);
        } // push the words on the container

    }

    catch(std::exception const& e){
        cout << "There was an error: " << e.what() << endl;
    }


}

