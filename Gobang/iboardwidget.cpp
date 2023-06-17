#include "iboardwidget.h"

#include <QtGui/qpainter.h>
#include <QtGui/qevent.h>

#include <QtCore/qdebug.h>

#include "iglobal.h"

IBoardWidget::IBoardWidget(QWidget *parent)
    : QWidget(parent)
{
    m_x = 10;
    m_y = 10;
    m_space = 50;
    m_pieceWidth = m_space - 2;
    m_width = m_space * (IGlobal::global().roadCount() + 1);
    m_height = m_space * (IGlobal::global().roadCount() + 1);
    isb = true;

    this->setFixedSize(m_width + 20, m_height + 20);
}

void IBoardWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    QPen originalPen = painter.pen();
    QPen newPen = originalPen;
    //最外层
    newPen.setWidth(3);
    painter.setPen(newPen);
    painter.fillRect(m_x, m_y, m_width, m_height, QColor(255,205,67));

    //网格
    painter.setPen(originalPen);
    for (qint32 x = m_x + m_space * 2; x <= m_width - m_space;x += m_space)
    {
        QPoint verticalStartPos(x, m_y + m_space);
        QPoint verticalEndPos(x, m_y + m_height - m_space);
        painter.drawLine(verticalStartPos, verticalEndPos);
    }
    for (qint32 y = m_y + m_space * 2;y <= m_height - m_space;y += m_space)
    {
        QPoint horizontalStartPos(m_x + m_space, y);
        QPoint horizontalEndPos(m_x + m_width - m_space, y);
        painter.drawLine(horizontalStartPos, horizontalEndPos);
    }

    //外围
    newPen.setWidth(2);
    painter.setPen(newPen);
    painter.drawRect(m_x + m_space, m_y + m_space, m_width - m_space * 2, m_height - m_space * 2);

    //绘制棋子
    painter.setPen(originalPen);
    QList<IPiece*> pieceList = IGlobal::global().pieceList();
    qint32 startX = m_x + m_space;
    qint32 startY = m_y + m_space;
    for (IPiece* pPiece : pieceList)
    {
        qint32 x = startX + pPiece->x() * m_space - m_pieceWidth / 2;
        qint32 y = startY + pPiece->y() * m_space - m_pieceWidth / 2;
        painter.setBrush(pPiece->camp() == IPieceCamp::BLack ? Qt::black : Qt::white);
        painter.drawEllipse(x, y, pPiece->width(), pPiece->height());
    }

    //绘制高亮
    IPiece* pPiece = pieceList.isEmpty() ? nullptr : pieceList.last();
    if (pPiece != nullptr)
    {
        originalPen.setColor(QColor(14,17,219));
        painter.setPen(originalPen);
        qint32 x = startX + pPiece->x() * m_space - m_pieceWidth / 2;
        qint32 y = startY + pPiece->y() * m_space - m_pieceWidth / 2;
        QRect pieceRange(x, y, pPiece->width(), pPiece->height());
        qint32 lineWidth = 10;
        QPoint pos;

        //左上角
        pos = pieceRange.topLeft();
        QPoint rightPos = pos + QPoint(lineWidth, 0);
        QPoint bottomPos = pos + QPoint(0, lineWidth);
        painter.drawLine(pos, rightPos);
        painter.drawLine(pos, bottomPos);

        //右上角
        pos = pieceRange.topRight();
        QPoint leftPos = pos + QPoint(-lineWidth, 0);
        bottomPos = pos + QPoint(0, lineWidth);
        painter.drawLine(pos, leftPos);
        painter.drawLine(pos, bottomPos);

        //左下角
        pos = pieceRange.bottomLeft();
        QPoint topPos = pos + QPoint(0, -lineWidth);
        rightPos = pos + QPoint(lineWidth, 0);
        painter.drawLine(pos, topPos);
        painter.drawLine(pos, rightPos);

        //右下角
        pos = pieceRange.bottomRight();
        topPos = pos + QPoint(0, -lineWidth);
        leftPos = pos + QPoint(-lineWidth, 0);
        painter.drawLine(pos, topPos);
        painter.drawLine(pos, leftPos);
    }
}

void IBoardWidget::mousePressEvent(QMouseEvent *event)
{
    QPoint eventPos = event->pos();
    qint32 startX = m_x + m_space;
    qint32 startY = m_y + m_space;
    QPoint selectPos;
    qint32 roadCount = IGlobal::global().roadCount();
    for (qint32 roadX = 0;roadX < roadCount;roadX++)
    {
        selectPos.setX(startX + roadX * m_space);
        for (qint32 roadY = 0;roadY < roadCount;roadY++)
        {
            selectPos.setY(startY + roadY * m_space);

            if (qAbs(eventPos.x() - selectPos.x()) < 20 && qAbs(eventPos.y() - selectPos.y()) < 20)
            {
                emit posClicked(QPoint(roadX, roadY));
                return;
            }
        }
    }
}
