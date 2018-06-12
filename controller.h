#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QAction>
#include <model.h>

class Controller
{
public:
    Controller();

public slots:
    void slotLogin();

    //slot proposition
    void slotCreateProposition();
    void slotReadAllProposition();
    void slotReadOneProposition();
    void slotUpdateProposition();
    void slotDeleteProposition();

    //slot question
    void slotCreateQuestion();
    void slotReadAllQuestion();
    void slotReadOneQuestion();
    void slotUpdateQuestion();
    void slotDeleteQuestion();

    //slot theme
    void slotCreateTheme();
    void slotReadAllTheme();
    void slotReadOneTheme();
    void slotUpdateTheme();
    void slotDeleteTheme();

    //slot user
    void slotCreateUser();
    void slotReadAllUser();
    void slotReadOneUser();
    void slotUpdateUser();
    void slotDeleteUser();

    void setAuth(bool state);
    bool getAuth();

private:
    QString pseudo;
    bool auth;
};

#endif // CONTROLLER_H
