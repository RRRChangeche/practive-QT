/*
 * https://www.youtube.com/watch?v=KugPAznC4Yo&list=PLUbFnGajtZlXbrbdlraCe3LMC_YH5abao&index=6
*/
#include <QCoreApplication>

#include "test.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test test;

    // Connect signal and slot
//    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit);    // connect(sender, signal, reciever, slot)
    QObject::connect(&test, &Test::close, &a, &QCoreApplication::quit, Qt::QueuedConnection);    // connect(sender, signal, reciever, slot, ConnectionType)

    test.do_stuff();
    int value = a.exec();
    qInfo() << "Exit value:" << value;

//    return a.exec();
    return value;
}
