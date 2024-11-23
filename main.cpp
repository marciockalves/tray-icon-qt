#include "settingswidget.h"
#include <QSystemTrayIcon>
#include <QApplication>
#include <QMenu>
#include <QAction>
#include <QObject>
#include <QFile>
#include <QSharedMemory>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    if(!QSystemTrayIcon::isSystemTrayAvailable()){
        qCritical("O Sitema não permite sistemas de Controle!");
        return -1;
    }

    QSharedMemory shareMemory("MyUniqueApplicationTrayIcon");

    if(!shareMemory.create(1)){
        QMessageBox::warning(nullptr, "já em execução", "A Aplicação já está em execução");
        return -1;
    };

    QApplication::setQuitOnLastWindowClosed(false);

    QSystemTrayIcon trayIcon;

    if (!QFile::exists(":/icons/icon.ico")) {
        qWarning() << "Ícone não encontrado!";
    }

    trayIcon.setIcon(QIcon(":/icons/icon.ico"));

    QMenu trayMenu;
    QAction settingsAction("Configurações");
    QAction exitAction("Sair");

    trayMenu.addAction(&settingsAction);
    trayMenu.addSeparator();
    trayMenu.addAction(&exitAction);

    trayIcon.setContextMenu(&trayMenu);
    trayIcon.show();

    SettingsWidget settingsWidget;

    QObject::connect(&settingsAction, &QAction::triggered, [&]() {
        settingsWidget.show();
    });

    QObject::connect(&exitAction, &QAction::triggered, &app, &QApplication::quit);

    QObject::connect(&app, &QApplication::aboutToQuit, [&](){
        shareMemory.detach();
    });


    return app.exec();

}
