#include "ichesshelper.h"

#include "iglobal.h"

IChessHelper::IChessHelper(QObject *parent)
    : QObject(parent)
{

}

qint32 IChessHelper::up2downPieceCount(const QPoint &piecePos, const IPieceCamp &camp)
{
    IGlobal& global = IGlobal::global();
    qint32 pieceCount = 0;
    QPoint pos;
    qint32 roadCount = global.roadCount();

    pieceCount = 1;
    pos = piecePos;
    //上
    for (qint32 y = piecePos.y() - 1; y >= 0; y--)
    {
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }
    //下
    for (qint32 y = piecePos.y() + 1; y < roadCount; y++)
    {
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }

    return pieceCount;
}

qint32 IChessHelper::left2rightPieceCount(const QPoint &piecePos, const IPieceCamp &camp)
{
    IGlobal& global = IGlobal::global();
    qint32 pieceCount = 0;
    QPoint pos;
    qint32 roadCount = global.roadCount();

    pieceCount = 1;
    pos = piecePos;
    //左
    for (qint32 x = piecePos.x() - 1; x >= 0; x--)
    {
        pos.setX(x);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }
    //右
    for (qint32 x = piecePos.x() + 1; x < roadCount; x++)
    {
        pos.setX(x);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }

    return pieceCount;
}

qint32 IChessHelper::topLeft2bottomRightPieceCount(const QPoint &piecePos, const IPieceCamp &camp)
{
    IGlobal& global = IGlobal::global();
    qint32 pieceCount = 0;
    QPoint pos;
    qint32 roadCount = global.roadCount();

    pieceCount = 1;
    pos = piecePos;
    //左上
    for (qint32 x = piecePos.x() - 1, y = piecePos.y() - 1; x >= 0 && y >= 0; x--, y--)
    {
        pos.setX(x);
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }
    //右下
    for (qint32 x = piecePos.x() + 1, y = piecePos.y() + 1; x < roadCount && y < roadCount; x++, y++)
    {
        pos.setX(x);
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }

    return pieceCount;
}

qint32 IChessHelper::topRight2bottomLeftPieceCount(const QPoint &piecePos, const IPieceCamp &camp)
{
    IGlobal& global = IGlobal::global();
    qint32 pieceCount = 0;
    QPoint pos;
    qint32 roadCount = global.roadCount();

    pieceCount = 1;
    pos = piecePos;
    //右上
    for (qint32 x = piecePos.x() + 1, y = piecePos.y() - 1; x < roadCount && y >= 0; x++, y--)
    {
        pos.setX(x);
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }
    //左下
    for (qint32 x = piecePos.x() - 1, y = piecePos.y() + 1; x >= 0 && y < roadCount; x--, y++)
    {
        pos.setX(x);
        pos.setY(y);
        if (!global.findSameCampPiece(pos, camp))
            break;
        pieceCount++;
    }

    return pieceCount;
}
