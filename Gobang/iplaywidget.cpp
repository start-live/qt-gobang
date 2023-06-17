#include "iplaywidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlayoutitem.h>
#include <QtWidgets/qlabel.h>

#include <QtGui/qicon.h>

#include "ipersonalwidget.h"

IPlayWidget::IPlayWidget(QWidget *parent)
    : QWidget(parent)
    , m_pMainLayout(nullptr)
    , m_pLeftPersonalWidget(nullptr)
    , m_pLeftHorizontalSpacer(nullptr)
    , m_pVSLabel(nullptr)
    , m_pRightHorizontalSpacer(nullptr)
    , m_pRightPersonalWidget(nullptr)
{
    init();
}

void IPlayWidget::init()
{
    m_pMainLayout = new QHBoxLayout();
    m_pLeftPersonalWidget = new IPersonalWidget(this);
    m_pLeftHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_pVSLabel = new QLabel(this);
    m_pRightHorizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_pRightPersonalWidget = new IPersonalWidget(this);

    m_pMainLayout->addWidget(m_pLeftPersonalWidget);
    m_pMainLayout->addItem(m_pLeftHorizontalSpacer);
    m_pMainLayout->addWidget(m_pVSLabel);
    m_pMainLayout->addItem(m_pRightHorizontalSpacer);
    m_pMainLayout->addWidget(m_pRightPersonalWidget);
    this->setLayout(m_pMainLayout);

    m_pVSLabel->setFixedSize(100, 60);
    m_pVSLabel->setText("VS");
    m_pVSLabel->setPixmap(QPixmap(":/gobang/images/vs.png"));
    m_pVSLabel->setScaledContents(true);
    m_pLeftPersonalWidget->setImage(QPixmap(":/gobang/images/player2.png"));
    m_pLeftPersonalWidget->setName("黑方");
    m_pRightPersonalWidget->setDirection(IInfoDerection::RightToLeft);
    m_pRightPersonalWidget->setImage(QPixmap(":/gobang/images/player1.png"));
    m_pRightPersonalWidget->setName("白方");
}
