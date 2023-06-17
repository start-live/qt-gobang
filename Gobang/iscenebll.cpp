#include "iscenebll.h"

#include <QtCore/qdebug.h>

#include "ilocalplayer.h"
#include "icomputerplayer.h"
#include "inetworkplayer.h"

#include "iglobal.h"
#include "ichesshelper.h"

ISceneBLL::ISceneBLL(QObject *parent)
    : QObject(parent)
    , m_pBalckPlayer(nullptr)
    , m_pWhitePlayer(nullptr)
    , m_pCurrentPlayer(nullptr)
    , m_active(false)
{
    init();
}

ISceneBLL::~ISceneBLL()
{
//    m_pCurrentPlayer = nullptr;
//    delete m_pBalckPlayer;
//    delete m_pWhitePlayer;
}

void ISceneBLL::selectPos(const QPoint &pos)
{
    if (m_pCurrentPlayer == nullptr)
        return;

    if (!m_active)
    {
        emit message("没有开始游戏！");
        return;
    }

    m_pCurrentPlayer->takePos(pos);
}

void ISceneBLL::start()
{
    if (!m_active)
    {
        m_active = true;
        return;
    }

    emit message("已经开始游戏！");
}

void ISceneBLL::restart()
{

}

void ISceneBLL::pause()
{

}

void ISceneBLL::end()
{

}

void ISceneBLL::regret()
{

}

void ISceneBLL::dogfall()
{

}

void ISceneBLL::defeat()
{

}

void ISceneBLL::prompt()
{

}

bool ISceneBLL::active() const
{
    return m_active;
}

void ISceneBLL::setActive(bool active)
{
    m_active = active;
}

IChessPlayer *ISceneBLL::currentPlayer() const
{
    return m_pCurrentPlayer;
}

void ISceneBLL::setCurrentPlayer(IChessPlayer *pCurrentPlayer)
{
    m_pCurrentPlayer = pCurrentPlayer;
}

IChessPlayer *ISceneBLL::nextPlayer()
{
    if (m_pCurrentPlayer == nullptr)
        return nullptr;

    return m_pCurrentPlayer == m_pBalckPlayer ? m_pWhitePlayer : m_pBalckPlayer;
}

bool ISceneBLL::gameOver()
{
    return gameOver(IGlobal::global().lastPiece());
}

bool ISceneBLL::gameOver(IPiece *pLastPiece)
{
    if (pLastPiece == nullptr)
        return false;

    IPieceCamp camp = pLastPiece->camp();
    QPoint piecePos = pLastPiece->pos();
    IChessHelper helper;
    qint32 pieceCount;

    //上下
    pieceCount = helper.up2downPieceCount(piecePos, camp);
    if (pieceCount >= 5)
        return true;

    //左右
    pieceCount = helper.left2rightPieceCount(piecePos, camp);
    if (pieceCount >= 5)
        return true;

    //左上-右下
    pieceCount = helper.topLeft2bottomRightPieceCount(piecePos, camp);
    if (pieceCount >= 5)
        return true;

    //右上-左下
    pieceCount = helper.topRight2bottomLeftPieceCount(piecePos, camp);
    if (pieceCount >= 5)
        return true;

    return false;
}

void ISceneBLL::init()
{
    m_pBalckPlayer = new ILocalPlayer(this);
    m_pBalckPlayer->setCamp(IPieceCamp::BLack);
    QObject::connect(m_pBalckPlayer, SIGNAL(moved(IPiece*))
                     , this, SLOT(onPlayerMoved(IPiece*)));

    m_pWhitePlayer = new ILocalPlayer(this);
    m_pWhitePlayer->setCamp(IPieceCamp::White);
    QObject::connect(m_pWhitePlayer, SIGNAL(moved(IPiece*))
                     , this, SLOT(onPlayerMoved(IPiece*)));

    m_pCurrentPlayer = m_pBalckPlayer;
}

void ISceneBLL::onPlayerMoved(IPiece *pPiece)
{
    if (gameOver(pPiece))
    {
        IGlobal::global().clearPiece();
        emit operated();
        return;
    }

    m_pCurrentPlayer = nextPlayer();
    m_pCurrentPlayer->toActive();
    emit operated();
}

IChessPlayer *ISceneBLL::whitePlayer() const
{
    return m_pWhitePlayer;
}

void ISceneBLL::setWhitePlayer(IChessPlayer *pWhitePlayer)
{
    m_pWhitePlayer = pWhitePlayer;
}

IChessPlayer *ISceneBLL::balckPlayer() const
{
    return m_pBalckPlayer;
}

void ISceneBLL::setBalckPlayer(IChessPlayer *pBalckPlayer)
{
    m_pBalckPlayer = pBalckPlayer;
}
