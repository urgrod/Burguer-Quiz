#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setWindowTitle("Burger Quiz - Administration");
    this->resize(465,300);

    widgetGeneral = new QWidget;
    QHBoxLayout *qblGeneral = new QHBoxLayout;


    widgetGeneral->setLayout(qblGeneral);
    this->setCentralWidget(widgetGeneral);

    //test
    onglets = new QTabWidget(this);
    onglets->setGeometry(0,0,465,300);

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



    loginInput = new QLineEdit;
    passwordInput = new QLineEdit;
    passwordDatabaseInput = new QLineEdit;
    ipDatabaseInput = new QLineEdit;
    loginButton = new QPushButton("Se connecter");

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



    QVBoxLayout *qboxLayout5 = new QVBoxLayout;


    dropdownQuestion = new QComboBox;
    dropdownTheme = new QComboBox;
    dropdownNbProposition = new QSpinBox;
    addPropositionLabel = new QLabel("Ajouter des propositions");
    addProposition1 = new QLineEdit;
    addProposition2 = new QLineEdit;
    addProposition3 = new QLineEdit;
    answerPropositionLabel = new QLabel("Choisir la bonne reponse:");
    answerRadio1 = new QRadioButton("Question 1");
    answerRadio2 = new QRadioButton("Question2");
    answerRadio3 = new QRadioButton("les 2");
    answerRadio4 = new QRadioButton("Question 1");
    answerRadio5 = new QRadioButton("Question2");
    answerRadio6 = new QRadioButton("les 2");
    answerRadio7 = new QRadioButton("Question 1");
    answerRadio8 = new QRadioButton("Question2");
    answerRadio9 = new QRadioButton("les 2");
    addPropositionButton = new QPushButton("Ajouter");
    updatePropositionButton = new QPushButton("Modifier");
    deletePropositionButton = new QPushButton("Supprimer");


    qboxLayout9->addWidget(addPropositionLabel);
    qboxLayout9->addWidget(dropdownNbProposition);
    qboxLayout1->addWidget(dropdownQuestion);
    qboxLayout1->addWidget(dropdownTheme);
    qboxLayout2->addWidget(addProposition1);
    qboxLayout2->addWidget(addProposition2);
    qboxLayout2->addWidget(addProposition3);

    qboxLayout3->addWidget(addPropositionButton);
    qboxLayout3->addWidget(updatePropositionButton);
    qboxLayout3->addWidget(deletePropositionButton);

    qboxLayout8->addWidget(answerPropositionLabel);
    qboxLayout4->addWidget(answerRadio1);
    qboxLayout4->addWidget(answerRadio4);
    qboxLayout4->addWidget(answerRadio7);

    qboxLayout6->addWidget(answerRadio2);
    qboxLayout6->addWidget(answerRadio5);
    qboxLayout6->addWidget(answerRadio8);

    qboxLayout7->addWidget(answerRadio3);
    qboxLayout7->addWidget(answerRadio6);
    qboxLayout7->addWidget(answerRadio9);

    qboxLayout5->addLayout(qboxLayout9);
    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout8);
    qboxLayout5->addLayout(qboxLayout4);
    qboxLayout5->addLayout(qboxLayout6);
    qboxLayout5->addLayout(qboxLayout7);
    qboxLayout5->addLayout(qboxLayout3);

    return qboxLayout5;
}

QLayout *MainWindow::createViewQuestion()
{
    QGroupBox *qgroupBox = new QGroupBox;

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;

    QVBoxLayout *qboxLayout5 = new QVBoxLayout;

    dropdownQuestion = new QComboBox;
    dropdownQuestion->addItem("choisir une question");
    addQuestion1 = new QLineEdit;
    textLabel1 = new QLabel(",");
    addQuestion2 = new QLineEdit;
    textLabel2 = new QLabel("ou les deux?");
    textLabel3 =new QLabel("Choisir un theme:");
    dropdownThemeProposition = new QComboBox;
    addQuestionButton = new QPushButton("Ajouter");
    updateQuestionButton = new QPushButton("Modifier");
    deleteQuestionButton = new QPushButton("Supprimer");

    qboxLayout1->addWidget(dropdownThemeProposition);
    qboxLayout1->addWidget(dropdownQuestion);


    qboxLayout2->addWidget(addQuestion1);
    qboxLayout2->addWidget(textLabel1);
    qboxLayout2->addWidget(addQuestion2);
    qboxLayout2->addWidget(textLabel2);

    qboxLayout3->addWidget(textLabel3);

    qboxLayout4->addWidget(addQuestionButton);
    qboxLayout4->addWidget(updateQuestionButton);
    qboxLayout4->addWidget(deleteQuestionButton);

    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout3);
    qboxLayout5->addLayout(qboxLayout4);


    return qboxLayout5;

}


QLayout *MainWindow::createViewTheme()
{

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;

    QVBoxLayout *qboxLayout5 = new QVBoxLayout;

    textTheme = new QLabel("Choisir un theme");
    dropdownTheme = new QComboBox;
    inputTheme = new QLineEdit;
    addThemeButton = new QPushButton("Ajouter");
    updateThemeButton = new QPushButton("Modifier");
    deleteThemeButton = new QPushButton ("Supprimer");

    qboxLayout1->addWidget(textTheme);
    qboxLayout1->addWidget(dropdownTheme);

    qboxLayout2->addWidget(inputTheme);

    qboxLayout3->addWidget(addThemeButton);
    qboxLayout3->addWidget(updateThemeButton);
    qboxLayout3->addWidget(deleteThemeButton);


    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout3);


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
    adminNoRadio = new QRadioButton("Oui");
    adminYesRadio = new QRadioButton("Non");
    addUserButton = new QPushButton("Ajouter");
    updateUserButton = new QPushButton("Modifier");
    deleteUserButton = new QPushButton("Supprimer");

    qboxLayout1->addWidget(dropdownUser);

    qboxLayout2->addWidget(inputPseudo);

    qboxLayout3->addWidget(inputName);
    qboxLayout3->addWidget(inputFirstname);

    qboxLayout4->addWidget(inputMail);
    qboxLayout4->addWidget(inputAvatar);

    qboxLayout5->addWidget(inputPasswordUser);
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
