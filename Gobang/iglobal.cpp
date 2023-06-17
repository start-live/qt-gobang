#include "iglobal.h"

IGlobal &IGlobal::global()
{
    static IGlobal instance;
    return instance;
}

IGlobal::~IGlobal()
{

}

IGlobal::IGlobal(QObject* parent)
    : QObject(parent)
    , m_roadCount(15)
    , m_pieceSize(48, 48)
{

}

qint32 IGlobal::roadCount() const
{
    return m_roadCount;
}

void IGlobal::setRoadCount(const qint32 &roadCount)
{
    m_roadCount = roadCount;
}

QSize IGlobal::pieceSize() const
{
    return m_pieceSize;
}

void IGlobal::setPieceSize(const QSize &pieceSize)
{
    m_pieceSize = pieceSize;
}

QList<IPiece *> IGlobal::pieceList() const
{
    return m_pieceList;
}

void IGlobal::setPieceList(const QList<IPiece *> &pieceList)
{
    m_pieceList = pieceList;
}

IPiece *IGlobal::lastPiece()
{
    return m_pieceList.isEmpty() ? nullptr : m_pieceList.last();
}

IPiece *IGlobal::getPiece(const QPoint &pos)
{
    for (IPiece* pPiece : m_pieceList)
    {
        if (pPiece->pos() == pos)
            return pPiece;
    }
    return nullptr;
}

void IGlobal::addPiece(IPiece *pPiece)
{
    if (pPiece == nullptr)
        return;

    m_pieceList.append(pPiece);
}

void IGlobal::clearPiece()
{
    for (IPiece* pPiece : m_pieceList)
    {
        delete pPiece;
    }
    m_pieceList.clear();
}

bool IGlobal::findPiece(const QPoint &pos)
{
    return getPiece(pos) != nullptr;
}

bool IGlobal::findSameCampPiece(const QPoint &pos, const IPieceCamp &camp)
{
    IPiece* pPiece = getPiece(pos);
    return pPiece != nullptr && pPiece->camp() == camp;
}
