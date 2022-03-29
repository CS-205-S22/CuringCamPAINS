#include <iostream>
#include <QCoreApplication>
#include "dbtool.h"
using namespace std;

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv); //Need to initialize
    DBTool db("../../database.sqlite");

    cout<<db.authenticate("rakotozt","blabl")<<endl;
      cout<<db.authenticate("hounasm","look")<<endl;

    return 0;
}
