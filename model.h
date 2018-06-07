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
    void connectToDatabase();
    bool requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, QString vip, QString avatar);
    bool requestTheme(int requestType, QString nom, QString id);
    bool requestQuestions(int requestType, QString libelle2, QString libelle1, QString idTheme, QString idQuestion);
    bool requestPropositions(int requestType, QString idPropositions, QString proposition, QString reponseQuestion, QString idQuestion);

private:
    QSqlDatabase db;
    QSqlQuery query;
    QSqlRecord record;
};

#endif // MODEL_H
