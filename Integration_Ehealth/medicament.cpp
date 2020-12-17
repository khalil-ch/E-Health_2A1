#include "medicament.h"

Medicament::Medicament()
{

}


Medicament::Medicament(QString n, QString t,int q,QString f, QDate d, QString r):NOM(n),TYPE(t),QUANTITE(q),FOURNISSEUR(f),DATE_EXP(d),REFERENCE(r)
{

}
bool Medicament::ajouter()
{
    QSqlQuery query;


    query.prepare("INSERT INTO Medicament (NOM,TYPE,QUANTITE,FOURNISSEUR,DATE_EXP,REFERENCE)"
                  "VALUES (:NOM,:TYPE,:QUANTITE,:FOURNISSEUR,:DATE_EXP,:REFERENCE)");

    query.bindValue(":NOM",NOM);
    query.bindValue(":TYPE",TYPE);
    query.bindValue(":QUANTITE",QUANTITE);
    query.bindValue(":FOURNISSEUR",FOURNISSEUR);
    query.bindValue(":DATE_EXP",DATE_EXP);
    query.bindValue(":REFERENCE",REFERENCE);
    return query.exec();
}


QSqlQueryModel * Medicament::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from Medicament");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("FOURNISSEUR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_EXP"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REFERENCE"));
    return model;
}


bool Medicament::supprimer(QString NOM)
{
    QSqlQuery qry;
    qry.prepare("Delete from Medicament where NOM = :NOM");
    qry.bindValue(":NOM",NOM);
    return qry.exec();
}

QSqlQueryModel * Medicament::chercher_med(QString chaine,int valeur)
{
    QSqlQuery q;
    if (valeur==1)
    {   q.prepare("select * from MEDICAMENT where REFERENCE=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("REFERENCE").toString();
        if(ch==chaine)
                return model;
    }
    else  if (valeur==2)
    {   q.prepare("select * from MEDICAMENT where NOM=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("NOM").toString();
        if (ch==chaine)
                return model;
    }
    else  if (valeur==3)
    {   q.prepare("select * from MEDICAMENT where FOURNISSEUR=:chaine");
        q.bindValue(":chaine", chaine);
        q.exec();
        QSqlQueryModel * model = new QSqlQueryModel;
        model->setQuery(q);
        QSqlRecord rec=model->record(0);
        QString ch=rec.value("FOURNISSEUR").toString();
        if (ch==chaine)
                return model;
    }
        return nullptr;



}

void Medicament::exporter(QTableView *table)
{
    QString filters("CSV files (*.csv);;All files (.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++) {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++) {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++) {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}
