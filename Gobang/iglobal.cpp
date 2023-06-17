#include "iglobal.h"

IGlobal &IGlobal::global()
{
    static IGlobal instance;
    return instance;
}

IGlobal::IGlobal(QObject* parent)
    : QObject(parent)
{

}

QList<IPiece *> IGlobal::pieceList() const
{
    return m_pieceList;
}

void IGlobal::setPieceList(const QList<IPiece *> &pieceList)
{
    m_pieceList = pieceList;
}

void IGlobal::addPiece(IPiece *pPiece)
{
    if (pPiece == nullptr)
        return;

    m_pieceList.append(pPiece);
}

bool IGlobal::findPiece(const QPoint &pos)
{
    for (IPiece* pPiece : m_pieceList)
    {
        if (pPiece->pos() == pos)
            return true;
    }
    return false;
}
