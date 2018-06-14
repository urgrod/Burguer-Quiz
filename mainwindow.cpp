#include "mainwindow.h"
#include "model.h"
#include "controller.h"

MainWindow::MainWindow() : QMainWindow()
{

    model = new Model();
    control = new Controller();

    this->setWindowTitle("Burger Quiz - Administration");
    this->resize(900,300);

    widgetGeneral = new QWidget;
    QHBoxLayout *qblGeneral = new QHBoxLayout;


    widgetGeneral->setLayout(qblGeneral);
    this->setCentralWidget(widgetGeneral);

    onglets = new QTabWidget(this);
    onglets->setGeometry(0,0,900,300);

    pageAccueil = new QWidget;
    pageAccueil->setLayout(createViewHome());

    pageTheme = new QWidget;
    pageTheme->setLayout(createViewTheme());

    pageQuestions = new QWidget;
    pageQuestions->setLayout(createViewQuestion());

    pagePropositions = new QWidget;
    pagePropositions->setLayout(createViewProposition());

    pageUser = new QWidget;
    pageUser->setLayout(createViewUser());

    pageLogout = new QWidget;
    pageLogout->setLayout(createViewLogout());


    onglets->addTab(pageAccueil, "Accueil");
    onglets->addTab(pageTheme, "Theme");
    onglets->addTab(pageQuestions, "Questions");
    onglets->addTab(pagePropositions, "Propositions");
    onglets->addTab(pageUser, "Utilisateur");
    onglets->addTab(pageLogout, "Quitter");

    onglets->setVisible(false);

    qblGeneral->addLayout(createViewLogin());

    connect(quitButton, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
    connect(loginButton, SIGNAL(clicked(bool)), this, SLOT(slotLogin()));
    connect(logoutButton, SIGNAL(clicked(bool)), this, SLOT(slotLogout()));

    connect(addThemeButton, SIGNAL(clicked(bool)), this, SLOT(slotAddTheme(int,int)));
    connect(updateThemeButton, SIGNAL(clicked(bool)), this, SLOT(slotUpdateTheme(int,int)));
    connect(deleteThemeButton, SIGNAL(clicked(bool)), this, SLOT(slotDeleteTheme(int,int)));
//    connect(selectThemeButton, SIGNAL(clicked(bool)), this, SLOT(slotSelectTheme()));

    connect(addQuestionButton, SIGNAL(clicked(bool)), this, SLOT(slotAddQuestion(int,int)));
    connect(updateQuestionButton, SIGNAL(clicked(bool)), this, SLOT(slotUpdateQuestion(int,int)));
    connect(deleteQuestionButton, SIGNAL(clicked(bool)), this, SLOT(slotDeleteQuestion(int,int)));
//    connect(selectQuestionButton, SIGNAL(clicked(bool)), this, SLOT(slotSelectQuestion()));

    connect(addPropositionButton, SIGNAL(clicked()), this, SLOT(slotAddProposition(int,int)));
    connect(updatePropositionButton, SIGNAL(clicked()), this, SLOT(slotUpdateProposition(int,int)));
    connect(deletePropositionButton, SIGNAL(clicked()), this, SLOT(slotDeleteProposition(int,int)));
//    connect(selectPropositionButton, SIGNAL(clicked(bool)), this, SLOT(slotSelectProposition()));


    connect(addUserButton, SIGNAL(clicked(bool)), this, SLOT(slotAddUser()));
    connect(updateUserButton, SIGNAL(clicked(bool)), this, SLOT(slotUpdateUser()));
    connect(deleteUserButton, SIGNAL(clicked(bool)), this, SLOT(slotDeleteUser()));
    connect(selectUserButton, SIGNAL(clicked(bool)), this, SLOT(slotSelectUser()));

    //test
    connect(tableTheme, SIGNAL(cellClicked(int,int)), this, SLOT(slotSelectTheme(int,int)));
    connect(tableQuestion, SIGNAL(cellClicked(int,int)), this, SLOT(slotSelectQuestion(int, int)));
    connect(tableProposition, SIGNAL(cellClicked(int,int)), this, SLOT(slotSelectProposition(int,int)));

    populateDropdownTheme();
    populateDropdownQuestion();
    populateDropdownProposition();
    populateDropdownReponse();
//    populateDropdownUser();

}

MainWindow::~MainWindow()
{
}


QLayout *MainWindow::createViewLogin()
{

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;

    QVBoxLayout *qboxLayout4 = new QVBoxLayout;

    QString ip = "127.0.0.1";



    loginInput = new QLineEdit;
    passwordInput = new QLineEdit;
    passwordDatabaseInput = new QLineEdit;
    ipDatabaseInput = new QLineEdit;
    loginButton = new QPushButton("Se connecter");

    ipDatabaseInput->setText(ip);
    passwordDatabaseInput->setEchoMode(QLineEdit::Password);
    passwordInput->setEchoMode(QLineEdit::Password);

    loginText = new QLabel("Login:");
    passwordText = new QLabel("Mot de passe:");
    passworddatabaseText = new QLabel("Mot de passe de la BDD:");
    ipDatabaseText = new QLabel("Adresse IP de la BDD:");


    qboxLayout1->addWidget(loginText);
    qboxLayout1->addWidget(loginInput);
    qboxLayout1->addWidget(passwordText);
    qboxLayout1->addWidget(passwordInput);
    qboxLayout2->addWidget(ipDatabaseText);
    qboxLayout2->addWidget(ipDatabaseInput);
    qboxLayout2->addWidget(passworddatabaseText);
    qboxLayout2->addWidget(passwordDatabaseInput);
    qboxLayout3->addWidget(loginButton);

    qboxLayout4->addLayout(qboxLayout1);
    qboxLayout4->addLayout(qboxLayout2);
    qboxLayout4->addLayout(qboxLayout3);


    return qboxLayout4;
}

QLayout *MainWindow::createViewHome()
{

    QHBoxLayout *qboxLayout = new QHBoxLayout;

    QLabel *text  = new QLabel("Tableau des scores a afficher");

    qboxLayout->addWidget(text);

//    qgrouBox->setLayout(qboxLayout);

//    return qgrouBox;

    return qboxLayout;

}

QLayout *MainWindow::createViewProposition()
{


    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;
    QHBoxLayout *qboxLayout6 = new QHBoxLayout;
    QHBoxLayout *qboxLayout7 = new QHBoxLayout;
    QHBoxLayout *qboxLayout8 = new QHBoxLayout;
    QHBoxLayout *qboxLayout9 = new QHBoxLayout;
    QHBoxLayout *qboxLayout10 = new QHBoxLayout;




    QVBoxLayout *qboxLayout5 = new QVBoxLayout;


//    dropdownQuestion = new QComboBox;
//    dropdownTheme = new QComboBox;
//    dropdownProposition = new QComboBox;
    addPropositionLabel = new QLabel("Ajouter des propositions");
    addProposition1 = new QLineEdit;
//    addProposition2 = new QLineEdit;
//    addProposition3 = new QLineEdit;
    answerPropositionLabel = new QLabel("Choisir la bonne reponse:");
//    answerRadio1 = new QRadioButton("Question 1");
//    answerRadio2 = new QRadioButton("Question2");
//    answerRadio3 = new QRadioButton("les 2");
//    answerRadio4 = new QRadioButton("Question 1");
//    answerRadio5 = new QRadioButton("Question2");
//    answerRadio6 = new QRadioButton("les 2");
//    answerRadio7 = new QRadioButton("Question 1");
//    answerRadio8 = new QRadioButton("Question2");
//    answerRadio9 = new QRadioButton("les 2");

    dropdownReponse1 = new QComboBox;
//    dropdownReponse2 = new QComboBox;
//    dropdownReponse3 = new QComboBox;

    addPropositionButton = new QPushButton("Ajouter");
    updatePropositionButton = new QPushButton("Modifier");
    deletePropositionButton = new QPushButton("Supprimer");
//    selectPropositionButton = new QPushButton("selectionner la proposition");

   tableProposition = new QTableWidget;
   tableProposition->setEditTriggers(QAbstractItemView::NoEditTriggers);
//   tableProposition->setHorizontalHeaderItem(0, new QTableWidgetItem("Proposition"));
//   tableProposition->setColumnHidden(0,true);



    qboxLayout9->addWidget(addPropositionLabel);
    qboxLayout9->addWidget(tableProposition);

//    qboxLayout1->addWidget(dropdownQuestion);
//    qboxLayout1->addWidget(dropdownTheme);

    qboxLayout2->addWidget(addProposition1);
//    qboxLayout2->addWidget(addProposition2);
//    qboxLayout2->addWidget(addProposition3);

    qboxLayout3->addWidget(addPropositionButton);
    qboxLayout3->addWidget(updatePropositionButton);
    qboxLayout3->addWidget(deletePropositionButton);

    qboxLayout8->addWidget(answerPropositionLabel);
    qboxLayout8->addWidget(dropdownReponse1);
//    qboxLayout8->addWidget(dropdownReponse2);
//    qboxLayout8->addWidget(dropdownReponse3);


//    qboxLayout4->addWidget(answerRadio1);
//    qboxLayout4->addWidget(answerRadio4);
//    qboxLayout4->addWidget(answerRadio7);

//    qboxLayout6->addWidget(answerRadio2);
//    qboxLayout6->addWidget(answerRadio5);
//    qboxLayout6->addWidget(answerRadio8);

//    qboxLayout7->addWidget(answerRadio3);
//    qboxLayout7->addWidget(answerRadio6);
//    qboxLayout7->addWidget(answerRadio9);

//    qboxLayout10->addWidget(selectPropositionButton);



    qboxLayout5->addLayout(qboxLayout9);
    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout10);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout8);
    qboxLayout5->addLayout(qboxLayout4);
    qboxLayout5->addLayout(qboxLayout6);
    qboxLayout5->addLayout(qboxLayout7);
    qboxLayout5->addLayout(qboxLayout3);

    populateDropdownProposition();

    return qboxLayout5;
}

