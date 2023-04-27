/*
 * Qt Quick demo with QML
 *
 * 1. use signals in QML and calls slots in C++ based object
 * 2. use signals in QML and calls slots in QML
 *
 *
*/
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "calculate.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Calculate testClass;

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/QT6_ep29_QtQuick-QML/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setProperty("classA", &testClass);

    return app.exec();
}
