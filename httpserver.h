#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QtNetwork>
#include <QTcpServer>
//#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QObject>

class QTcpServer;

class httpserver : public QObject
{
    Q_OBJECT
public:
    httpserver();
private:
    QTcpServer *tcpServer;
    QMap<int,QTcpSocket *> SClients;
public slots:
    bool start();
private slots:
    void newclient();
    void slotReadClient();
};

#endif // HTTPSERVER_H
