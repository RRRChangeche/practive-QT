/*
 * Determine the OS
 * https://doc.qt.io/qt-6/qsysinfo.html#details
 * https://doc.qt.io/qt-6/qtsystemdetection.html#Q_OS_WIN
*/
#include <QCoreApplication>
#include <QDebug>
#include <QSysInfo>

void compileTime(){
#ifdef Q_OS_LINUX
    qDebug() << "This is Linux";
#endif

#ifdef Q_OS_WIN
    qDebug() << "This is Windows";
#endif

#ifdef Q_OS_WIN32
    qDebug() << "This is Windows 32 bit";
#endif

#ifdef Q_OS_WIN64
    qDebug() << "This is Windows 64 bit";
#endif

}

void runTime(){
    QSysInfo info;
    qInfo() << "prettyProductName" << info.prettyProductName();
    qInfo() << "productType" << info.productType();
    qInfo() << "productVersion" << info.productVersion();
    qInfo() << "machineHostName" << info.machineHostName();
    qInfo() << "machineUniqueId" << info.machineUniqueId();
    qInfo() << "currentCpuArchitecture" << info.currentCpuArchitecture();
    qInfo() << "buildCpuArchitecture" << info.buildCpuArchitecture();
    qInfo() << "buildAbi" << info.buildAbi();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    compileTime();
    runTime();

    return a.exec();
}
