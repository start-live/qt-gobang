#include "iscenewidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlayoutitem.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qmessagebox.h>

#include <QtGui/qicon.h>

#include "iplaywidget.h"
#include "iboardwidget.h"
#include "ioperationwidget.h"

#include "iglobal.h"
#include "iscenebll.h"

ISceneWidget::ISceneWidget(QWidget *parent)
    : QWidget(parent)
    , m_pMainLayout(nullptr)
    , m_pTopVerticalSpacer(nullptr)
    , m_pPlayWidget(nullptr)
    , m_pBoardWidget(nullptr)
    , m_pOperationWidget(nullptr)
    , m_pBottomVerticalSpacer(nullptr)
    , m_pSceneBLL(nullptr)
{
    init();
}

void ISceneWidget::init()
{
    initWidget();
    initBLL();
}

void ISceneWidget::initWidget()
{
    m_pMainLayout = new QVBoxLayout();
    m_pTopVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_pPlayWidget = new IPlayWidget(this);
    m_pBoardWidget = new IBoardWidget(this);
    m_pOperationWidget = new IOperationWidget(this);
    m_pBottomVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);


    m_pMainLayout->addItem(m_pTopVerticalSpacer);
    m_pMainLayout->addWidget(m_pPlayWidget);
    m_pMainLayout->addWidget(m_pBoardWidget);
    m_pMainLayout->addWidget(m_pOperationWidget);
    m_pMainLayout->addItem(m_pBottomVerticalSpacer);
    this->setLayout(m_pMainLayout);

    m_pMainLayout->setSpacing(0);

    this->setWindowIcon(QIcon(":/gobang/images/wzq.png"));
    this->setAttribute(Qt::WA_StyledBackground);
    this->setObjectName("SceneWidget");
    this->setStyleSheet("QWidget#SceneWidget{border-image:url(:/gobang/images/background4.png);}");
}

void ISceneWidget::initBLL()
{
    m_pSceneBLL = new ISceneBLL(this);
    QObject::connect(m_pBoardWidget, SIGNAL(posClicked(const QPoint&))
                     , m_pSceneBLL, SLOT(selectPos(const QPoint&)));
    QObject::connect(m_pSceneBLL, SIGNAL(operated())
                     , m_pBoardWidget, SLOT(update()));
    QObject::connect(m_pSceneBLL, SIGNAL(message(const QString&))
                     , this, SLOT(onBLLMessage(const QString&)));
    //m_pOperationWidget
    QObject::connect(m_pOperationWidget, &IOperationWidget::start, m_pSceneBLL, &ISceneBLL::start);
    QObject::connect(m_pOperationWidget, &IOperationWidget::restart, m_pSceneBLL, &ISceneBLL::restart);
    QObject::connect(m_pOperationWidget, &IOperationWidget::pause, m_pSceneBLL, &ISceneBLL::pause);
    QObject::connect(m_pOperationWidget, &IOperationWidget::end, m_pSceneBLL, &ISceneBLL::end);
    QObject::connect(m_pOperationWidget, &IOperationWidget::regret, m_pSceneBLL, &ISceneBLL::regret);
    QObject::connect(m_pOperationWidget, &IOperationWidget::dogfall, m_pSceneBLL, &ISceneBLL::dogfall);
    QObject::connect(m_pOperationWidget, &IOperationWidget::defeat, m_pSceneBLL, &ISceneBLL::defeat);
    QObject::connect(m_pOperationWidget, &IOperationWidget::prompt, m_pSceneBLL, &ISceneBLL::prompt);
}

void ISceneWidget::onBLLMessage(const QString &message)
{
    QMessageBox::information(this, "提示", message);
}

