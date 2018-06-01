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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow();
    ~MainWindow();

//     void createMenu();
//     void createAction();
//     void contextMenuEvent(QContextMenuEvent *event) override;

     //differentes vue
     QGroupBox *createViewLogin();
     QGroupBox *createViewHome();
     QGroupBox *createViewProposition();
     QGroupBox *createViewQuestion();

private:

     QWidget *widgetGeneral;
     QWidget *topWidget;
     QGraphicsView *viewAccueil;

     QMenu *accueilMenu;
     QMenu *propositionsMenu;
     QMenu *questionsMenu;
     QMenu *userMenu;
     QMenu *quitMenu;
     QMenu *themeMenu;

     //menu question
     QAction *createQuestion;
     QAction *deleteQuestion;
     QAction *readQuestion;
     QAction *updateQuestion;
     //menu proposition
     QAction *createProposition;
     QAction *deleteProposition;
     QAction *readProposition;
     QAction *updateProposition;
     //menu theme
     QAction *createTheme;
     QAction *deleteTheme;
     QAction *readTheme;
     QAction *updateTheme;
     //menu user
     QAction *createUser;
     QAction *deleteUser;
     QAction *readUser;
     QAction *updateUser;
     //menu autres
     QAction *logout;

     //interface login
     QLineEdit *loginInput;
     QLineEdit *passwordInput;
     QLineEdit *passwordDatabaseInput;
     QPushButton *loginButton;
     QLabel *loginText;
     QLabel *passwordText;
     QLabel *passworddatabaseText;

     //interface d'accueil

     //interface proposition
     QComboBox *dropdownQuestion;
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
     QComboBox *dropdownTheme;
     QPushButton *addQuestionButton;
     QPushButton *updateQuestionButton;
     QPushButton *deleteQuestionButton;



private slots:
};

#endif // MAINWINDOW_H
