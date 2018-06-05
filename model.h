#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class Model:public QObject
{
public:
    Model();
    void Database();
    QByteArray request(const QString &query);

private:
    QSqlDatabase db;
    QSqlQuery query;
    QSqlRecord record;
};

#endif // MODEL_H
