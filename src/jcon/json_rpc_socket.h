#ifndef JSONRPCSOCKET_H
#define JSONRPCSOCKET_H

#include "jcon.h"

#include <QHostAddress>
#include <QObject>

#include <memory>

namespace jcon {

class JCON_API JsonRpcSocket : public QObject
{
    Q_OBJECT

public:
    JsonRpcSocket() {}
    virtual ~JsonRpcSocket() {}

    virtual void connectToHost(QString host, int port) = 0;
    virtual bool waitForConnected() = 0;
    virtual void disconnectFromHost() = 0;
    virtual void send(const QByteArray& data) = 0;
    virtual QString errorString() const = 0;
    virtual QHostAddress localAddress() const = 0;
    virtual int localPort() const = 0;
    virtual QHostAddress peerAddress() const = 0;
    virtual int peerPort() const = 0;

signals:
    void dataReceived(const QByteArray& bytes, QObject* socket);
    void socketDisconnected(QObject* socket);
};

typedef std::shared_ptr<JsonRpcSocket> JsonRpcSocketPtr;

}

#endif
