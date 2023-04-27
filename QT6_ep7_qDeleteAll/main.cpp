/*
 * Qt memory managment
 * qDeleteAll
 * https://youtu.be/TXl5XxzUs0s
 *
 * 1. Getting a list of pointes
 * 2. Display the list
 * 3. qDeleteAll in action
 *
 * when we display all pointers in list, we found that those pointers have no parent (QObject 0x0),
 * which don't follow parent-child relationship and will not be deleted automatically,
 * it may casuse the memory leak here.
 *
 * After we perform qdeleteAll(list), we found those child has been deleted.
 *
*/
#include <QCoreApplication>
#include "test.h"

// Getting a list of pointes
typedef QList<Test*> testList;

testList getList(){
    testList list;
    for(int i = 0; i < 5; i++){
        list.append(new Test());
        list.last()->setObjectName("Test" + QString::number(i));
    }

    // qt list is not QObject, we simply return it, we're doing a copy here.
    return list;
}

void display(testList list){
    foreach(Test* item, list){
        qInfo() << item;    // we didn't check the pointer is valid of not, it may cause the problem.
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // In action...
    testList list = getList();
    display(list);

    qInfo() << "Deleting ...";
    qDeleteAll(list);   // the entire list
//    qDeleteAll(list.begin(), list.end());   // the same
//    list.clear();   // everytime we use qDeleteAll, we must clear list

    display(list);  // it will crash the application if we don't clear the list and use bad pointers.

    return a.exec();
}
