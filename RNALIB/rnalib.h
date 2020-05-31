#ifndef RNALIB_H
#define RNALIB_H

#include "RNALIB_global.h"
#include <QString>
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <QDir>


class RNALIB_EXPORT RNALIB
{
    public:
        RNALIB();

        static void stringToFasta(QString, QString, QString);
};

#endif // RNALIB_H
