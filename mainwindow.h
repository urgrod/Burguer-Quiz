#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <model.h>
#include <controller.h>

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
#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>


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

     void populateDropdownTheme();
     void populateDropdownReponse();
     void populateDropdownUser();
     void populateDropdownQuestion();
     void populateDropdownProposition();

private:

     QWidget *widgetGeneral;
     Model *model;
     Controller *control;

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
//     QComboBox *dropdownProposition;
     QLineEdit *addProposition1;
     QLineEdit *addProposition2;
     QLineEdit *addProposition3;
//     QRadioButton *answerRadio1;
//     QRadioButton *answerRadio2;
//     QRadioButton *answerRadio3;
//     QRadioButton *answerRadio4;
//     QRadioButton *answerRadio5;
//     QRadioButton *answerRadio6;
//     QRadioButton *answerRadio7;
//     QRadioButton *answerRadio8;
//     QRadioButton *answerRadio9;
     QPushButton *addPropositionButton;
     QPushButton *updatePropositionButton;
     QPushButton *deletePropositionButton;
//     QPushButton *selectPropositionButton;
     QLabel *addPropositionLabel;
     QLabel *answerPropositionLabel;
     QTableWidget *tableProposition;

     QComboBox *dropdownReponse1;
     QComboBox *dropdownReponse2;
     QComboBox *dropdownReponse3;


     //interface question
     QTableWidget *tableQuestion;
     QLabel *choiceQuestionLabel;
     QLineEdit *addQuestion1;
     QLineEdit *addQuestion2;
     QLabel *textLabel1;
     QLabel *textLabel2;
     QLabel *textLabel3;
     QPushButton *addQuestionButton;
     QPushButton *updateQuestionButton;
     QPushButton *deleteQuestionButton;
//     QPushButton *selectQuestionButton;

     //interface theme
     QLabel *textTheme;
     QLineEdit *inputTheme;
     QPushButton *addThemeButton;
     QPushButton *updateThemeButton;
     QPushButton *deleteThemeButton;
     QPushButton *selectThemeButton;
     QTableWidget *tableTheme;

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
     QPushButton *selectUserButton;
     QLabel *textUser1;
     QLabel *textUser2;
     QLabel *textUser3;
     QLabel *textUser4;
     QLabel *textUser5;
     QLabel *textUser6;
     QLabel *textUser7;


     //interface logout
     QPushButton *logoutButton;
     QPushButton *quitButton;

public slots:
     void slotLogin();
     void slotLogout();

     void slotAddTheme(int row, int coll);
     void slotUpdateTheme(int row, int coll);
     void slotDeleteTheme(int row, int coll);
     void slotSelectTheme(int row, int coll);

     void slotAddQuestion(int row, int coll);
     void slotUpdateQuestion(int row, int coll);
     void slotDeleteQuestion(int row, int coll);
     void slotSelectQuestion(int row, int coll);

     void slotAddProposition(int row, int coll);
     void slotUpdateProposition(int row, int coll);
     void slotDeleteProposition(int row, int coll);
     void slotSelectProposition(int row, int coll);

     void slotAddUser();
     void slotUpdateUser();
     void slotDeleteUser();
     void slotSelectUser();


};

#endif // MAINWINDOW_H
