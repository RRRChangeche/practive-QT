/*
 * Communicating between threads
 * https://youtu.be/h_Fx9MtcsB0
 *
*/
#include <QCoreApplication>
#include <QThread>
#include "worker.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread pThread;
    QThread cThread;

    Worker producer;
    Worker comsumer;

    pThread.setObjectName("Producer Thread");
    cThread.setObjectName("Comsumer Thread");
    producer.setObjectName("Producer");
    comsumer.setObjectName("Comsumer");

    producer.moveToThread(&pThread);
    comsumer.moveToThread(&cThread);
    producer.setProducer(true);

    QObject::connect(&pThread, &QThread::started, &producer, &Worker::start);
    QObject::connect(&cThread, &QThread::started, &comsumer, &Worker::start);

    QObject::connect(&producer, &Worker::produced, &comsumer, &Worker::consume, Qt::QueuedConnection);
    QObject::connect(&producer, &Worker::finished, &comsumer, &Worker::quit, Qt::QueuedConnection);
//    QObject::connect(&producer, &Worker::produced, &comsumer, &Worker::consume, Qt::AutoConnection);
//    QObject::connect(&producer, &Worker::finished, &comsumer, &Worker::quit, Qt::AutoConnection);

    cThread.start();
    pThread.start();

    return a.exec();
}
