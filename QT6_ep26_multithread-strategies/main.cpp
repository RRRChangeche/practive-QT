
#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QThreadPool>
#include <QTimer>
#include <QtConcurrent>
#include "worker.h"

void testMain(){
    qInfo() << "Testing on main";

    Worker* worker = new Worker();
    worker->run();
    worker->deleteLater();
    qInfo() << "Testing ...";

}

void testThread(){
    // The reason we create a pointer for thread is, if we store the thread in the stack memory
    // the thread will be killed when it is out of scope.
    QThread* thread = new QThread();
    thread->setObjectName("Worker Thread");
    qInfo() << "Testing on Worker Thread";
    Worker* worker = new Worker();

    worker->moveToThread(thread);
    // Don't make custom thread class for threading, use moveToThread()

    QObject::connect(thread, &QThread::started, worker, &Worker::run);
    QObject::connect(worker, &Worker::finished, worker, &Worker::deleteLater);
    QObject::connect(worker, &Worker::finished, thread, &QThread::quit);
    QObject::connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();

    qInfo() << "Testing ...";

}

void testPool(){
    qInfo() << "Testing on Thread Pool";
    Worker* worker = new Worker();
    worker->setAutoDelete(true);
    QThreadPool::globalInstance()->start(worker);

    qInfo() << "Testing ...";
}

void testConcurrent(){
    // QtConcurrent is high level api.
    // this function will run worker in the threadpool using QtConcurrent to run
    // and delete worker pointer automatically using QScopedPointer
    qInfo() << "Testing on Concurrent";
    QScopedPointer<Worker> worker(new Worker);
    worker->run();

    qInfo() << "Testing ...";
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

//    testMain();
//    testThread();
//    testPool();
    QtConcurrent::run(&testConcurrent);

    qInfo() << "Finished in " << QThread::currentThread();

    return a.exec();
}
