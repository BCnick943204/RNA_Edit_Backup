#ifndef BASEPLUGIN_H
#define BASEPLUGIN_H

#include "IAlgorithm.h"
#include <QProcess>
#include <QMap>

class BasePlugin : public IAlgorithm
{
public:
    BasePlugin();
    BasePlugin(QJsonObject);
    ~BasePlugin();
    QStringList getInfo() override;
    QString getStructure() override;
    QMap<QString, double> getOptions() override;
    QString initiate(QString filepath, QMap<QString, double> opt) override;

    //QProcess* proc;

private:
    QStringList info;
    QMap<QString, QVariant>* map;
    QString algName;
    QString algDesc;
    QVariantList* algOptions;
    QString structure;

};

#endif // BASEPLUGIN_H
