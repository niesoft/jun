#include <QCoreApplication>
#include <QDebug>
#include "httpserver.h"

void onHttpConnect(QString text);
void onHttpDisconnect();
void onHttpError();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    httpserver httpserver;
    httpserver.start();
    return a.exec();
}

void onHttpConnect(QString text)
{
    qDebug() << text;
}
void onHttpDisconnect()
{

}
void onHttpError()
{

}
