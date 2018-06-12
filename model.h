#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCryptographicHash>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

class Model:public QObject
{
public:
    Model();
    void connectToDatabase(QString password, QString ip);
    void requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, QString vip, QString avatar);
    void requestTheme(int requestType, QString nom, int id);
    void requestQuestions(int requestType, QString libelle2, QString libelle1, int idTheme, int idQuestion);
    void requestPropositions(int requestType, int idPropositions, QString proposition, QString reponseQuestion, int idQuestion);
    bool authentificationUser(QString pseudo, QString password, QString passwordDatabase, QString ip);

private:
    sql::Driver *driver;
    sql::Connection *connection;
    sql::PreparedStatement *statement;
    sql::ResultSet *result;
};

#endif // MODEL_H
