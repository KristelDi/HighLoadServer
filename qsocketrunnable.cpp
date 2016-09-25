#include "qsocketrunnable.h"

QSocketRunnable::QSocketRunnable(int handle) :
    descriptor(handle)
{

}


void QSocketRunnable::run()
{
    QTcpSocket * socket = new QTcpSocket();
    socket->setSocketDescriptor(descriptor);

    socket->waitForReadyRead();
    qDebug() << socket -> readAll();

    QString response = "HTTP/1.1 200 OK\r\n\r\nCurrentTime: %1";
    socket->write(response.arg(QTime::currentTime().toString()).toLatin1());
    socket->waitForBytesWritten();

    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}

