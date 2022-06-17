#include "singleton_db.h"

singleton_db * singleton_db::p_instance=0;
singleton_db_destroyer singleton_db::destroyer;
/**
 * @brief singleton_db_destroyer::~singleton_db_destroyer деструктор
 */
singleton_db_destroyer::~singleton_db_destroyer(){
    qDebug() << "deleted";
    delete p_instance;
}
/**
 * @brief singleton_db_destroyer::initialize копирует ссылку на объект класса singleton_db
 * для последующей работы с ней в классе singleton_db_destroyer
 * @param p
 */
void singleton_db_destroyer::initialize(singleton_db * p){
    qDebug() << "initialize";
    p_instance = p;
}
/**
 * @brief singleton_db::getInstance создание и сохранение ссылки в аргумент p_instance
 * @return
 */
singleton_db * singleton_db::getInstance(){
    qDebug() << "get instance";
    if(!p_instance){
        p_instance = new singleton_db();
        destroyer.initialize(p_instance);
    }
    return p_instance;
}
/**
 * @brief singleton_db::singleton_db конструктор для подключения к БД
 */
singleton_db::singleton_db()
{
    qDebug() << "constructor";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/tp_final_tochno/no-tre/everything/db/USG.db");

    if (!db.open()){
        qDebug() << "nope";
    }
    else{
        qDebug() << "ok";
    }
}
/**
 * @brief singleton_db::close_db закрытие БД
 */
void singleton_db::close_db(){
    if (db.open()){
        db.close();
        qDebug() << "closed";
    }
    else{
        qDebug() << "already closed";
    }
}
/**
 * @brief singleton_db::~singleton_db деструктор
 */
singleton_db::~singleton_db()
{

}