QLayout *MainWindow::createViewQuestion()
{
    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;
    QHBoxLayout *qboxLayout6 = new QHBoxLayout;

    QVBoxLayout *qboxLayout5 = new QVBoxLayout;

//    dropdownQuestion = new QComboBox;
//    dropdownQuestion->addItem("choisir une question");
    tableQuestion = new QTableWidget;
    addQuestion1 = new QLineEdit;
    textLabel1 = new QLabel(",");
    addQuestion2 = new QLineEdit;
    textLabel2 = new QLabel("ou les deux?");
    textLabel3 =new QLabel("Choisir un theme:");
    addQuestionButton = new QPushButton("Ajouter");
    updateQuestionButton = new QPushButton("Modifier");
    deleteQuestionButton = new QPushButton("Supprimer");
//    selectQuestionButton = new QPushButton("Selectionner la question");

    qboxLayout1->addWidget(tableQuestion);
//    qboxLayout1->addWidget(dropdownQuestion);

//    qboxLayout6->addWidget(selectQuestionButton);

    tableQuestion->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableQuestion->setHorizontalHeaderItem(0, new QTableWidgetItem("Question"));
    tableQuestion->setColumnHidden(0,true);

    qboxLayout2->addWidget(addQuestion1);
    qboxLayout2->addWidget(textLabel1);
    qboxLayout2->addWidget(addQuestion2);
    qboxLayout2->addWidget(textLabel2);

//    qboxLayout3->addWidget(textLabel3);

    qboxLayout4->addWidget(addQuestionButton);
    qboxLayout4->addWidget(updateQuestionButton);
    qboxLayout4->addWidget(deleteQuestionButton);

    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout6);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout3);
    qboxLayout5->addLayout(qboxLayout4);

    populateDropdownQuestion();

    return qboxLayout5;

}


