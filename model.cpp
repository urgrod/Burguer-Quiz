#include "model.h"

Model::Model()
{
}


void Model::connectToDatabase()
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

    qDebug() << db.open();

    if(db.open())
    {
        qDebug() << "[INFO] Connexion sur " << db.hostName() <<" reussie";
    }
    else
    {
        qDebug() << "[ERROR] Connexion sur " << db.hostName() << "echouee";

    }
}

bool Model::requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, QString vip, QString avatar)
{

    QSqlQuery query;
    QString request;
    QString base;
    QString value;

    if(requestType == 1)
    {
        //requete ajout
        base = "INSERT INTO `USER` (`pseudo`, `password`, `mail`, `name`, `lastname`, `vip`, `avatar`) ";
        value = "VALUES ('"+ pseudo +"', '"+ password +"', '"+ mail + "', '"+ name +"', '"+ lastname +"', '"+ vip + "', '"+ avatar +"');";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;

    }

    if(requestType == 2)
    {
        //requete lecture all
        base = "SELECT * FROM `USER`";
        value = "";
        request = base +value;

        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 3)
    {
        //requete lecture un seul
        base = "SELECT * FROM `USER` ";
        value = "WHERE `pseudo` = '"+ pseudo +"'";
        request = base + value;

        if(query.exec(base)) return 1;
        else return 0;
    }



    if(requestType == 4)
    {
        //requete update
        base = "UPDATE `USER` SET ";
        value = "`pseudo` ='" + pseudo +"', `password` = '"+ password + "', `mail` = '"+ mail + "' , `name` = '"+ name + "' , `lastname` = '"+ lastname + "' , `vip` = '"+ vip + "' ,"
            + " `avatar` = '"+ avatar + "' ;";
        request = base +value;

        if(query.exec(base)) return 1;
        else return 0;

    }

    if(requestType == 5)
    {
        //requete delete
        base = "DELETE FROM USER ";
        value = "WHERE pseudo = '"+ pseudo +"'";
        request = base + value;
        request = base + value;

        if(query.exec(base)) return 1;
        else return 0;

    }
}

bool Model::requestTheme(int requestType, QString nom, QString id)
{

    QSqlQuery query;
    QString request;
    QString base;
    QString value;


    if(requestType == 1)
    {
        //requete ajout
        base = "INSERT INTO THEME (name_theme) ";
        value = "VALUES = '"+ nom +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(base)) return 1;
        else return 0;

    }

    if(requestType == 2)
    {
        //requete read all
        base = "SELECT * FROM theme ";
        value = "";
        request = base + value;
        query.exec(request);


        if(query.exec(base)) return 1;
        else return 0;

    }

    if(requestType == 3)
    {
        //requete read 1
        base = "SELECT * FROM theme ";
        value = "WHERE id_theme = '"+ id +"';";
        request = base + value;
        query.exec(request);


        if(query.exec(base)) return 1;
        else return 0;

    }

    if(requestType == 4)
    {
        //requete update
        base = "UPDATE theme ";
        value = "SET name_theme = '"+ nom +"' WHERE theme.id_theme = '"+ id +"';";
        request = base + value;
        query.exec(request);


        if(query.exec(base)) return 1;
        else return 0;

    }

    if(requestType == 5)
    {
        //requete delete
        base = "DELETE FROM theme ";
        value = "WHERE id_theme = '"+ id +"';";
        request = base + value;
        query.exec(request);


        if(query.exec(base)) return 1;
        else return 0;

    }


}

bool Model::requestQuestions(int requestType, QString libelle2, QString libelle1, QString idTheme, QString idQuestion)
{

    QSqlQuery query;
    QString request;
    QString base;
    QString value;

    if(requestType == 1)
    {
        //requete ajout
        base = "INSERT INTO questions (id_questions, libelle1, libelle2, id_theme) ";
        value = "VALUES ( NULL, '"+ libelle1 +"', "+ libelle2 +"', '"+ idTheme +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 2)
    {
        //requete read all
        base = "SELECT * FROM questions ";
        value = "";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 3)
    {
        //requete read 1
        base = "SELECT * FROM questions ";
        value = "WHERE id_questions = '"+ idQuestion +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 4)
    {
        //requete update
        base = "UPDATE quesitons SET ";
        value = "libelle1 = '"+ libelle1 +"', libelle2 = '"+ libelle2 +"', WHERE questions.id_quesiton = '"+ idQuestion +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 5)
    {
        //requete delete
        base = "DELETE FROM questions";
        value = "WHERE questions.id_question = '"+ idQuestion +"'";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

}

bool Model::requestPropositions(int requestType, QString idPropositions, QString proposition, QString reponseQuestion, QString idQuestion)
{
    QSqlQuery query;
    QString request;
    QString base;
    QString value;

    if(requestType == 1)
    {
        //requete ajout
        base = "INSERT INTO propositions (id_propositions, proposition, reponse_question, id_question) VALUES ";
        value = " (NULL, '"+ proposition +"', '"+ reponseQuestion +"', '"+ idQuestion +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 2)
    {
        //requete read all
        base = "SELECT * FROM propositions;";
        value = "";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 3)
    {
        //requete read 1
        base = "SELECT * FROM propositions WHERE ";
        value = "id_propositions = '"+ idPropositions +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 4)
    {
        //requete update
        base = "UPDATE propositions SET ";
        value = "proposition = '"+ proposition +"', reponse_question = '"+ reponseQuestion +"' WHERE propositions.id_proposition = '"+ idPropositions +"'";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }

    if(requestType == 5)
    {
        //requete delete
        base = "DELETE FROM propositions WHERE ";
        value = "propositions.id_proposition = '"+ idPropositions +"';";
        request = base + value;
        query.exec(request);

        if(query.exec(request)) return 1;
        else return 0;
    }


}
