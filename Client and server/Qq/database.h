#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlRecord>

class Database;

class DatabaseDestroyer
{
    private:
        Database * databasePointer;
    public:
        ~DatabaseDestroyer() {delete databasePointer;}
        void initialize(Database * p){databasePointer = p;}
};

class Database
{
    private:
        static Database * p_instance;
        static DatabaseDestroyer destroyer;
        static QSqlDatabase db;
    protected:
        Database(){
            db = QSqlDatabase::addDatabase("QSQLITE");
            db.setDatabaseName("D:/ProgTech/DataBase/build-DataBase-Desktop_Qt_6_2_3_MSVC2019_64bit-Debug/ForUsers.db");

            if(!db.open())
                qDebug()<<db.lastError().text();
        };
        Database(const Database& ); //=delete
        Database& operator = (Database &); //=delete
        ~Database(){db.close();}
        friend class DatabaseDestroyer;
    public:
        static Database* getInstance(){
            if (!p_instance)
            {
                p_instance = new Database();

                destroyer.initialize(p_instance);
            }
            return p_instance;
        }

        static QSqlQuery query_to_db(QString temp)
        {
            QSqlQuery query(db);
            query.exec(temp);
            return query;
        }
        //functions
};

Database * Database::p_instance = 0;
DatabaseDestroyer Database::destroyer;
QSqlDatabase Database::db;

#endif // DATABASE_H
