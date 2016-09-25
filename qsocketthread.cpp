#include "qsocketthread.h"



QSocketThread::QSocketThread(int descriptor, QObject *parent) :
        QThread(parent), socketDesc(descriptor)
{

}


QSocketThread::~QSocketThread()
{
    delete socket;
}

void QSocketThread::run()
{
    socket = new QTcpSocket();
    socket->setSocketDescriptor(socketDesc);

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(onDisconnect()),Qt::DirectConnection);

    exec();
}

void QSocketThread::onReadyRead()
{
    qDebug() << socket -> readAll();

    QString response = "HTTP/1.1 200 OK\r\n\r\n%q";
    socket->write(response.arg(QTime::currentTime().toString()).toLatin1());
    socket->disconnectFromHost();
}

void QSocketThread::onDisconnect()
{
    socket->close();
    quit();
}
