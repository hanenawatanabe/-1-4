#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QTextCodec>

extern bool optEnable;


int main(int argc, char *argv[])
{
    //中文乱码问题解决
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF8"));
        QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF8"));

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
