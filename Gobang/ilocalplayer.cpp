#include "ilocalplayer.h"

#include "iglobal.h"

ILocalPlayer::ILocalPlayer(QObject *parent)
    : IChessPlayer(parent)
{

}

void ILocalPlayer::toActive()
{
    setSelectPos(QPoint(-1, -1));
}

void ILocalPlayer::takePos(const QPoint &pos)
{
    if (IGlobal::global().findPiece(pos))
        return;

    setSelectPos(pos);
    doMove();
}
