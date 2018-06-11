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
#include <QCryptographicHash>

class Model:public QObject
{
public:
    Model();
    void connectToDatabase(QString password, QString ip);
    void requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, QString vip, QString avatar);
    bool requestTheme(int requestType, QString nom, QString id);
    bool requestQuestions(int requestType, QString libelle2, QString libelle1, QString idTheme, QString idQuestion);
    bool requestPropositions(int requestType, QString idPropositions, QString proposition, QString reponseQuestion, QString idQuestion);
    bool authentificationUser(QString pseudo, QString password, QString passwordDatabase, QString ip);

private:
    QSqlDatabase *db;
    QSqlQuery *query;
    QSqlRecord *record;
};

#endif // MODEL_H
