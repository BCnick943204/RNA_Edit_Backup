#include "parsexml.h"

QString* ParseXML::getPath(QString fileName, int i) {
    //The QDomDocument class represents an XML document.
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        QString *error = new QString();
        QString message = "Error while loading file.";
        error[0] = message;
        return error;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();

    QDomElement root = xmlBOM.documentElement();
    QDomElement program = root.firstChild().toElement();

    int j = 0;

    //This find the proper program in the list.
    while(!program.isNull()) {
        if(program.tagName()=="Program" && j == i) {
            QString* path = new QString();
            path[0] = program.text();
            return path;
        }
        program = program.nextSiblingElement();
        j++;
    }

    QString* error = new QString("Element not found");
    return error;
}

