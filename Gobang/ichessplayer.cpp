#include "ichessplayer.h"

#include "iglobal.h"

IChessPlayer::IChessPlayer(QObject *parent)
    : QObject(parent)
{

}

IChessPlayer::~IChessPlayer()
{

}

bool IChessPlayer::active() const
{
    return m_active;
}

void IChessPlayer::setActive(bool active)
{
    m_active = active;
}

void IChessPlayer::toActive()
{
    m_active = true;
}

IPieceCamp IChessPlayer::camp() const
{
    return m_camp;
}

void IChessPlayer::setCamp(const IPieceCamp &camp)
{
    m_camp = camp;
}

void IChessPlayer::doMove()
{
    IPiece* pPiece = new IPiece(this);
    pPiece->setPos(m_selectPos);
    pPiece->setSize(IGlobal::global().pieceSize());
    pPiece->setCamp(m_camp);
    IGlobal::global().addPiece(pPiece);
    emit moved(pPiece);
}

QPoint IChessPlayer::selectPos() const
{
    return m_selectPos;
}

void IChessPlayer::setSelectPos(const QPoint &selectPos)
{
    m_selectPos = selectPos;
}
