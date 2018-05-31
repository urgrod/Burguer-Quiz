#include "mymodel.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QTableView>
#include <QHeaderView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel myModel(0);
    tableView.setModel(&myModel);

    //    QHeaderView *vh = new QHeaderView(Qt::Horizontal);
    //    QHeaderView *hh = new QHeaderView(Qt::Vertical);
    //    vh->hide();
    //    hh->hide();
    //    tableView.setVerticalHeader(vh);
    //    tableView.setHorizontalHeader(hh);


    tableView.show();
    return a.exec();
}
