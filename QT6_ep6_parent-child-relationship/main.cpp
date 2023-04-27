/*
 * Qt memory managment
 * Parent and child relationship
 *
 * 1. Create a class to setup parent and child relationship
 * 2. Setting in the constructor
 *
 * Spot will be deleted automatically,
 * because it's the child of the parent(Application a).
 *
 * 3. Setting up after constructor (setParent)
 * Princess will be deleted automatically,
 * because cat set dog as its parent.
 *
*/

#include <QCoreApplication>
#include <QTimer>
#include "test.h"

// Setting in the constructor
Test* getTest(QObject* parent){
    return new Test(parent);    // with parent
}

// Setting up after constructor
Test* getTest(){
    return new Test();    // No parent
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTimer timer;
    timer.singleShot(3000, &a, &QCoreApplication::quit);   // (ms, reciever, slot)

    // Setting in the constructor
    Test* dog = getTest(&a);
    dog->setObjectName("Spot");

    // Setting up after constructor
    Test* cat = getTest();
    cat->setObjectName("Princess");
    cat->setParent(dog);    // set dog as its parent

    int value = a.exec();
    qInfo() << "Exit code: " << value;
    return value;
//    return a.exec();
}
