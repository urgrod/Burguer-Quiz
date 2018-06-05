#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGroupBox>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QContextMenuEvent>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QList>
#include <QComboBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QTabWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
    ~MainWindow();

     //differentes vue
     QLayout *createViewLogin();
     QLayout *createViewHome();
     QLayout *createViewProposition();
     QLayout *createViewQuestion();
     QLayout *createViewTheme();
     QLayout *createViewUser();
     QLayout *createViewLogout();

private:

     QWidget *widgetGeneral;

     //menu
     QTabWidget *onglets;
     QWidget *pageAccueil;
     QWidget *pageTheme;
     QWidget *pageQuestions;
     QWidget *pagePropositions;
     QWidget *pageUser;
     QWidget *pageLogout;



     //interface login
     QLineEdit *loginInput;
     QLineEdit *passwordInput;
     QLineEdit *ipDatabaseInput;
     QLineEdit *passwordDatabaseInput;
     QPushButton *loginButton;
     QLabel *loginText;
     QLabel *passwordText;
     QLabel *passworddatabaseText;
     QLabel *ipDatabaseText;


     //interface d'accueil

     //interface proposition
     QComboBox *dropdownQuestion;
     QComboBox *dropdownThemeProposition;
     QSpinBox *dropdownNbProposition;
     QLineEdit *addProposition1;
     QLineEdit *addProposition2;
     QLineEdit *addProposition3;
     QRadioButton *answerRadio1;
     QRadioButton *answerRadio2;
     QRadioButton *answerRadio3;
     QRadioButton *answerRadio4;
     QRadioButton *answerRadio5;
     QRadioButton *answerRadio6;
     QRadioButton *answerRadio7;
     QRadioButton *answerRadio8;
     QRadioButton *answerRadio9;
     QPushButton *addPropositionButton;
     QPushButton *updatePropositionButton;
     QPushButton *deletePropositionButton;
     QLabel *addPropositionLabel;
     QLabel *answerPropositionLabel;

     //interface question
     QLabel *choiceQuestionLabel;
     QLineEdit *addQuestion1;
     QLineEdit *addQuestion2;
     QLabel *textLabel1;
     QLabel *textLabel2;
     QLabel *textLabel3;
     QPushButton *addQuestionButton;
     QPushButton *updateQuestionButton;
     QPushButton *deleteQuestionButton;

     //interface theme
     QLabel *textTheme;
     QLineEdit *inputTheme;
     QComboBox *dropdownTheme;
     QPushButton *addThemeButton;
     QPushButton *updateThemeButton;
     QPushButton *deleteThemeButton;

     //interface user
     QComboBox *dropdownUser;
     QLineEdit *inputPseudo;
     QLineEdit *inputName;
     QLineEdit *inputFirstname;
     QLineEdit *inputMail;
     QLineEdit *inputAvatar;
     QLineEdit *inputPasswordUser;
     QLineEdit *inputPasswordVerifUser;
     QLabel *textUser;
     QRadioButton *adminYesRadio;
     QRadioButton *adminNoRadio;
     QPushButton *addUserButton;
     QPushButton *updateUserButton;
     QPushButton *deleteUserButton;

     //interface logout
     QPushButton *logoutButton;
     QPushButton *quitButton;

public slots:

};

#endif // MAINWINDOW_H