QLayout *MainWindow::createViewTheme()
{

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;

    QVBoxLayout *qboxLayout5 = new QVBoxLayout;

    textTheme = new QLabel("Choisir un theme");
    inputTheme = new QLineEdit;
    addThemeButton = new QPushButton("Ajouter");
    updateThemeButton = new QPushButton("Modifier");
    deleteThemeButton = new QPushButton ("Supprimer");

    tableTheme = new QTableWidget(this);
    tableTheme->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableTheme->setHorizontalHeaderItem(0, new QTableWidgetItem("Theme"));


    qboxLayout1->addWidget(textTheme);
    qboxLayout1->addWidget(tableTheme);

    qboxLayout2->addWidget(inputTheme);

    qboxLayout3->addWidget(addThemeButton);
    qboxLayout3->addWidget(updateThemeButton);
    qboxLayout3->addWidget(deleteThemeButton);


    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout3);

    populateDropdownTheme();


    return qboxLayout5;
}

QLayout *MainWindow::createViewUser()
{

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;
    QHBoxLayout *qboxLayout5 = new QHBoxLayout;
    QHBoxLayout *qboxLayout6 = new QHBoxLayout;
    QHBoxLayout *qboxLayout7 = new QHBoxLayout;

    QVBoxLayout *qboxLayout8 = new QVBoxLayout;

    dropdownUser = new QComboBox;
    inputPseudo = new QLineEdit;
    inputName = new QLineEdit;
    inputFirstname = new QLineEdit;
    inputMail = new QLineEdit;
    inputAvatar = new QLineEdit;
    inputPasswordUser = new QLineEdit;
    inputPasswordVerifUser = new QLineEdit;
    textUser = new QLabel("Droit d'administration?");
    adminNoRadio = new QRadioButton("Non");
    adminYesRadio = new QRadioButton("Oui");
    addUserButton = new QPushButton("Ajouter");
    updateUserButton = new QPushButton("Modifier");
    deleteUserButton = new QPushButton("Supprimer");
    selectUserButton = new QPushButton("Selectionner");
    textUser1 = new QLabel("Pseudo:");
    textUser2 = new QLabel("Prenom:");
    textUser3 = new QLabel("Nom:");
    textUser4 = new QLabel("Mail:");
    textUser5 = new QLabel("Avatar:");
    textUser6 = new QLabel("Mot de passe:");
    textUser7 = new QLabel("Confirmation:");


    inputPasswordUser->setEchoMode(QLineEdit::Password);
    inputPasswordVerifUser->setEchoMode(QLineEdit::Password);

    qboxLayout1->addWidget(dropdownUser);
    qboxLayout1->addWidget(selectUserButton);

    qboxLayout2->addWidget(textUser1);
    qboxLayout2->addWidget(inputPseudo);

    qboxLayout3->addWidget(textUser2);
    qboxLayout3->addWidget(inputName);
    qboxLayout3->addWidget(textUser3);
    qboxLayout3->addWidget(inputFirstname);

    qboxLayout4->addWidget(textUser4);
    qboxLayout4->addWidget(inputMail);
    qboxLayout4->addWidget(textUser5);
    qboxLayout4->addWidget(inputAvatar);

    qboxLayout5->addWidget(textUser6);
    qboxLayout5->addWidget(inputPasswordUser);
    qboxLayout5->addWidget(textUser7);
    qboxLayout5->addWidget(inputPasswordVerifUser);

    qboxLayout6->addWidget(textUser);
    qboxLayout6->addWidget(adminNoRadio);
    qboxLayout6->addWidget(adminYesRadio);

    qboxLayout7->addWidget(addUserButton);
    qboxLayout7->addWidget(updateUserButton);
    qboxLayout7->addWidget(deleteUserButton);

    qboxLayout8->addLayout(qboxLayout1);
    qboxLayout8->addLayout(qboxLayout2);
    qboxLayout8->addLayout(qboxLayout3);
    qboxLayout8->addLayout(qboxLayout4);
    qboxLayout8->addLayout(qboxLayout5);
    qboxLayout8->addLayout(qboxLayout6);
    qboxLayout8->addLayout(qboxLayout7);

    populateDropdownUser();

    return qboxLayout8;

}

