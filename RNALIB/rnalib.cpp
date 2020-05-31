
#include "rnalib.h"

RNALIB::RNALIB()
{

}

void RNALIB::stringToFasta (QString str, QString path = QDir::currentPath(), QString name = "temp"){

    QString filename = path + "//" + name + ".fasta";
    std::ofstream fOut;
    fOut.open(filename.toStdString(), std::ofstream::out);

    //FASTA must begin with > and then the sequence name
    fOut << ">" << name.toStdString() << std::endl;

    fOut << str.toStdString() << std::endl;

    fOut.close();

    std::cout << "File created Complete";

}
