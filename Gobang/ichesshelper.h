#ifndef ICHESSHELPER_H
#define ICHESSHELPER_H

#include "ipiece.h"

class IChessHelper : public QObject
{
    Q_OBJECT
public:
    explicit IChessHelper(QObject *parent = nullptr);

    qint32 up2downPieceCount(const QPoint& piecePos, const IPieceCamp& camp);
    qint32 left2rightPieceCount(const QPoint& piecePos, const IPieceCamp& camp);
    qint32 topLeft2bottomRightPieceCount(const QPoint& piecePos, const IPieceCamp& camp);
    qint32 topRight2bottomLeftPieceCount(const QPoint& piecePos, const IPieceCamp& camp);

signals:

};

#endif // ICHESSHELPER_H
