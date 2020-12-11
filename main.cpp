#include "mainmenu.h"

#include <QApplication>
#include <QtWidgets>
#include <QSplashScreen>

void loadModules(QSplashScreen *psplash)
{
    QTime time;
    time.start();

    for(int i = 0; i < 100;) {
        if(time.elapsed() > 40) {
            time.start();
            ++i;
        }
        psplash->showMessage("Loading modules: " + QString::number(i) + "%", Qt::AlignCenter|Qt::AlignCenter, Qt::white);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/pictures/fr_cuisine.jpg"));
    splash.show();
    MainMenu w;
    loadModules(&splash);
    splash.finish(&w);
    QFile file(":/browser/helper/style.qss");
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());
    a.setStyleSheet(strCSS);
    w.show();
    return a.exec();
}
