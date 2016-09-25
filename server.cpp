#include "server.h"


Server::Server(int port, QObject *parent) :
    QTcpServer(parent)
{
    if(listen(QHostAddress::Any, port)) {
        qDebug() << "Listening ..." << port;
    } else {
        qDebug() << "Error while starting  " << errorString();
    }

}

void Server::incomingConnection(int handle)
{
    QSocketThread* thread = new QSocketThread(handle);
    connect(thread, SIGNAL(finished()),thread, SLOT(deleteLater()));
    thread->start();

}
