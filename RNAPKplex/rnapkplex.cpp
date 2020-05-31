#include "rnapkplex.h"
#ifdef Q_OS_WIN
#define MYEXPORT __declspec(dllexport)
#else
#define MYEXPORT
#endif

RNAPKplex::RNAPKplex()
{
    //Creates the options.
    options.append("No lonely pairs");
    options.append("No GU pairs");
    options.append("No closing GU pairs");
    options.append("Enter temp (default 37C): ");
    options.append("Enter energy cutoff (default -8.10): ");
}

QStringList RNAPKplex::getOptions() {
    return options;
}

QStringList RNAPKplex::getInfo() {
    return info;
}

QString RNAPKplex::getStructure() {
    return structure;
}

void RNAPKplex::initiate(QString filepath, QStringList opt) {

}

extern "C" MYEXPORT IAlgorithm* create_RNAPKplex() {
    return new RNAPKplex();
}
