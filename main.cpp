#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "bindable.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Bindable>("Bindable", 1, 0, "Bindable");

    qmlRegisterSingletonType<BindableHelper>( "Bindable", 1, 0, "BindableHelper",  [](QQmlEngine *engine, QJSEngine *scriptEngine) -> BindableHelper * {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        BindableHelper *example = new BindableHelper();
        return example;
    });

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
