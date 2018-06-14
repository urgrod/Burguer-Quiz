#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCryptographicHash>
#include <QRadioButton>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

class Model:public QObject
{
public:
    Model();
    void connectToDatabase(QString password, QString ip);

    void requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, bool vip, QString avatar);
    void requestTheme(int requestType, QString nom, int id);
    void requestQuestions(int requestType, QString libelle2, QString libelle1, int idTheme, int idQuestion);
    void requestPropositions(int requestType, int idPropositions, QString proposition, int reponseQuestion, int idQuestion);
    void requestScore();

    bool authentificationUser(QString pseudo, QString password, QString passwordDatabase, QString ip);
    bool verificationData(QString data);
    int verificationRadio(QRadioButton *radio1, QRadioButton *radio2, QRadioButton *radio3);

    bool getRequestEffect();
    void setRequestEffect(bool reponse);


    sql::ResultSet *result;

private:
    sql::Driver *driver;
    sql::Connection *connection;
    sql::PreparedStatement *statement;
    bool requestEffect;


};

#endif // MODEL_H
