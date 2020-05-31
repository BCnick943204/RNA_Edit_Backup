#include "BasePlugin.h"
#include <QObject>
#include <QProcess>
#include <QString>
#include <QJsonArray>
#include <QVariant>

#ifdef Q_OS_WINDOWS
#define MYEXPORT __declspec(dllexport)
#else
#define MYEXPORT
#endif

Q_PLUGIN_METADATA(IAlgorithm_IID FILE BasePlugin.json)
Q_INTERFACES(IAlgorithm)

BasePlugin::BasePlugin(){
    //placeholder, generalization needed
   // initiate("RNAfold.exe", {"--noPS"});
}

BasePlugin::BasePlugin(QJsonObject ini){
    QString str = "options";

    //ini is the entirety of the .json file for this plugin
    //It can be converted into a QVariantMap
    // pluginMap = new QVariantMap(ini.toVariantMap());
    //Supposedly a QVariantMap is "Synonym for QMap<QString, QVariant>."
    //Whatever that means...
     //from pluginMap, which is declared as QMap<QString,QVariant>, we should be able to extract values by using
     //pluginMap->value()/pluginMap->key() to return the QVariant/QString
     //this however, returns a const object. which we can't assign to anything
     //instead we have to do this
     QVariant var;
    // var = pluginMap->value("options");
     //This now contains:
     /*[{
      *          "command": "--noconv",
      *          "pass": {
      *                  "Do you want non-standard nucleotides to be converted?": 0.0
      *          },
      *  ...
      *  ...
      *  }]
      */
     //or similar. Why does QT keep changing the margins on these comments? you notice that?
     //var is an array of QObjects at this point, or it should be. Now each position in the array contains a QVariant (probably), which is hopefully
     //a map.
     QMap<QString,double> testmap;
     //WE can't put anything in here yet though.
     //Accessing this data is stupid and requires placing the "pass" value into another QVariant
     //We run into an issue where we must use QVariant, but since QVariant isn't recognized as an array by the compiler (even though it would be at runtime)
     //and therefore must find another way to sequentially access the data.
     //we can probably do this like
     QJsonArray arr = var.toJsonArray();
     //but arr still doesn't know what's inside it because... well it has no way of knowing.
     //Therefore
     //arr[0].value("pass");
     //is incomprehensible to the compiler.
     //Options:
     //Follow this rabbit hole all the way to the end. Maybe using <T> to calm the frayed nerves of the compiler.
     //2 Arrays inside the json, 1 for the command which we have to keep track of, and 1 for the String,double pair
     //We can maybe iterate through QVariant? QVariant::value<type> can be accessed this way. This was what I was doing when I 'lost' the previous file.
     //There are methods QVariant::canConvert(), and many options for converting QVariants into specific types so we can do things with them. Brute force-y.

}

QString BasePlugin::initiate(QString filepath, QMap<QString, double> opt){
    //file_path = filepath;
   // proc = new QProcess(this);

    return "Value";
}

QString BasePlugin::getStructure(){
    return structure;
}
QStringList BasePlugin::getInfo(){
    return info;
}
QMap<QString, double> BasePlugin::getOptions(){
    QMap<QString,double> map;
    return map;
}

BasePlugin::~BasePlugin(){

}

extern "C" MYEXPORT IAlgorithm* create_rFoldPlugin() {
    return new BasePlugin();
}