QLayout *MainWindow::createViewLogout()
{

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;

    QVBoxLayout *qboxLayout2 = new QVBoxLayout;

    logoutButton = new QPushButton("Se deconnecter");
    quitButton = new QPushButton("Quitter le programme");

    qboxLayout1->addWidget(logoutButton);
    qboxLayout1->addWidget(quitButton);

    qboxLayout2->addLayout(qboxLayout1);

    return qboxLayout2;
}

void MainWindow::populateDropdownTheme()
{
    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    int row =0;
    model->connectToDatabase(password,ip);
    model->requestTheme(2, ip, 1);

    tableTheme->setColumnHidden(0,true);


    while(model->result->next())
    {
        tableTheme->setItem(row, 1, new QTableWidgetItem(model->result->getString(2).c_str()));
        tableTheme->setItem(row,0, new QTableWidgetItem(model->result->getString(1).c_str()));
        row++;
    }

    tableTheme->setRowCount(row);
    tableTheme->setColumnCount(2);

}

void MainWindow::populateDropdownReponse()
{
    dropdownReponse1->addItem("libelle 1");
    dropdownReponse1->addItem("libelle 2");
    dropdownReponse1->addItem("les 2");
//    dropdownReponse2->addItem("libelle 1");
//    dropdownReponse2->addItem("libelle 2");
//    dropdownReponse2->addItem("les 2");
//    dropdownReponse3->addItem("libelle 1");
//    dropdownReponse3->addItem("libelle 2");
//    dropdownReponse3->addItem("les 2");

}

