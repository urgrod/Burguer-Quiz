#include "mymodel.h"

MyModel::MyModel(QObject *parent)
    :QAbstractTableModel(parent)
{

}

int MyModel::rowCount(const QModelIndex & /*parent*/)const
{
    return 8;
}

int MyModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 10;
}

//interface accueil
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 0 && col == 0){
//                return QString("Bouton accueil");
//            }
//            if(row == 1 && col == 0){
//                return QString("Bouton questions");
//            }
//            if(row == 2 && col == 0){
//                return QString("Bouton Propositon");
//            }
//            if(row == 3 && col == 0){
//                return QString("Bouton Utilisateur");
//            }
//            if(row == 4 && col == 0){
//                return QString("Bouton Theme");
//            }
//            if(row == 5 && col == 0){
//                return QString("Bouton Quitter");
//            }
//        break;




//    }
//    return QVariant();
//}

//interface login
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 5 && col == 1){
//                return QString("Champ login");
//            }
//            if(row == 5 && col == 3){
//                return QString("Champ Password");
//            }
//            if(row == 5 && col == 5){
//                return QString("Champ Password BDD");
//            }
//            if(row == 5 && col == 7){
//                return QString("Bouton Se connecter");
//            }
//        break;
//    }
//    return QVariant();
//}

////interface questions
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 0 && col == 0){
//                return QString("Bouton accueil");
//            }
//            if(row == 1 && col == 0){
//                return QString("Bouton questions");
//            }
//            if(row == 2 && col == 0){
//                return QString("Bouton Propositon");
//            }
//            if(row == 3 && col == 0){
//                return QString("Bouton Utilisateur");
//            }
//            if(row == 4 && col == 0){
//                return QString("Bouton Theme");
//            }
//            if(row == 5 && col == 0){
//                return QString("Bouton Quitter");
//            }
//            if(row == 1 && col == 1){
//                return QString("Ajouter une question");
//            }
//            if(row == 1 && col == 3){
//                return QString("champ Question 1");
//            }
//            if(row == 1 && col == 5){
//                return QString("OU");
//            }
//            if(row == 1 && col == 7){
//                return QString("champ Question 2");
//            }
//            if(row == 2 && col == 7){
//                return QString("Bouton Ajouter la question");
//            }
//            if(row == 4 && col == 1){
//                return QString("Modifier la question");
//            }
//            if(row == 4 && col == 3){
//                return QString("Dropdown avec les questions");
//            }
//            if(row == 5 && col == 3){
//                return QString("champ question 1");
//            }
//            if(row == 5 && col == 5){
//                return QString("OU");
//            }
//            if(row == 5 && col == 7){
//                return QString("champ question 2");
//            }
//            if(row == 6 && col == 7){
//                return QString("Bouton modifier la question");
//            }
//        break;
//    }
//}

//interface proposition
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 0 && col == 0){
//                return QString("Bouton accueil");
//            }
//            if(row == 1 && col == 0){
//                return QString("Bouton questions");
//            }
//            if(row == 2 && col == 0){
//                return QString("Bouton Propositon");
//            }
//            if(row == 3 && col == 0){
//                return QString("Bouton Utilisateur");
//            }
//            if(row == 4 && col == 0){
//                return QString("Bouton Theme");
//            }
//            if(row == 5 && col == 0){
//                return QString("Bouton Quitter");
//            }
//            if(row == 1 && col == 1){
//                return QString("Ajouter des proposition");
//            }
//            if(row == 1 && col == 3){
//                return QString("Dropdown avec les questions");
//            }
//            if(row == 2 && col == 3){
//                return QString("champ proposition 1");
//            }
//            if(row == 2 && col == 5){
//                return QString("champ proposition 2");
//            }
//            if(row == 3 && col == 3){
//                return QString("champ proposition 3");
//            }
//            if(row == 3 && col == 5){
//                return QString("bouton d'ajout");
//            }


//            if(row == 4 && col == 1){
//                return QString("Modifier les propositions");
//            }
//            if(row == 4 && col == 3){
//                return QString("Dropdown avec les questions");
//            }
//            if(row == 5 && col == 3){
//                return QString("champ proposition 1");
//            }
//            if(row == 5 && col == 5){
//                return QString("champ proposition 2");
//            }
//            if(row == 6 && col == 3){
//                return QString("champ proposition 3");
//            }
//            if(row == 6 && col == 5){
//                return QString("bouton d'ajout");
//            }
//        break;
//    }
//}

//ajout de theme
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 0 && col == 0){
//                return QString("Bouton accueil");
//            }
//            if(row == 1 && col == 0){
//                return QString("Bouton questions");
//            }
//            if(row == 2 && col == 0){
//                return QString("Bouton Propositon");
//            }
//            if(row == 3 && col == 0){
//                return QString("Bouton Utilisateur");
//            }
//            if(row == 4 && col == 0){
//                return QString("Bouton Theme");
//            }
//            if(row == 5 && col == 0){
//                return QString("Bouton Quitter");
//            }


//            if(row == 1 && col == 1){
//                return QString("Ajouter un theme");
//            }
//            if(row == 1 && col == 3){
//                return QString("champ avec le theme");
//            }
//            if(row == 2 && col == 3){
//                return QString("bouton d'ajout");
//            }


//            if(row == 4 && col == 1){
//                return QString("Modifier un theme");
//            }
//            if(row == 4 && col == 3){
//                return QString("Dropdown avec les theme");
//            }
//            if(row == 5 && col == 3){
//                return QString("champ theme a modifier");
//            }
//            if(row == 5 && col == 5){
//                return QString("bouton modifier");
//            }
//            if(row == 5 && col == 7){
//                return QString("bouton supprimer");
//            }
//        break;
//    }
//}

//ajout d'un user
//QVariant MyModel::data(const QModelIndex &index, int role) const
//{
//    int row = index.row();
//    int col = index.column();

//    switch(role){
//        case Qt::DisplayRole:
//            if(row == 0 && col == 0){
//                return QString("Bouton accueil");
//            }
//            if(row == 1 && col == 0){
//                return QString("Bouton questions");
//            }
//            if(row == 2 && col == 0){
//                return QString("Bouton Propositon");
//            }
//            if(row == 3 && col == 0){
//                return QString("Bouton Utilisateur");
//            }
//            if(row == 4 && col == 0){
//                return QString("Bouton Theme");
//            }
//            if(row == 5 && col == 0){
//                return QString("Bouton Quitter");
//            }


//            if(row == 1 && col == 1){
//                return QString("Ajouter un utilisateur");
//            }
//            if(row == 1 && col == 3){
//                return QString("champ pseudo");
//            }
//            if(row == 2 && col == 3){
//                return QString("champ password");
//            }
//            if(row == 2 && col == 5){
//                return QString("champ password verif");
//            }
//            if(row == 3 && col == 3){
//                return QString("champ mail");
//            }
//            if(row == 4 && col == 3){
//                return QString("champ nom");
//            }
//            if(row == 4 && col == 5){
//                return QString("champ prenom");
//            }
//            if(row == 5 && col == 3){
//                return QString("champ lien avatar");
//            }
//            if(row == 6 && col == 3){
//                return QString("Droit d'admin");
//            }
//            if(row == 6 && col == 5){
//                return QString("checkbos oui");
//            }
//            if(row == 6 && col == 7){
//                return QString("checkbos non");
//            }
//            if(row == 7 && col == 7){
//                return QString("ajouter l'utilisateur");
//            }

//        break;
//    }
//}

//interface d'accueil
QVariant MyModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch(role){
        case Qt::DisplayRole:
            if(row == 0 && col == 0){
                return QString("Bouton accueil");
            }
            if(row == 1 && col == 0){
                return QString("Bouton questions");
            }
            if(row == 2 && col == 0){
                return QString("Bouton Propositon");
            }
            if(row == 3 && col == 0){
                return QString("Bouton Utilisateur");
            }
            if(row == 4 && col == 0){
                return QString("Bouton Theme");
            }
            if(row == 5 && col == 0){
                return QString("Bouton Quitter");
            }


            if(row == 1 && col == 3){
                return QString("Pseudo");
            }
            if(row == 1 && col == 4){
                return QString("Miam");
            }
            if(row == 1 && col == 5){
                return QString("Temps");
            }
            if(row == 1 && col == 6){
                return QString("Score");
            }





        break;
    }
}
