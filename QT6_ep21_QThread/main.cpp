/*
 * Threaded Example
 *
 * 1. Create a QThread
 * 2. Move a class to it
 * 3. Can not have a parent!
 *
 * The object which move into a thread cannot have a parent!
*/
#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    qInfo() << "Starting" << QThread::currentThread();

//    Worker work;    // no issues
//    work.run();

    Worker* work = new Worker(); // No parent!!
    QThread thread;
    thread.setObjectName("Worker Thread");
    work->moveToThread(&thread);    // worker doesn't start
    QObject::connect(&thread, &QThread::started, work, &Worker::run);

    thread.start();

    qInfo() << "Doing stuff" << QThread::currentThread();
    for (int i = 0; i < 10; i++){
        qInfo() << "Working" << QString::number(i) << QThread::currentThread();
        QThread::currentThread()->msleep(500);
    }

    qInfo() << "Finished" << QThread::currentThread();

    return a.exec();
}
