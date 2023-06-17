#include "ipiece.h"

IPiece::IPiece(QObject *parent)
    : QObject(parent)
{

}

qint32 IPiece::x() const
{
    return m_pos.x();
}

void IPiece::setX(qint32 x)
{
    m_pos.setX(x);
}

qint32 IPiece::y() const
{
    return m_pos.y();
}

void IPiece::setY(qint32 y)
{
    m_pos.setY(y);
}

QPoint IPiece::pos() const
{
    return m_pos;
}

void IPiece::setPos(const QPoint &pos)
{
    m_pos = pos;
}

qint32 IPiece::width() const
{
    return m_size.width();
}

void IPiece::setWidth(qint32 width)
{
    m_size.setWidth(width);
}

qint32 IPiece::height() const
{
    return m_size.height();
}

void IPiece::setHeight(qint32 height)
{
    m_size.setHeight(height);
}

QSize IPiece::size() const
{
    return m_size;
}

void IPiece::setSize(const QSize &size)
{
    m_size = size;
}

IPieceCamp IPiece::camp() const
{
    return m_camp;
}

void IPiece::setCamp(const IPieceCamp &camp)
{
    m_camp = camp;
}
