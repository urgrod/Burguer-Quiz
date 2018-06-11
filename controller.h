#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QString>
#include <QAction>

class controller
{
public:
    controller();

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

private:
    QString pseudo;
    bool auth;
};

#endif // CONTROLLER_H
