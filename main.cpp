//#include "mainwindow.h"
#include "game.h"
#include <QApplication>

game* Game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game = new game();
    Game->show();
    //MainWindow w;
    //w.show();
    return a.exec();
}