void MainWindow::populateDropdownUser()
{
    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    model->connectToDatabase(password,ip);
    model->requestUser(2, ip, ip, ip, ip, ip, 1, ip);


    while(model->result->next())
    {
        dropdownUser->addItem(tr(model->result->getString(1).c_str()));
    }



}

void MainWindow::populateDropdownProposition()
{
    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    int row =0;
    model->connectToDatabase(password,ip);
    model->requestPropositions(2, 1, ip, 1, 1);

    tableProposition->setColumnHidden(0,true);
    tableProposition->setColumnHidden(2,true);
    tableProposition->setColumnHidden(3,true);



    while(model->result->next())
    {


        tableProposition->setItem(row, 0, new QTableWidgetItem(model->result->getString(1).c_str()));
        tableProposition->setItem(row, 1, new QTableWidgetItem(model->result->getString(2).c_str()));
        tableProposition->setItem(row, 2, new QTableWidgetItem(model->result->getString(3).c_str()));
        tableProposition->setItem(row, 3, new QTableWidgetItem(model->result->getString(4).c_str()));



        row++;
    }

    tableProposition->setRowCount(row);
    tableProposition->setColumnCount(4);

}

void MainWindow::populateDropdownQuestion()
{

    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    int row =0;
    model->connectToDatabase(password,ip);
    model->requestQuestions(2, ip, ip, 1, 1);

    tableQuestion->setColumnHidden(0,true);


    while(model->result->next())
    {
        QString test1 = model->result->getString(3).c_str();
        QString test2 = model->result->getString(2).c_str();

        QString test = test1 + ":" +test2;


        tableQuestion->setItem(row, 0, new QTableWidgetItem(model->result->getString(1).c_str()));
        tableQuestion->setItem(row, 1, new QTableWidgetItem(test));

        row++;
    }

    tableQuestion->setRowCount(row);
    tableQuestion->setColumnCount(2);


}

void MainWindow::slotLogin()
{

//    QString pseudo = loginInput->text();
//    QString password = passwordInput->text();
//    QString ip = ipDatabaseInput->text();
//    QString passwordDb = passwordDatabaseInput->text();

//    bool auth = model->authentificationUser(pseudo, password, passwordDb, ip);

//    if(auth == 1)
//    {
//        model->connectToDatabase(passwordDb,ip);
//        onglets->setVisible(true);
//        widgetGeneral->setVisible(false);

//    }

//    else
//    {
//        QMessageBox::information(this, "ERREUR", "Vous n'avez pas reussi a vous connecter, l'un des champs saisis est faux");
//    }

    onglets->setVisible(true);
    widgetGeneral->setVisible(false);
}

void MainWindow::slotLogout()
{
    onglets->setVisible(false);
    loginInput->clear();
    passwordInput->clear();
    passwordDatabaseInput->clear();
    widgetGeneral->setVisible(true);
}

void MainWindow::slotAddTheme(int row, int coll)
{
    QString theme = inputTheme->text();
//    int id = dropdownTheme->itemData(dropdownTheme->currentIndex()).toInt();
    int id2 = 1;

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Ajout d'un theme", "Voulez-vous ajouter le theme "+ theme +"?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(theme))
    {
        QString password = "burgerquiz";
        QString ip ="127.0.0.1";
        model->connectToDatabase(password,ip);
        model->requestTheme(1, theme, id2);


        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Ajout d'un theme", "Le theme "+theme +" a ete ajoute dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un theme", "Le theme "+theme +" n'a pas ete ajoute dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un theme", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputTheme->clear();
    }
}

void MainWindow::slotUpdateTheme(int row, int coll)
{
    QString theme = inputTheme->text();
//    int id = dropdownTheme->itemData(dropdownTheme->currentIndex()).toInt();
//    qDebug() << "id" << id;

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Mise a jour d'un theme", "Voulez-vous mettre a jour le theme "+ theme +"?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(theme))
    {
//        model->requestTheme(4, theme,id);\

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Mise a jour d'un theme", "Le theme "+theme +" a ete mis a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'un theme", "Le theme "+theme +" n'a pas ete mis a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'un theme", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputTheme->clear();
    }
}

