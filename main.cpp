#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model *model = new Model();
    QString ip = "127.0.0.1";
    QString password = "quizburger";
    QString pseudo = "admin";
    bool reponse = model->authentificationUser(pseudo, password, password,ip);
    MainWindow w;
    w.show();

    return a.exec();
}
