#include "model.h"
#include "controller.h"

Model::Model()
{
}


void Model::connectToDatabase(QString password, QString ip)
{

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);


    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();
    }

    driver = get_driver_instance();
    connection = driver->connect(("tcp://" + ip.toStdString() + ":3306"), line[1].toStdString(), password.toStdString());

    if(connection)
    {
        connection->setSchema(line[3].toStdString());
        qDebug()<< "[INFO] Connexion sur " << line[3] << "effectuee";
    }
    else{
        qDebug()<< "[ERROR] Connexion sur " << line[3] << "echouee";

    }




}

void Model::requestUser(int requestType, QString pseudo, QString password, QString mail, QString name, QString lastname, QString vip, QString avatar)
{
    if(requestType == 1)
    {
        //requete ajout

        statement = connection->prepareStatement("INSERT INTO USER (pseudo, password, mail, name, lastname, vip, avatar)"
                                                " VALUES (?,?,?,?,?,?,?)");
        statement->setString(1,pseudo.toStdString());
        statement->setString(2,password.toStdString());
        statement->setString(3,mail.toStdString());
        statement->setString(4,name.toStdString());
        statement->setString(5,lastname.toStdString());
        statement->setString(7,avatar.toStdString());
        statement->setString(6, vip.toStdString());

        result = statement->executeQuery();

    }

    if(requestType == 2)
    {
        //requete lecture all
        statement = connection->prepareStatement("SELECT * FROM USER");

        result = statement->executeQuery();


    }

    if(requestType == 3)
    {
        //requete lecture un seul
        statement = connection->prepareStatement("SELECT * FROM USER WHERE pseudo =?");

        statement->setString(1,pseudo.toStdString());

        result = statement->executeQuery();
        return;
    }



    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE USER SET pseudo = ?, password = ?, mail = ?, name =?, lastname=?, vip =?, avatar =?;");

        statement->setString(1,pseudo.toStdString());
        statement->setString(2,password.toStdString());
        statement->setString(3,mail.toStdString());
        statement->setString(4,name.toStdString());
        statement->setString(5,lastname.toStdString());
        statement->setString(6,vip.toStdString());
        statement->setString(7,avatar.toStdString());


        result = statement->executeQuery();



    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM USER WHERE pseudo =?");

        statement->setString(1,pseudo.toStdString());

        result = statement->executeQuery();



    }
}

void Model::requestTheme(int requestType, QString nom, int id)
{



    if(requestType == 1)
    {

        qDebug() <<"nom theme" << nom;

        //requete ajout
        statement = connection->prepareStatement("INSERT INTO THEME (id_theme, name_theme) VALUES (NULL, '?');");

        qDebug() <<"nom theme" << nom;

        statement->setString(1,nom.toStdString());

        qDebug() <<"nom theme" << nom;

        result = statement->executeQuery();



    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM theme");

        result = statement->executeQuery();


    }

    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM theme WHERE id_theme = ?");

        statement->setInt(1,id);

        result = statement->executeQuery();


    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE theme SET name_theme = ? WHERE theme.id_theme = ?");

        statement->setString(1,nom.toStdString());
        statement->setInt(2, id);

        result = statement->executeQuery();



    }

    if(requestType == 5)
    {
        statement = connection->prepareStatement("DELETE FROM theme WHERE theme.id_theme = ?");

        statement->setInt(1,id);

        result = statement->executeQuery();

    }


}

void Model::requestQuestions(int requestType, QString libelle2, QString libelle1, int idTheme, int idQuestion)
{


    if(requestType == 1)
    {
        //requete ajout

        statement = connection->prepareStatement("INSERT INTO questions (id_questions, libelle1, libelle2, id_theme) VALUES (NULL, ?,?,?)");

        statement->setString(1,libelle1.toStdString());
        statement->setString(2,libelle2.toStdString());
        statement->setInt(3,idTheme);

        result = statement->executeQuery();


    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM questions");

        result = statement->executeQuery();
    }

    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM questions WHERE id_questions = ?;");

        statement->setInt(1,idQuestion);

        result = statement->executeQuery();

    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE questions SET libelle1 = ?, libelle2 = ?, WHERE questions.id_questions = ?;");

        statement->setString(1,libelle1.toStdString());
        statement->setString(2,libelle2.toStdString());
        statement->setInt(3,idQuestion);

        result = statement->executeQuery();

    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM questions WHERE id_questions = ?;");

        statement->setInt(1,idQuestion);

        result = statement->executeQuery();


    }

}

void Model::requestPropositions(int requestType, int idPropositions, QString proposition, QString reponseQuestion, int idQuestion)
{

    if(requestType == 1)
    {
        //requete ajout
        statement = connection->prepareStatement("INSERT INTO propositions (id_propositions, proposition, reponse_question, id_question) VALUES (NULL, ?, ?, ?);");

        statement->setString(1,proposition.toStdString());
        statement->setString(2,reponseQuestion.toStdString());
        statement->setInt(3, idQuestion);


        result = statement->executeQuery();
    }

    if(requestType == 2)
    {
        //requete read all
        statement = connection->prepareStatement("SELECT * FROM propositions");

        result = statement->executeQuery();
    }

    if(requestType == 3)
    {
        //requete read 1
        statement = connection->prepareStatement("SELECT * FROM propositions WHERE id_propositions = ?;");

        statement->setInt(1, idPropositions);


        result = statement->executeQuery();
    }

    if(requestType == 4)
    {
        //requete update
        statement = connection->prepareStatement("UPDATE propositions SET proposition = ?, reponse_question = ?, WHERE propositions.id_proposition = ?;");

        statement->setString(1,proposition.toStdString());
        statement->setString(2, reponseQuestion.toStdString());
        statement->setInt(3, idPropositions);


        result = statement->executeQuery();
    }

    if(requestType == 5)
    {
        //requete delete
        statement = connection->prepareStatement("DELETE FROM propositions WHERE propositions.id_proposition = ?;");

        statement->setInt(1, idPropositions);


        result = statement->executeQuery();

    }


}

bool Model::authentificationUser(QString pseudo, QString password, QString passwordDatabase, QString ip)
{
    Controller *control = new Controller();

    QByteArray ba = QCryptographicHash::hash(passwordDatabase.toUtf8(), QCryptographicHash::Sha256);
    QByteArray ba2 = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    QString hashDatabase = ba.toHex();
    QString hash = ba2.toHex();

    QFile file("bdd.conf");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    QStringList line;

    while(!flux.atEnd())
    {
        line << flux.readLine();

    }

    if(line[2] == hashDatabase)
    {
        connectToDatabase(password, ip);

        requestUser(3, pseudo, password, pseudo, pseudo, pseudo, pseudo, pseudo);

        result->next();

        if(hashDatabase == line[2] && pseudo.toStdString() == result->getString(1).c_str() && hash.toStdString() == result->getString(2).c_str() && result->getInt(6) == 1)
        {
            control->setAuth(1);
            qDebug() << "[INFO] Authentification reussie, login: " << pseudo;
            //affichage de la vue d'administration

            return 1;
        }
        else
        {
            control->setAuth(0);
            return 0;
        }
    }
    else{
        qDebug() << "[INFO] Authentification echouee";
        control->setAuth(0);
        return 0;
    }
}

