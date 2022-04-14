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

/**
 * @brief Database:write
 * Method to write file in the database
 * @param table_name : name of the table in the database
 * @param parameters: string array about the column names in the table
 * @param param_size number of elements in the column
 * @param values: string array about the values for each column
 */
void Database::write(string table_name, string parameters[], int param_size, string values[] ){
try{
    QSqlQuery query;
    string temp; // temporary variable
    string temp2;// temporary variable
    temp = parameters[0]; //first parameters value
    temp2 = ":" + parameters[0]; //first parameter value in form of ":parameter"

    //concatenate the parameters to get the form param1,param2,param3
    for (int i = 1; i < param_size; i++) {

        temp += "," + parameters[i];
        temp2 += ",:" + parameters[i];
    }
    //write the query in form of
    //INSERT INTO table_name (param1,param2,param3)"+" VALUES "+" (val1,val2,val3)"
    string com = "INSERT INTO " + table_name + "(" + temp + ")" + " VALUES " + " (" + temp2 + ")";
//    std::cout << com << endl;

    query.prepare(QString::fromStdString(com));

    //use bindValue
    //query.bindValue(:param1,val1);
    for (int i = 0; i < param_size; i++){
        string rec = ":" + parameters[i];
        query.bindValue(QString::fromStdString(rec), QString::fromStdString(values[i]));
    }
//    cout << "Here" << endl;
    query.exec(); //execute the command
//    cout << QDir::currentPath().toStdString() << endl;
    cout << "Succesful writing" << endl;
    }
    catch (const std::bad_alloc&) {
        cout << "error" << endl;
    }
}


/**
 * @brief Database:remove
 * Method to remove a row in the database based on a given condition
 * @param table_name : name of the table in the database
 * @param parameters: column names in the table
 * @param condition: values of the condition
 * Example: DELETE * FROM user where name="Tafita"
 * In this specific example table_name="user" , parameters=name , condition = "Tafita"
 */
void Database::remove(string table_name,string parameter,string conditions){
    QSqlQuery query;
    std::string com = "DELETE FROM "+ table_name+ " WHERE "+parameter+"=:"+parameter;
   cout<<com<<endl;
    query.prepare(QString::fromStdString(com));
    string temp =":"+parameter;
    query.bindValue(QString::fromStdString(temp),QString::fromStdString(conditions));
    query.exec(); //execute the command
//    cout<<"Succesful delete"<<endl;
}

vector<string> Database::read(string table_name,string parameter,string conditions) {
    QSqlQuery query;
    std::string com = "SELECT* FROM "+ table_name + " WHERE "+parameter+"=:"+parameter;
    cout<<com<<endl;
    query.prepare(QString::fromStdString(com));
    string temp =":"+parameter;
    query.bindValue(QString::fromStdString(temp),QString::fromStdString(conditions));
    query.exec(); //execute the command
    vector<string> messages;
    while(query.next()) {
        QString text = query.value(2).toString();
        messages.push_back(text.toStdString());
    }
    return messages;
}

/**
 * @brief Database:authenticate
 * Method to verify if a user with a certain username and passwrd is in the database
 * @param usr : the username
 * @param pwd : password
 */
bool Database::authenticate(QString usr, QString pwd){

    try{
    QSqlQuery query;
    QString query_str_id = "SELECT password FROM user WHERE userName='"+usr+"' ;"; //get password
    query.exec(query_str_id);
    query.next();
//    cout<<"Here"<<endl;
    std::string result=query.value(0).toString().toStdString();
    std::string temp=pwd.toStdString();

    if(temp==result){
        return true;
    }
    else{
        return false;
    }
    }

    catch(...){
        cout<<"error occured"<<endl;
        return false;
    }
}



/**
 * @brief DBTool::getMaxId
 * get the max id on the user row
 */
int Database::getMaxId(string table_name,string id_name){
    try{
    QSqlQuery query;
    QString id= QString::fromStdString(id_name);
    QString table=QString::fromStdString(table_name);
    QString query_str_id = "select MAX("+id+") from "+table;
    query.exec(query_str_id);
    query.next();
    std::string result=query.value(0).toString().toStdString();
    return stoi(result);

}
    catch(...){
        cout<<"Error occured"<<endl;
        return 1;
    }
}


void Database::closeDB() {

    //std::cerr << "closing object\n";

    curr_db->close();
    curr_db = NULL;
}