void MainWindow::slotDeleteTheme(int row, int coll)
{
    QString theme = inputTheme->text();
//    int id = dropdownTheme->itemData(dropdownTheme->currentIndex()).toInt();
//    qDebug() << "id" << id;

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Suppression d'un theme", "Voulez-vous supprimer le theme "+ theme +" ainsi que les questions et propositions qui en depandent?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(theme))
    {
//        model->requestTheme(5, theme,id);\

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Suppression d'un theme", "Le theme "+theme +" a ete supprime dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Suppression d'un theme", "Le theme "+theme +" n'a pas ete supprime dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Suppression d'un theme", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputTheme->clear();
    }


}

void MainWindow::slotSelectTheme(int row, int coll)
{
    /*
     * recup de l'id select
     * demande de l'info de l'id en base
     * affichage de la requete dans les champs
    */
    QString theme = tableTheme->item(row, coll)->text();
    QString id = tableTheme->item(row,0)->text();

    inputTheme->setText(theme);

    qDebug() << "id"<<id;


}

void MainWindow::slotAddQuestion(int row, int coll)
{

    QString libelle1 = addQuestion1->text();
    QString libelle2 = addQuestion2->text();
    int idQuestion =1;
    int idTheme = 1; /* = idQuestion selected*/

    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    model->connectToDatabase(password,ip);
    model->requestQuestions(1, libelle1, libelle2, idTheme, idQuestion);


    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Ajout d'une question", "Voulez-vous ajouter la question"+ libelle1 +", "+ libelle2 + "?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(libelle1) && model->verificationData(libelle1))
    {
        model->requestQuestions(1, libelle1, libelle2,idTheme ,idQuestion);\

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Ajout d'une question", "La question"+libelle1 +","+libelle2 +" a ete ajoutee dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Ajout d'une question", "La question"+libelle1 +","+libelle1 +" n'a pas ete ajoutee dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Ajout d'une question", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        addQuestion1->clear();
        addQuestion2->clear();
    }

}

void MainWindow::slotUpdateQuestion(int row, int coll)
{
    QString libelle1 = addQuestion1->text();
    QString libelle2 = addQuestion2->text();
    int idQuestion; /* = idQuestion selected*/
    int idTheme; /* = idQuestion selected*/


    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Mise a jour d'une question", "Voulez-vous mettre a jour la question"+ libelle1 +", "+ libelle2 + "?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(libelle1) && model->verificationData(libelle1))
    {
        model->requestQuestions(4, libelle1, libelle2,idTheme ,idQuestion);\

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Mise a jour d'une question", "La question"+libelle1 +","+libelle2 +" a ete mise a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'une question", "La question"+libelle1 +","+libelle1 +" n'a pas ete mise a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'une question", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        addQuestion1->clear();
        addQuestion2->clear();
    }

}

void MainWindow::slotDeleteQuestion(int row, int coll)
{
    QString libelle1 = addQuestion1->text();
    QString libelle2 = addQuestion2->text();
    int idQuestion; /* = idQuestion selected*/
    int idTheme; /* = idQuestion selected*/


    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Suppression d'une question", "Voulez-vous supprimer la question"+ libelle1 +", "+ libelle2 + "ainsi que les propositions qui en depandent?", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(libelle1) && model->verificationData(libelle1))
    {
        model->requestQuestions(5, libelle1, libelle2,idTheme ,idQuestion);\

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Suppression d'une question", "La question"+libelle1 +","+libelle2 +" a ete supprime dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Suppression d'une question", "La question"+libelle1 +","+libelle1 +" n'a pas ete supprime dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Suppression d'une question", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        addQuestion1->clear();
        addQuestion2->clear();
    }
}

void MainWindow::slotSelectQuestion(int row, int coll)
{
    /*
     * recup de l'id select
     * demande de l'info de l'id en base
     * affichage de la requete dans les champs
    */

    QString id = tableQuestion->item(row,0)->text();
    QString text = tableQuestion->item(row, coll)->text();
    QList <QString> texts = text.split(":");

    addQuestion1->setText(texts[0]);
    addQuestion2->setText(texts[1]);

    qDebug()<<"id"<<id;

}

