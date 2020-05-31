#include "PluginHandler.h"
#include <QDir>
#include <QString>
#include <QJsonDocument>

PluginHandler::PluginHandler(){}

//Give plugin handler the path (or just name) of the executable.
//It should look in the default location : lib/path
PluginHandler::PluginHandler(QString path){
    setDir(path);
}

void PluginHandler::setDir(QString _path){
    this->path = &_path;
    QString lib = "..\\lib\\";
    QString defPath = lib + path;
    directory = new QDir(*path);

    if(!directory->exists()){
        //We haven't been passed a complete path
        //Attempt to find it
        directory = new QDir(defPath);
    }else if(!directory->exists()){
        qWarning("Cannot find directory");
        EXIT_FAILURE;
    }
}

void PluginHandler::findJson(){
    QString fileName = *path + ".json";
    QStringList filters;
    filters << fileName;
    directory->setNameFilters(filters);

    QStringList file;
    if((file = directory->entryList(filters)).isEmpty()){
        qWarning("Cannot find plugin");
    }
    doc = new QJsonDocument(QJsonDocument::fromJson(file.first().toLocal8Bit()));
}

void PluginHandler::buildPlugin(){
    plugin = new BasePlugin(doc->object());
}

//bool checkJson(QString exe, QJsonObject file){
//    return true;
//}
PluginHandler::~PluginHandler(){}


//Initialize plugin list from available files
//Instead of being asked for each one by main.
//void PluginHandler::initPluginList(){
//    //Only .json files will be checked.
//    QStringList filters;
//    filters << "*.json";
//    directory->setNameFilters(filters);

//    //This is a container of all .json files in the directory
//    files = new QFileInfoList(directory->entryInfoList());
//    if(files->isEmpty()){
//        qWarning("No plugins found");
//    }
//}

