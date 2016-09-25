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
    QTcpSocket * socket = new QTcpSocket(this);
    socket -> setSocketDescriptor(handle);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconect()), this, SLOT(onDisconect()));
}

void Server::onReadyRead()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    qDebug() << socket -> readAll();

    QString response = "HTTP/1.1 200 OK\r\n\r\n%q";
    socket->write(response.arg(QTime::currentTime().toString()).toLatin1());
    socket ->disconnectFromHost();
}

void Server::onDisconect()
{
    QTcpSocket * socket = qobject_cast<QTcpSocket*>(sender());
    socket->close();
    socket->deleteLater();

}
