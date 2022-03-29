#include "dbtool.h"

DBTool::DBTool() {
    std::cerr << "Name must be provided to DBTool Class "
              << "during creation.\n";
    exit(-1);
}

DBTool::DBTool(std::string name) {
    if (!QSqlDatabase::drivers().contains("QSQLITE")){
        std::cerr << "Unable to load database this demo needs the SQLITE driver" <<std::endl;
        exit(-1);
    }

    db_name     = name;
    db_location = ".";

    open_db();
}


DBTool::DBTool(const char* name) {
    //std::cerr << "constructing object 2\n";

    db_name     = name;
    db_location = ".";

    open_db();
}

DBTool::DBTool(const char* location, const char* name) {
    //std::cerr << "constructing object 3\n";

    db_name     = name;
    db_location = location;

    open_db();
}


DBTool::DBTool(std::string location, std::string name) {
    //std::cerr << "constructing object 4\n";

    db_name     = name;
    db_location = location;

    open_db();
}


DBTool::~DBTool() {

    //std::cerr << "closing object\n";

    curr_db->close();
    curr_db = NULL;
}


/** Method that will open the provided database.
 */
int DBTool::open_db() {

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
    cur_id=getMaxId();
    return retCode;
}


void DBTool::print(std::ostream &sout) {

    sout << "DB Name : " << db_name     << std::endl;
    sout << "DB Loc  : " << db_location << std::endl;

    sout << "Status  : "
         << ( db_open() ? "open" : "closed" )
         << std::endl;
}

void DBTool::runQuery(QString str){
    QSqlQuery qry;
    if(!qry.exec(str)){
        qDebug()<<"error running query";
    }
}

bool DBTool::authenticate(QString usr, QString pwd){

    try{
    QSqlQuery query;
    QString query_str_id = "SELECT password FROM user WHERE userName='"+usr+"' ;"; //get password
    query.exec(query_str_id);
    query.next();
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

int DBTool::getMaxId(){
    try{
    QSqlQuery query;
    QString query_str_id = "select MAX(userId) from user";
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
void DBTool::addContact(std::string name,std::string password,std::string userName,std::string isResearcher){
    cur_id++;

    std::string id = std::to_string(cur_id);
    std::string initial = "insert into user values (";
    std::string comma = ",";
    std::string ending = ");";

    std::string name_to_str = "'" + name + "'";
    std::string pwd_to_str = "'" +  password + "'";
    std::string usrName_to_str = "'" +  userName + "'";
    std::string isResearcher_to_str = "'" +  isResearcher + "'";

    std::string query_str = initial + id + comma + name_to_str+ comma + pwd_to_str + comma + usrName_to_str+comma+isResearcher_to_str  + ending;
    QString command = QString::fromStdString(query_str);

    std::cout << query_str << std::endl;
    runQuery(command);

}
