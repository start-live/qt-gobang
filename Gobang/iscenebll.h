#ifndef ISCENEBLL_H
#define ISCENEBLL_H

#include <QtCore/qobject.h>
#include <QtCore/qpoint.h>

class IPiece;
class IChessPlayer;

class ISceneBLL : public QObject
{
    Q_OBJECT
public:
    explicit ISceneBLL(QObject *parent = nullptr);
    ~ISceneBLL();

    IChessPlayer *balckPlayer() const;
    void setBalckPlayer(IChessPlayer *pBalckPlayer);

    IChessPlayer *whitePlayer() const;
    void setWhitePlayer(IChessPlayer *pWhitePlayer);

    IChessPlayer *currentPlayer() const;
    void setCurrentPlayer(IChessPlayer *pCurrentPlayer);

    IChessPlayer* nextPlayer();

    bool gameOver();
    bool gameOver(IPiece* pLastPiece);

    bool active() const;
    void setActive(bool active);

private:
    void init();

signals:
    void operated();
    void message(const QString& message);

private slots:
    void onPlayerMoved(IPiece* pPiece);

public slots:
    void selectPos(const QPoint& pos);
    void start();
    void restart();
    void pause();
    void end();
    void regret();
    void dogfall();
    void defeat();
    void prompt();

private:
    IChessPlayer* m_pBalckPlayer;
    IChessPlayer* m_pWhitePlayer;
    IChessPlayer* m_pCurrentPlayer;
    bool m_active;
};

#endif // ISCENEBLL_H
