#ifndef IPIECE_H
#define IPIECE_H

#include <QtCore/qobject.h>
#include <QtCore/qpoint.h>
#include <QtCore/qsize.h>

enum class IPieceCamp
{
    BLack,
    White
};

class IPiece : public QObject
{
    Q_OBJECT
public:
    explicit IPiece(QObject *parent = nullptr);

    qint32 x() const;
    void setX(qint32 x);

    qint32 y() const;
    void setY(qint32 y);

    QPoint pos() const;
    void setPos(const QPoint &pos);

    qint32 width() const;
    void setWidth(qint32 width);

    qint32 height() const;
    void setHeight(qint32 height);

    QSize size() const;
    void setSize(const QSize &size);

    IPieceCamp camp() const;
    void setCamp(const IPieceCamp &camp);

signals:

private:
    QPoint m_pos;
    QSize m_size;
    IPieceCamp m_camp;
};

#endif // IPIECE_H