void MainWindow::slotAddProposition(int row, int coll)
{

    QString proposition1 = addProposition1->text();
//    QString proposition2 = addProposition2->text();
//    QString proposition3 = addProposition3->text();
    int reponseProposition1 = dropdownReponse1->currentIndex()+1;
//    int reponseProposition2 = dropdownReponse2->currentIndex()+1;
//    int reponseProposition3 = dropdownReponse3->currentIndex()+1;
    int idQuestion =1;
    int idProposition =1;

    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    model->connectToDatabase(password,ip);
    model->requestPropositions(1, idProposition, proposition1, reponseProposition1, idQuestion);
//    model->requestPropositions(1, idProposition, proposition2, reponseProposition2, idQuestion);
//    model->requestPropositions(1, idProposition, proposition3, reponseProposition3, idQuestion);


    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Ajout d'une proposition", "Les propositions"+proposition1 +" vont etre ajoutees de la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(proposition1))
    {
//        model->requestPropositions(5, idProposition, proposition1, reponseProposition1, idQuestion);\
//        model->requestPropositions(5, idProposition, proposition2, reponseProposition2, idQuestion);
//        model->requestPropositions(5, idProposition, proposition3, reponseProposition3, idQuestion);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Ajout d'une proposition", "Les propositions"+proposition1 +" a ete ajoute dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Ajout d'une proposition", "Les propositions"+proposition1 +" n'ont pas ete ajoute dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Ajout d'une proposition", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputPasswordVerifUser->clear();
    }
}

void MainWindow::slotUpdateProposition(int row, int coll)
{

    QString proposition1 = addProposition1->text();
//    QString proposition2 = addProposition2->text();
//    QString proposition3 = addProposition3->text();
    int reponseProposition1;
    int reponseProposition2;
    int reponseProposition3;
    int idQuestion;
    int idProposition;

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Mise a jour d'une proposition", "Les propositions"+proposition1 +" vont etre supprimes de la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(proposition1))
    {
        model->requestPropositions(5, idProposition, proposition1, reponseProposition1, idQuestion);\
//        model->requestPropositions(5, idProposition, proposition2, reponseProposition2, idQuestion);
//        model->requestPropositions(5, idProposition, proposition3, reponseProposition3, idQuestion);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Mise a jour d'une proposition", "Les propositions"+proposition1 +" ont ete mises a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'une proposition", "Les propositions"+proposition1 + "n'ont pas ete mises a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Mise a jour d'une proposition", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputPasswordVerifUser->clear();


    }


}

void MainWindow::slotDeleteProposition(int row, int coll)
{

    QString proposition1 = addProposition1->text();
//    QString proposition2 = addProposition2->text();
//    QString proposition3 = addProposition3->text();
    int reponseProposition1;
    int reponseProposition2;
    int reponseProposition3;
    int idQuestion;
    int idProposition;

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Suppression d'une proposition", "Les propositions"+proposition1 +" vont etre supprimes de la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && model->verificationData(proposition1))
    {
        model->requestPropositions(5, idProposition, proposition1, reponseProposition1, idQuestion);\
//        model->requestPropositions(5, idProposition, proposition2, reponseProposition2, idQuestion);
//        model->requestPropositions(5, idProposition, proposition3, reponseProposition3, idQuestion);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Suppression d'une proposition", "Les propositions"+proposition1 +" ont ete supprimes de la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Suppression d'une proposition", "Les propositions"+proposition1 +" n'ont pas ete supprimes de la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Suppression d'une proposition", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputPasswordVerifUser->clear();


    }
}

void MainWindow::slotSelectProposition(int row, int coll)
{

    /*
     * recup de l'id select
     * demande de l'info de l'id en base
     * affichage de la requete dans les champs
    */

    QString id = tableProposition->item(row,0)->text();
    QString text = tableProposition->item(row, coll)->text();
    QString reponse = tableProposition->item(row,2)->text();
    int reponseInt = reponse.toInt() -1;

    addProposition1->setText(text);
    dropdownReponse1->setCurrentIndex(reponseInt);

    qDebug()<<"id"<<id;


}

void MainWindow::slotAddUser()
{

    QString pseudo = inputPseudo->text();
    QString name = inputName->text();
    QString lastname = inputFirstname->text();
    QString password = inputPasswordUser->text();
    QString passwordVerif = inputPasswordVerifUser->text();
    QString mail = inputMail->text();
    QString avatar = inputAvatar->text();
    bool yesVip = adminYesRadio->isChecked();

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Ajout d'un utilisateur", "L'utilisateur "+pseudo +" va etre ajoute a la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && password == passwordVerif && model->verificationData(pseudo) && model->verificationData(name) && model->verificationData(lastname) && model->verificationData(password) && model->verificationData(passwordVerif))
    {
        model->requestUser(1, pseudo, password, mail, name, lastname, yesVip, avatar);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Ajout d'un utilisateur", "L'utilisateur "+pseudo +" a ete ajoute a la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un utilisateur", "L'utilisateur "+pseudo +" n'a pas ete ajoute a la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un utilisateur", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputPasswordVerifUser->clear();
        inputMail->clear();
        inputAvatar->clear();


    }

}

