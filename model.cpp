#include "model.h"

Model::Model()
{
}


void Model::connectToDatabase(QString password, QString ip)
{

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);

    qDebug()<<"password "<<password;

    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();
    }
      driver = get_driver_instance();
//    connection = driver->connect(("tcp://" + ip2.toStdString() + ":3306"), line[1].toStdString(), password.toStdString());
//    connection = driver->connect(("tcp://" + ip.toStdString() + ":3306"), line[1].toStdString(), "burgerquiz");
//      connection = driver->connect(("tcp://" + ip.toStdString() + ":3306"), line[1].toStdString(), "burgerquiz");
    connection = driver->connect(("tcp://" + ip.toStdString() + ":3306"), line[1].toStdString(), "burgerquiz"/*password.toStdString()*/);



    if(connection)
    {
        connection->setSchema(line[3].toStdString());

        qDebug()<< "[INFO] Connexion sur " << line[3] << "effectuee";
    }
    else{
        qDebug()<< "[ERROR] Connexion sur " << line[3] << "echouee";

    }




}

void Model::requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, bool vip, QString avatar)
{

    QByteArray ba = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hash = ba.toHex();

    if(requestType == 1)
    {
        //requete ajout

        statement = connection->prepareStatement("INSERT INTO USER (pseudo, password, mail, name, lastname, vip, avatar)"
                                                " VALUES (?,?,?,?,?,?,?)");
        statement->setString(1,pseudo.toStdString());
        statement->setString(2,hash.toStdString());
        statement->setString(3,mail.toStdString());
        statement->setString(4,name.toStdString());
        statement->setString(5,lastname.toStdString());
        statement->setString(7,avatar.toStdString());
        statement->setBoolean(6, vip);

        result = statement->executeQuery();

        setRequestEffect(result);
        return;
    }

    if(requestType == 2)
    {
        //requete lecture all
        statement = connection->prepareStatement("SELECT * FROM USER");

        result = statement->executeQuery();
//        qDebug() << "tets" << result->getString(1).c_str();
        setRequestEffect(result);
        return;


    }

    if(requestType == 3)
    {
        //requete lecture un seul
        statement = connection->prepareStatement("SELECT * FROM USER WHERE pseudo =?");

        statement->setString(1,pseudo.toStdString());

        result = statement->executeQuery();
        setRequestEffect(result);
        return;
    }



    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE USER SET password = ?, mail = ?, name =?, lastname=?, vip =?, avatar =?;");

        statement->setString(1,hash.toStdString());
        statement->setString(2,mail.toStdString());
        statement->setString(3,name.toStdString());
        statement->setString(4,lastname.toStdString());
        statement->setBoolean(5,vip);
        statement->setString(6,avatar.toStdString());


        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM USER WHERE pseudo =?");

        statement->setString(1,pseudo.toStdString());

        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }
}

void Model::requestTheme(int requestType, QString nom, int id)
{



    if(requestType == 1)
    {

        //requete ajout
        statement = connection->prepareStatement("INSERT INTO THEME (id_theme, name_theme) VALUES (NULL, ?);");
        statement->setString(1,nom.toStdString());

        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM THEME");

        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }

    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM THEME WHERE name_theme = ?");

        statement->setString(1,nom.toStdString());

        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE THEME SET name_theme = ? WHERE THEME.id_theme = ?");

        statement->setString(1,nom.toStdString());
        statement->setInt(2, id);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;



    }

    if(requestType == 5)
    {
        statement = connection->prepareStatement("DELETE FROM THEME WHERE THEME.id_theme = ?");

        statement->setInt(1,id);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }


}

