/*
 * Qt sharing resources between threads
 * - using QMutex
 * - using QMutexLocker
*/
#include <QCoreApplication>
#include <QThread>
#include <QThreadPool>
#include <QMutex>
#include <QDebug>
#include "worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int count = 0;  // Shared resource
    int max = 5000;    // Number of threads

    QMutex mutex;

    for (int i = 0; i < max; i++){
        Worker *worker = new Worker();  // Qt has built-in memory managment
        worker->setCount(&count);
        worker->setMutex(&mutex);
        worker->setAutoDelete(true);    // it will be deleted when we no longer needs it.

        QThreadPool::globalInstance()->start(worker);
    }

    QThreadPool::globalInstance()->waitForDone();   // wait for everything done in threadpool
    qInfo() << "Count: " << count;


    return a.exec();
}