void MainWindow::slotUpdateUser()
{
    QString pseudo = inputPseudo->text();
    QString name = inputName->text();
    QString lastname = inputFirstname->text();
    QString password = inputPasswordUser->text();
    QString passwordVerif = inputPasswordVerifUser->text();
    QString mail = inputMail->text();
    QString avatar = inputAvatar->text();
    bool yesVip = adminYesRadio->isChecked();

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Ajout d'un utilisateur", "L'utilisateur "+pseudo +" va etre mis a jour dans la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && password == passwordVerif && model->verificationData(pseudo) && model->verificationData(name) && model->verificationData(lastname) && model->verificationData(password) && model->verificationData(passwordVerif))
    {
        model->requestUser(4, pseudo, password, mail, name, lastname, yesVip, avatar);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Ajout d'un utilisateur", "L'utilisateur "+pseudo +" a ete mis a jour dans la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un utilisateur", "L'utilisateur "+pseudo +" n'a pas ete mis a jour dana la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Ajout d'un utilisateur", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputPasswordVerifUser->clear();
        inputMail->clear();
        inputMail->clear();
        inputAvatar->clear();



    }

}

void MainWindow::slotDeleteUser()
{

    QString pseudo = inputPseudo->text();
    QString name = inputName->text();
    QString mail = inputMail->text();
    QString lastname = inputFirstname->text();
    QString password = inputPasswordUser->text();
    QString passwordVerif = inputPasswordVerifUser->text();
    QString avatar = inputAvatar->text();
    bool yesVip = adminYesRadio->isChecked();

    QMessageBox::StandardButton reponse;
    reponse = QMessageBox::question(this, "Suppression d'un utilisateur", "L'utilisateur "+pseudo +" va etre supprime de la base", QMessageBox::Yes|QMessageBox::No);

    if(reponse ==  QMessageBox::Yes && password == passwordVerif && model->verificationData(pseudo) && model->verificationData(name) && model->verificationData(lastname))
    {
        model->requestUser(5, pseudo, password, mail, name, lastname, yesVip, avatar);

        if(model->getRequestEffect())
        {
            reponse = QMessageBox::question(this, "Suppression d'un utilisateur", "L'utilisateur "+pseudo +" a ete supprime de la base", QMessageBox::Yes|QMessageBox::No);
        }
        else {
            reponse = QMessageBox::question(this, "[ERREUR] Suppression d'un utilisateur", "L'utilisateur "+pseudo +" n'a pas ete supprime de la base", QMessageBox::Yes|QMessageBox::No);
        }
    }
    else {

        reponse = QMessageBox::question(this, "[ERREUR] Suppression d'un utilisateur", "L'un des champs de saisi est vide", QMessageBox::Yes|QMessageBox::No);

        inputPseudo->clear();
        inputName->clear();
        inputFirstname->clear();
        inputPasswordUser->clear();
        inputMail->clear();
        inputPasswordVerifUser->clear();
        inputAvatar->clear();


    }

    inputPseudo->clear();
    inputName->clear();
    inputFirstname->clear();
    inputPasswordUser->clear();
    inputMail->clear();
    inputPasswordVerifUser->clear();
    inputAvatar->clear();


}

void MainWindow::slotSelectUser()
{
    QString pseudo = dropdownUser->currentText();

    QString password = "burgerquiz";
    QString ip ="127.0.0.1";
    model->connectToDatabase(password,ip);
    model->requestUser(3, pseudo, pseudo, pseudo, pseudo, pseudo, 1, pseudo);
    model->result->next();

    inputPseudo->setText(pseudo);
    inputName->setText(model->result->getString(4).c_str());
    inputFirstname->setText(model->result->getString(5).c_str());
    inputMail->setText(model->result->getString(3).c_str());
    inputAvatar->setText(model->result->getString(7).c_str());

    if(model->result->getBoolean(6) == 1) adminYesRadio->setChecked(1);
    if(model->result->getBoolean(6) == 0) adminNoRadio->setChecked(1);

}
