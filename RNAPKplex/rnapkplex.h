#ifndef RNAPKPLEX_H
#define RNAPKPLEX_H

#include "IAlgorithm.h"


class RNAPKplex : public IAlgorithm
{
public:
    RNAPKplex();

    QStringList getInfo() override;
    QString getStructure() override;
    QStringList getOptions() override;
    void initiate(QString filepath, QStringList opt) override;
    virtual ~RNAPKplex() {};

private:
    QStringList info;
    QStringList options;
    QString structure;

};

#endif // RNAPKPLEX_H
