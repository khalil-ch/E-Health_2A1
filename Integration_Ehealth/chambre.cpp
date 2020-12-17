#include "chambre.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
// test
chambre::chambre()
{
    this->id="";
    this->etage=0;
    this->numero_chambre=0;
    this->type="";
}
chambre::chambre(QString id ,int etage,int numero_chambre,QString type )
{

    this->id=id;
    this->etage=etage;
    this->numero_chambre=numero_chambre;
    this->type=type;
}
bool chambre::ajouter()
{
QSqlQuery query;
query.prepare("Insert into chambre (id,etage,numero_chambre,type)"
              " Values(:id,:etage,:numero_chambre,:type)");

query.bindValue(":id",id);
query.bindValue(":etage",etage);
query.bindValue(":numero_chambre",numero_chambre);
query.bindValue(":type",type);

 return query.exec();
}
QSqlQueryModel * chambre::afficher()
{
   QSqlQueryModel * model =new QSqlQueryModel();
   model->setQuery("select * from chambre");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("id")); 
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("etage"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero_chambre"));


return model;
}
bool chambre::supprimer(QString id)
{

    QSqlQuery query;

    query.prepare("delete from chambre where id = :id");
    query.bindValue(":id",id);
    return query.exec();

}
bool chambre::update(QString id ,int etage ,int numero_chambre,QString type)
{
    QSqlQuery query;
    query.prepare("UPDATE chambre SET id= :id,etage=:etage,numero_chambre=:numero_chambre,type= :type WHERE id = :id");


    query.bindValue(":id",id);
    query.bindValue(":etage",etage);
    query.bindValue(":numero_chambre",numero_chambre);
    query.bindValue(":type",type);

    return    query.exec();
}
QSqlQueryModel * chambre::rechercher_chambre(QString id,int numero_chambre,int etage)
{
    QSqlQuery *query=new QSqlQuery();
    query->prepare("select * from chambre where id=:id or numero_chambre=:numero_chambre or etage=:etage");
    query->bindValue(":id",id);
    query->bindValue(":numero_chambre",numero_chambre);
    query->bindValue(":etage",etage);

    query->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*query);
    return model;
}
QSqlQueryModel *chambre::trier(QString crit)
{
    QSqlQuery *query=new QSqlQuery();
    QSqlQueryModel *model=new QSqlQueryModel();
    query->prepare("select * from chambre order by "+crit+"");
    query->exec();
    model->setQuery(*query);
    return model;
}

void chambre::exporter(QTableView *table)
{
    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                        filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++)
        {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
         }
         data << strList.join(";") << "\n";
         for (int i = 0; i < model->rowCount(); i++)
         {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++)
            {

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



