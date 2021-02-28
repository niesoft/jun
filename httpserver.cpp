#include "httpserver.h"

httpserver::httpserver()
{
    tcpServer = new QTcpServer(this);
}

bool httpserver::start()
{
    if (tcpServer->listen(QHostAddress::Any, 8080)){
        return connect(tcpServer, &QTcpServer::newConnection, this, &httpserver::newclient);
    }else{
        qDebug() << "error: " << tcpServer->errorString();
        return false;
    }
}

void httpserver::newclient()
{
    QTcpSocket* clientSocket=tcpServer->nextPendingConnection();
    int idusersocs=clientSocket->socketDescriptor();
    qDebug() << idusersocs;
    SClients[idusersocs]=clientSocket;
    connect(SClients[idusersocs],SIGNAL(readyRead()),this, SLOT(slotReadClient()));
}

void httpserver::slotReadClient()
{
    QTcpSocket* clientSocket = (QTcpSocket*)sender();
    int idusersocs = clientSocket->socketDescriptor();
    QTextStream os(clientSocket);
    os.setAutoDetectUnicode(true);
    os << "HTTP/1.0 200 Ok\r\n"
          "Content-Type: text/html; charset=\"utf-8\"\r\n"
          "\r\n"
          "<!DOCTYPE html>"
            "<html lang='en'>"
            "<head>"
                "<meta charset='UTF-8'>"
                "<meta content='width=device-width, user-scalable=no' name='viewport'>"
                "<title>Jun</title>"
            "</head>"
            "<body>"
                "<h1>Jun WebServer</h1>"
            "</body>"
            "</html>";
    qDebug() << "ReadClient:"+clientSocket->readAll()+"\n\r";
    // Если нужно закрыть сокет
    clientSocket->close();
    SClients.remove(idusersocs);
}
