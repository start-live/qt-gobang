#ifndef IGLOBAL_H
#define IGLOBAL_H

#include <QtCore/qobject.h>

#include "ipiece.h"

class IGlobal : public QObject
{
    Q_OBJECT
public:
    static IGlobal& global();
    ~IGlobal();

    QList<IPiece *> pieceList() const;
    void setPieceList(const QList<IPiece *> &pieceList);

    IPiece* lastPiece();
    IPiece* getPiece(const QPoint& pos);
    void addPiece(IPiece* pPieve);
    void clearPiece();
    bool findPiece(const QPoint& pos);
    bool findSameCampPiece(const QPoint& pos, const IPieceCamp& camp);

    QSize pieceSize() const;
    void setPieceSize(const QSize &pieceSize);

    qint32 roadCount() const;
    void setRoadCount(const qint32 &roadCount);

private:
    explicit IGlobal(QObject* parent = nullptr);

private:
    qint32 m_roadCount;
    QSize m_pieceSize;
    QList<IPiece*> m_pieceList;
};

#endif // IGLOBAL_H
