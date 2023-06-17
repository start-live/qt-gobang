#ifndef INETWORKPLAYER_H
#define INETWORKPLAYER_H

#include <QObject>

class INetworkPlayer : public QObject
{
    Q_OBJECT
public:
    explicit INetworkPlayer(QObject *parent = nullptr);

signals:

};

#endif // INETWORKPLAYER_H
