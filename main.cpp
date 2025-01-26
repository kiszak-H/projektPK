#include <QApplication>
#include <windows.h>
#include "mainwindow.h"

#include <stdio.h>

#include <iostream>

int main(int argc, char* argv[])
{

    
  //  Q_INIT_RESOURCE(application);

    QApplication app(argc, argv);
    app.setOrganizationName("Trolltech");
    app.setApplicationName("Application Example");
    MainWindow mainWin;
    //mainWin.setMinimumWidth(500);
    mainWin.setMinimumSize(QSize(500, 500));

#if defined(Q_OS_SYMBIAN)
    mainWin.showMaximized();
#else
    mainWin.show();
#endif
    return app.exec();
}