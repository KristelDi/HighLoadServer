#ifndef QSOCKETTHREAD_H
#define QSOCKETTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTime>
#include <QTcpSocket>


class QSocketThread : public QThread
{
    Q_OBJECT
public:
    explicit QSocketThread(int descriptor, QObject *parent = 0);
    ~QSocketThread();

    void run();


public slots:
    void onReadyRead();
    void onDisconnect();

private:
    int socketDesc;
    QTcpSocket* socket;

};

#endif // QSOCKETTHREAD_H
