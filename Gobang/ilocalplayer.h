#ifndef ILOCALPLAYER_H
#define ILOCALPLAYER_H

#include "ichessplayer.h"

class ILocalPlayer : public IChessPlayer
{
    Q_OBJECT
public:
    explicit ILocalPlayer(QObject *parent = nullptr);

    virtual void toActive() override;
    virtual void takePos(const QPoint& pos) override;

signals:

};

#endif // ILOCALPLAYER_H
