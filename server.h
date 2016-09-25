#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QDateTime>
#include "qsocketthread.h"


class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(int port, QObject *parent = 0);
private:
    void incomingConnection(int socketId);

public slots:

};

#endif // SERVER_H