void Model::requestQuestions(int requestType, QString libelle2, QString libelle1, int idTheme, int idQuestion)
{


    if(requestType == 1)
    {
        //requete ajout

        statement = connection->prepareStatement("INSERT INTO QUESTIONS (id_question, libelle1, libelle2, id_theme) VALUES (NULL, ?,?,?)");

        statement->setString(1,libelle1.toStdString());
        statement->setString(2,libelle2.toStdString());
        statement->setInt(3,idTheme);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;


    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM QUESTIONS");

        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM QUESTIONS WHERE id_question = ?;");

        statement->setInt(1,idQuestion);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE `QUESTIONS` SET `libelle1` = ?, `libelle2` = ? WHERE `QUESTIONS`.`id_question` = ?;");

        statement->setString(1,libelle1.toStdString());
        statement->setString(2,libelle2.toStdString());
        statement->setInt(3,idQuestion);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM `QUESTIONS` WHERE `QUESTIONS`.`id_question` = ?");

        statement->setInt(1,idQuestion);

        result = statement->executeQuery();
        setRequestEffect(result);
        return;


    }

}

void Model::requestPropositions(int requestType, int idPropositions, QString proposition, int reponseQuestion, int idQuestion)
{

    if(requestType == 1)
    {
        //requete ajout
        statement = connection->prepareStatement("INSERT INTO PROPOSITIONS (id_propositions, proposition, reponse_question, id_question) VALUES (NULL, ?, ?, ?);");

        statement->setString(1,proposition.toStdString());
        statement->setInt(2,reponseQuestion);
        statement->setInt(3, idQuestion);


        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM `PROPOSITIONS` ;");

        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }


    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM PROPOSITIONS WHERE id_propositions = ?;");

        statement->setInt(1, idPropositions);


        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE `PROPOSITIONS` SET `proposition` = ?, `reponse_question` = ? WHERE `PROPOSITIONS`.`id_propositions` = ?;");

        statement->setString(1,proposition.toStdString());
        statement->setInt(2, reponseQuestion);
        statement->setInt(3, idPropositions);


        result = statement->executeQuery();
        setRequestEffect(result);
        return;

    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM `PROPOSITIONS` WHERE `PROPOSITIONS`.`id_propositions` = ? ");

        statement->setInt(1, idQuestion);


        result = statement->executeQuery();
        setRequestEffect(result);
        return;


    }


}

bool Model::authentificationUser(QString pseudo, QString password, QString passwordDatabase, QString ip)
{

    QByteArray ba = QCryptographicHash::hash(passwordDatabase.toUtf8(), QCryptographicHash::Sha256);
    QByteArray ba2 = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hashDatabase = ba.toHex();
    QString hash = ba2.toHex();
    bool vip =0;

    qDebug()<<"hash" << hash;
    qDebug()<<"hash DB" << hashDatabase;

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();

    }

    qDebug() << "file" << line[2];

    if(line[2] == hashDatabase)
    {
        connectToDatabase(password, ip);

        requestUser(3, pseudo, password, pseudo, pseudo, pseudo, vip, pseudo);

        result->next();

        if(hashDatabase == line[2] && pseudo.toStdString() == result->getString(1).c_str() && hash.toStdString() == result->getString(2).c_str() && result->getInt(6) == 1)
        {
            auth =1;
            qDebug() << "[INFO] Authentification reussie, login: " << pseudo;
            //affichage de la vue d'administration

            return 1;
        }
        else
        {
            qDebug() << "[INFO] Authentification echouee   2";

            auth = 0;
            return 0;
        }
    }
    else{
        qDebug() << "[INFO] Authentification echouee";
        auth = 0;
        return 0;
    }
}

bool Model::verificationData(QString data)
{
    if(data == "")
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool Model::getRequestEffect()
{
    return requestEffect;
}

void Model::setRequestEffect(bool reponse)
{
    requestEffect = reponse;
}

void Model::requestScore()
{
    statement = connection->prepareStatement("SELECT * FROM `SCORE` ");

    result = statement->executeQuery();
    setRequestEffect(result);
    return;

}

void Model::setAuth(bool value)
{
    auth = value;
}

bool Model::getAuth()
{
    return auth;
}
