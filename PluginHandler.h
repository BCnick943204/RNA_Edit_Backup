#ifndef PLUGINHANDLER_H
#define PLUGINHANDLER_H

#include <QString>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QJsonDocument>
#include "BasePlugin.h"

class PluginHandler{

public:
    PluginHandler();
    PluginHandler(QString);

    void setDir(QString);

    ~PluginHandler();

    void findJson();
    void buildPlugin();
//    bool checkJson(QString,QJsonObject);

    QString* path;

private:
    QDir* directory;
    QFileInfoList* files;
    IAlgorithm* plugin;
    QJsonDocument* doc;

    //void initPluginList();

};

#endif // PLUGINHANDLER_H
