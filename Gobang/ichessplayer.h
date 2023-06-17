#ifndef ICHESSPLAYER_H
#define ICHESSPLAYER_H

#include <QtCore/qobject.h>

#include "ipiece.h"

class IChessPlayer : public QObject
{
    Q_OBJECT
public:
    explicit IChessPlayer(QObject *parent = nullptr);
    virtual ~IChessPlayer();

    bool active() const;
    void setActive(bool active);

    IPieceCamp camp() const;
    void setCamp(const IPieceCamp &camp);

    void doMove();

    QPoint selectPos() const;
    void setSelectPos(const QPoint &selectPos);

    virtual void toActive() = 0;
    virtual void takePos(const QPoint& pos) = 0;

signals:
    void moved(IPiece* pPiece);

private:
    IPieceCamp m_camp;
    bool m_active;
    QPoint m_selectPos;
};

#endif // ICHESSPLAYER_H
