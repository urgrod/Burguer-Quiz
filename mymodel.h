#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractTableModel>
#include <QPushButton>

class MyModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MyModel(QObject *parent);
    int rowCount(const QModelIndex &pqrent = QModelIndex()) const override;
    int columnCount(const QModelIndex &pqrent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // MYMODEL_H
