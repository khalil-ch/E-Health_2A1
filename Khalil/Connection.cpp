#include "Connection.h"
#include "QSqlDatabase"

Connection::Connection()
{

}
bool Connection::createConnection()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test4");
    db.setUserName("khalil3");
    db.setPassword("khalil3");

    if(db.open())
        test=true;
    return test;
}
