#include "mainwindow.h"
#include "model.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//    QString nom = "lolo5";
//    QString login = "quizburger";
//    QString ip = "127.0.0.1";
//    Model *model = new Model();
//    model->connectToDatabase(login,ip);
//    model->requestUser(1, nom, nom,nom,nom,nom, 1, nom);
//    qDebug()<<"test"<<model->getRequestEffect();
    w.show();

    return a.exec();
}
