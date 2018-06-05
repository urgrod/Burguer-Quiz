#include "model.h"

Model::Model()
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);

    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();
    }

    db.setHostName(line[0]);
    db.setUserName(line[1]);
    db.setPassword(line[2]);
    db.setDatabaseName(line[3]);

    if(db.open())
    {
        qDebug() << "[INFO] Connexion sur " << db.hostName() <<" reussie";
    }
    else
    {
        qDebug() << "[ERROR] Connexion sur " << db.hostName() << "echouee";

    }
}


void Model::Database()
{
    db = QSqlDatabase::addDatabase("QPSQL");

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);

    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();
    }

    db.setHostName(line[0]);
    db.setUserName(line[1]);
    db.setPassword(line[2]);
    db.setDatabaseName(line[3]);

    if(db.open())
    {
        qDebug() << "[INFO] Connexion sur " << db.hostName() <<" reussie";
    }
    else
    {
        qDebug() << "[ERROR] Connexion sur " << db.hostName() << "echouee";

    }
}
