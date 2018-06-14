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
     void populateDropdownScore();
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
    QTableWidget *tableScore;

     //interface proposition
     QLineEdit *addProposition1;
     QLineEdit *idProposition;
     QPushButton *addPropositionButton;
     QPushButton *updatePropositionButton;
     QPushButton *deletePropositionButton;
     QLabel *addPropositionLabel;
     QLabel *answerPropositionLabel;
     QTableWidget *tableProposition;
     QTableWidget *tableQuestionProposition;
     QComboBox *dropdownReponse1;


     //interface question
     QTableWidget *tableQuestion;
     QTableWidget *tableThemeQuestion;
     QLabel *choiceQuestionLabel;
     QLineEdit *addQuestion1;
     QLineEdit *addQuestion2;
     QLineEdit *idQuestion;
     QLabel *textLabel1;
     QLabel *textLabel2;
     QLabel *textLabel3;
     QPushButton *addQuestionButton;
     QPushButton *updateQuestionButton;
     QPushButton *deleteQuestionButton;

     //interface theme
     QLabel *textTheme;
     QLineEdit *inputTheme;
     QLineEdit *idTheme;
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

     void slotAddTheme();
     void slotUpdateTheme();
     void slotDeleteTheme();
     void slotSelectTheme(int row, int coll);

     void slotAddQuestion();
     void slotUpdateQuestion();
     void slotDeleteQuestion();
     void slotSelectQuestion(int row, int coll);

     void slotAddProposition();
     void slotUpdateProposition();
     void slotDeleteProposition();
     void slotSelectProposition(int row, int coll);

     void slotAddUser();
     void slotUpdateUser();
     void slotDeleteUser();
     void slotSelectUser();


};

#endif // MAINWINDOW_H
