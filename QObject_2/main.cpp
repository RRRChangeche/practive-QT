/*
 * QObject cannot be copied.
 * https://youtu.be/M6W-ViiX0l0
*/

#include <QCoreApplication>
#include "cat.h"

void test(Cat &cat){
    qInfo() << "Addr " << &cat;
}

void test2(Cat *cat){
    qInfo() << "Ptr "<< cat;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Cat kitty;
    kitty.setObjectName("kitty");
    Cat death;
    death.setObjectName("death");

    test(kitty);
    test2(&kitty);

    test(death);
    test2(&death);

    return a.exec();
}
