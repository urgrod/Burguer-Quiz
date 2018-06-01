#include "mainwindow.h"

MainWindow::MainWindow() : QMainWindow()
{
    this->setWindowTitle("Burger Quiz - Administration");

    widgetGeneral = new QWidget;
    QHBoxLayout *qblGeneral = new QHBoxLayout;

//    createMenu();

    widgetGeneral->setLayout(qblGeneral);
    this->setCentralWidget(widgetGeneral);

//    viewLogin = new QGraphicsView;

//    qblGeneral->addWidget(createViewLogin());
//    qblGeneral->addWidget(createViewHome());
//    qblGeneral->addWidget(createViewProposition());
    qblGeneral->addWidget(createViewQuestion());



}

MainWindow::~MainWindow()
{
}

//void MainWindow::createMenu()
//{
//    accueilMenu = menuBar()->addMenu(tr("&Accueil"));
//    propositionsMenu = menuBar()->addMenu(tr("&Propositions"));
//    questionsMenu = menuBar()->addMenu(tr("&Questions"));
//    themeMenu = menuBar()->addMenu(tr("&Theme"));
//    userMenu = menuBar()->addMenu(tr("&Utilisateur"));
//    quitMenu = menuBar()->addMenu(tr("&Quitter"));

//    //ajout des actions aux menus
//    //menu propositions
//    propositionsMenu->addAction(readProposition);
//    propositionsMenu->addAction(createProposition);
//    propositionsMenu->addAction(updateProposition);
//    propositionsMenu->addAction(deleteProposition);

//    //menu questions
//    questionsMenu->addAction(readQuestion);
//    questionsMenu->addAction(createQuestion);
//    questionsMenu->addAction(updateQuestion);
//    questionsMenu->addAction(deleteQuestion);

//    //menu user
//    userMenu->addAction(readUser);
//    userMenu->addAction(createUser);
//    userMenu->addAction(updateUser);
//    userMenu->addAction(deleteUser);

//    //menu theme
//    themeMenu->addAction(readTheme);
//    themeMenu->addAction(createTheme);
//    themeMenu->addAction(updateTheme);
//    themeMenu->addAction(deleteTheme);

//    //menu autre
//    quitMenu->addAction(logout);
//}

//void MainWindow::createAction()
//{
//}



//void MainWindow::contextMenuEvent(QContextMenuEvent *event)
//{
//    QMenu menu(this);
//    menu.addAction(readQuestion);
//    menu.exec(event->globalPos());
//}


QGroupBox *MainWindow::createViewLogin()
{
    QGroupBox *qgrouBox = new QGroupBox;

    QHBoxLayout *qboxLayout = new QHBoxLayout;

    loginInput = new QLineEdit;
    passwordInput = new QLineEdit;
    passwordDatabaseInput = new QLineEdit;
    loginButton = new QPushButton("Se connecter");

    loginText = new QLabel("Login:");
    passwordText = new QLabel("Mot de passe:");
    passworddatabaseText = new QLabel("Mot de passe de la BDD:");

    qboxLayout->addWidget(loginText);
    qboxLayout->addWidget(loginInput);
    qboxLayout->addWidget(passwordText);
    qboxLayout->addWidget(passwordInput);
    qboxLayout->addWidget(passworddatabaseText);
    qboxLayout->addWidget(passwordDatabaseInput);
    qboxLayout->addWidget(loginButton);

    qgrouBox->setLayout(qboxLayout);

    return qgrouBox;
}

QGroupBox *MainWindow::createViewHome()
{
//    QGroupBox *qgrouBox = new QGroupBox;

//    QHBoxLayout *qboxLayout = new QHBoxLayout;

//    tableau = new QList

//    qboxLayout->addWidget(loginButton);

//    qgrouBox->setLayout(qboxLayout);

//    return qgrouBox;

}

QGroupBox *MainWindow::createViewProposition()
{

    QGroupBox *qgroupBox = new QGroupBox;

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;
    QHBoxLayout *qboxLayout6 = new QHBoxLayout;
    QHBoxLayout *qboxLayout7 = new QHBoxLayout;
    QHBoxLayout *qboxLayout8 = new QHBoxLayout;


    QVBoxLayout *qboxLayout5 = new QVBoxLayout;


    dropdownQuestion = new QComboBox;
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
    addPropositionButton = new QPushButton("Ajouter les propositions");
    updatePropositionButton = new QPushButton("Modifier les propositions");
    deletePropositionButton = new QPushButton("Supprimer les propositions");


    qboxLayout1->addWidget(addPropositionLabel);
    qboxLayout1->addWidget(dropdownQuestion);

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

    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout8);
    qboxLayout5->addLayout(qboxLayout4);
    qboxLayout5->addLayout(qboxLayout6);
    qboxLayout5->addLayout(qboxLayout7);
    qboxLayout5->addLayout(qboxLayout3);


    qgroupBox->setLayout(qboxLayout5);

    return qgroupBox;

}

QGroupBox *MainWindow::createViewQuestion()
{
    QGroupBox *qgroupBox = new QGroupBox;

    QHBoxLayout *qboxLayout1 = new QHBoxLayout;
    QHBoxLayout *qboxLayout2 = new QHBoxLayout;
    QHBoxLayout *qboxLayout3 = new QHBoxLayout;
    QHBoxLayout *qboxLayout4 = new QHBoxLayout;

    QVBoxLayout *qboxLayout5 = new QVBoxLayout;

    dropdownQuestion = new QComboBox;
    addQuestion1 = new QLineEdit;
    textLabel1 = new QLabel(",");
    addQuestion2 = new QLineEdit;
    textLabel2 = new QLabel("ou les deux?");
    textLabel3 =new QLabel("Choisir un theme:");
    dropdownTheme = new QComboBox;
    addQuestionButton = new QPushButton("Ajouter la question");
    updateQuestionButton = new QPushButton("Modifier la question");
    deleteQuestionButton = new QPushButton("Supprimer la question");

    qboxLayout1->addWidget(dropdownQuestion);

    qboxLayout2->addWidget(addQuestion1);
    qboxLayout2->addWidget(textLabel1);
    qboxLayout2->addWidget(addQuestion2);
    qboxLayout2->addWidget(textLabel2);

    qboxLayout3->addWidget(textLabel3);
    qboxLayout3->addWidget(dropdownTheme);

    qboxLayout4->addWidget(addQuestionButton);
    qboxLayout4->addWidget(updateQuestionButton);
    qboxLayout4->addWidget(deleteQuestionButton);

    qboxLayout5->addLayout(qboxLayout1);
    qboxLayout5->addLayout(qboxLayout2);
    qboxLayout5->addLayout(qboxLayout3);
    qboxLayout5->addLayout(qboxLayout4);

    qgroupBox->setLayout(qboxLayout5);

    return qgroupBox;

}
