/*
 * Qt memory managment
 * QScopePointer
 * QSharedPointer
 * https://youtu.be/GTOTyH0W-cc
 *
 * QT Smart pointers
 * https://www.qt.io/blog/2009/08/25/count-with-me-how-many-smart-pointer-classes-does-qt-have
 *
 * 1. test QScopedPointer, pointers will be deleted when it is out of scope
 * 2. tes QSharedPointer, pointers will be deleted when no pointers point to the object
 *
 *      main
 *        |
 *      testShared   --- work
 *        |          |
 *      step ----------- work
 *        |          |
 *      finish       --- work
 *
 *
 *
*/
#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void testScope(){
    QScopedPointer<Test> ptr(new Test());
    ptr->message("Hello");
}

void finish(QSharedPointer<Test> ptr){
    ptr->message("Finished");
}

void work(QSharedPointer<Test> ptr){
    ptr->message("Working");
}

void step(QSharedPointer<Test> ptr){
    ptr->message("Stepping");
    for (int i = 0; i < 3; i++){
        work(ptr);
    }
    finish(ptr);
}

void testShared(Test* test){
    QSharedPointer<Test> ptr(test);
    ptr->message("Starting");
    step(ptr);
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

//    testScope();
    testShared(new Test());

    return a.exec();
}
