#include "uiinkamo.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QProcess>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Ink_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    UiInkamo Ink;

    if(Ink.actualizar())
    {
        QProcess *proc = new QProcess(0);
        proc->start(QString(argv[0]), QStringList(""));
        return 0;
    }

    Ink.detectar_impresoras();

    Ink.show();
    return app.exec();
}
