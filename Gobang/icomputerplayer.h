#ifndef ICOMPUTERPLAYER_H
#define ICOMPUTERPLAYER_H

#include <QObject>

class IComputerPlayer : public QObject
{
    Q_OBJECT
public:
    explicit IComputerPlayer(QObject *parent = nullptr);

signals:

};

#endif // ICOMPUTERPLAYER_H
