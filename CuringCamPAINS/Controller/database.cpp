#include "database.h"
#include <cstdlib>



Database::Database() {
    std::cerr << "Name must be provided to Database Class "
              << "during creation.\n";
    exit(-1);
}

Database::Database(std::string name) {
    if (!QSqlDatabase::drivers().contains("QSQLITE")){
        std::cerr << "Unable to load database this demo needs the SQLITE driver" <<std::endl;
        exit(-1);
    }

    db_name     = name;
    db_location = ".";

    open_db();
}


Database::Database(const char* name) {
    //std::cerr << "constructing object 2\n";

    db_name     = name;
    db_location = ".";

    open_db();
}

Database::Database(const char* location, const char* name) {
    //std::cerr << "constructing object 3\n";

    db_name     = name;
    db_location = location;

    open_db();
}


Database::Database(std::string location, std::string name) {
    //std::cerr << "constructing object 4\n";

    db_name     = name;
    db_location = location;

    open_db();
}


Database::~Database() {

    //std::cerr << "closing object\n";

    curr_db->close();
    curr_db = NULL;
}


/** Method that will open the provided database.
 */
int Database::open_db() {

    int retCode = 0;

    std::string full_name =db_location + "/" + db_name;

    // open the database --------------------

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(full_name));
    //    db.setDatabaseName(":memory:"); use to create temporary in-memory db

    if(!db.open()){
        std::cerr << "Database does not open -- "
                  << db.lastError().text().toStdString()
                  << std::endl;

        std::cerr << "  File -- " << full_name << std::endl;
        exit(0);
    }else{
        std::cerr << "Opened database successfully\n";
    }
    return retCode;
}


void Database::print(std::ostream &sout) {

    sout << "DB Name : " << db_name     << std::endl;
    sout << "DB Loc  : " << db_location << std::endl;

    sout << "Status  : "
         << ( db_open() ? "open" : "closed" )
         << std::endl;
}

void Database::runQuery(QString str){
    QSqlQuery qry;
    if(!qry.exec(str)){
        qDebug()<<"error running query";
    }
}

void Database::write(string table_name,string parameters[],int param_size,string values[] ){

    QSqlQuery query;
    string temp; // temporary variable
    string temp2;// temporary variable
    temp=parameters[0]; //first parameters value
    temp2=":"+parameters[0]; //first parameter value in form of ":parameter"

    //concatenate the parameters to get the form param1,param2,param3
    for (int i = 1; i < param_size; i++) {

        temp+=","+parameters[i];
        temp2+=",:"+parameters[i];
    }
    //write the query in form of
    //INSERT INTO table_name (param1,param2,param3)"+" VALUES "+" (val1,val2,val3)"
    string com="INSERT INTO "+ table_name +"("+temp+")"+" VALUES "+" ("+temp2 +")";
    std::cout<<com<<endl;

     query.prepare(QString::fromStdString(com));
     //use bindValue
     //query.bindValue(:param1,val1);
     for (int i = 0; i < param_size; i++){
        string rec=":"+parameters[i];
    query.bindValue(QString::fromStdString(rec),QString::fromStdString(values[i]));
    }
    query.exec(); //execute the command
}
