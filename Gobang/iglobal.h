#ifndef IGLOBAL_H
#define IGLOBAL_H

#include <QtCore/qobject.h>

#include "ipiece.h"

class IGlobal : public QObject
{
    Q_OBJECT
public:
    static IGlobal& global();

    QList<IPiece *> pieceList() const;
    void setPieceList(const QList<IPiece *> &pieceList);

    void addPiece(IPiece* pPieve);
    bool findPiece(const QPoint& pos);

private:
    explicit IGlobal(QObject* parent = nullptr);

private:
    QList<IPiece*> m_pieceList;
};

#endif // IGLOBAL_H
