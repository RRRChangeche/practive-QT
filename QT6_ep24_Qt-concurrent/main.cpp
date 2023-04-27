/*
 * Qt Concurrent
 * https://doc.qt.io/qt-6/qtconcurrent-index.html
 *
*/
#include <QCoreApplication>
#include <QDebug>
#include <QRandomGenerator>
#include <QThread>
#include <QFuture>
#include <QtConcurrent>

void test(){
    qInfo() << "Test " << QThread::currentThread();
}

int testRandom(int max){
    qInfo() << "Random " << QThread::currentThread();
    QThread::currentThread()->msleep(1000);

    return QRandomGenerator::global()->bounded(max);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");
    qInfo() << "Starting " << QThread::currentThread();

    // To do - thread
    // Synchronizing these 2 threads using waitForFinished()
//    test();
    QFuture<void> f1 = QtConcurrent::run(test); // QFurtre is a template class, and run() returns nothing
    f1.waitForFinished();   // future wait for thread (run inside thread pool) to finished

    QFuture<int> f2 = QtConcurrent::run(testRandom, 100); // QFurtre is a template class, and run() returns nothing
//    f2.waitForFinished();   // future wait for thread (run inside thread pool) to finished
    qInfo() << "Random: " << f2.result();     // Returns the first result in the future

    qInfo() << "Finished " << QThread::currentThread();

    return a.exec();
}
