#include "ipersonalwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlabel.h>

IPersonalWidget::IPersonalWidget(QWidget *parent)
    : QWidget(parent)
    , m_pMainLayout(nullptr)
    , m_pImageLabel(nullptr)
    , m_pInfoLayout(nullptr)
    , m_pNameLabel(nullptr)
    , m_pTimeLabel(nullptr)
    , m_derection(IInfoDerection::LeftToRight)
{
    init();
}

void IPersonalWidget::setDirection(const IInfoDerection &derection)
{
    if (m_pMainLayout == nullptr)
        return;

    if (derection == m_derection)
        return;

    m_pMainLayout->removeWidget(m_pImageLabel);
    if (derection == IInfoDerection::RightToLeft)
    {
        m_pMainLayout->addWidget(m_pImageLabel);
    }
    else
    {
        m_pMainLayout->insertWidget(0, m_pImageLabel);
    }

    m_derection = derection;
}

void IPersonalWidget::setImage(const QPixmap &pixmap)
{
    if (m_pImageLabel == nullptr)
        return;

    m_pImageLabel->setPixmap(pixmap);
}

void IPersonalWidget::setName(const QString &name)
{
    if (m_pNameLabel == nullptr)
        return;

    m_pNameLabel->setText(name);
}

void IPersonalWidget::init()
{
    m_pMainLayout = new QHBoxLayout();
    m_pImageLabel = new QLabel(this);
    m_pInfoLayout = new QVBoxLayout();
    m_pNameLabel = new QLabel(this);
    m_pTimeLabel = new QLabel(this);

    m_pInfoLayout->addWidget(m_pNameLabel);
    m_pInfoLayout->addWidget(m_pTimeLabel);
    m_pMainLayout->addWidget(m_pImageLabel);
    m_pMainLayout->addLayout(m_pInfoLayout);
    this->setLayout(m_pMainLayout);

    m_pMainLayout->setContentsMargins(20, 0, 20, 0);
    m_pImageLabel->setFixedSize(100, 60);
    m_pImageLabel->setScaledContents(true);
    m_pNameLabel->setText("选手");
    m_pTimeLabel->setText("10:00");

    this->setObjectName("dd");
    this->setAttribute(Qt::WA_StyledBackground);
    this->setStyleSheet("QWidget#dd{background-color:red;}");
    //开始游戏， 重新开始，暂停游戏，结束游戏，悔棋，求和，认输，提示
}
