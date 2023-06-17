#include "ioperationwidget.h"

#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>

IOperationWidget::IOperationWidget(QWidget *parent)
    : QWidget(parent)
    , m_pMainLayout(nullptr)
    , m_pStartButton(nullptr)
    , m_pRestartButton(nullptr)
    , m_pPauseButton(nullptr)
    , m_pEndButton(nullptr)
    , m_pRegretButton(nullptr)
    , m_pDogfallButton(nullptr)
    , m_pDefeatButton(nullptr)
    , m_pPromptButton(nullptr)
{
    init();
}

void IOperationWidget::init()
{
    m_pMainLayout = new QHBoxLayout();
    m_pStartButton = new QPushButton(this);
    m_pRestartButton = new QPushButton(this);
    m_pPauseButton = new QPushButton(this);
    m_pEndButton = new QPushButton(this);
    m_pRegretButton = new QPushButton(this);
    m_pDogfallButton = new QPushButton(this);
    m_pDefeatButton = new QPushButton(this);
    m_pPromptButton = new QPushButton(this);

    m_pMainLayout->addWidget(m_pStartButton);
    m_pMainLayout->addWidget(m_pRestartButton);
    m_pMainLayout->addWidget(m_pPauseButton);
    m_pMainLayout->addWidget(m_pEndButton);
    m_pMainLayout->addWidget(m_pRegretButton);
    m_pMainLayout->addWidget(m_pDogfallButton);
    m_pMainLayout->addWidget(m_pDefeatButton);
    m_pMainLayout->addWidget(m_pPromptButton);
    this->setLayout(m_pMainLayout);

    m_pMainLayout->setMargin(0);
    m_pStartButton->setText("开始");
    m_pRestartButton->setText("重新开始");
    m_pPauseButton->setText("暂停");
    m_pEndButton->setText("结束");
    m_pRegretButton->setText("悔棋");
    m_pDogfallButton->setText("求和");
    m_pDefeatButton->setText("认输");
    m_pPromptButton->setText("提示");

    QObject::connect(m_pStartButton, &QPushButton::clicked, this, &IOperationWidget::start);
    QObject::connect(m_pRestartButton, &QPushButton::clicked, this, &IOperationWidget::restart);
    QObject::connect(m_pPauseButton, &QPushButton::clicked, this, &IOperationWidget::pause);
    QObject::connect(m_pEndButton, &QPushButton::clicked, this, &IOperationWidget::end);
    QObject::connect(m_pRegretButton, &QPushButton::clicked, this, &IOperationWidget::regret);
    QObject::connect(m_pDogfallButton, &QPushButton::clicked, this, &IOperationWidget::dogfall);
    QObject::connect(m_pDefeatButton, &QPushButton::clicked, this, &IOperationWidget::defeat);
    QObject::connect(m_pPromptButton, &QPushButton::clicked, this, &IOperationWidget::prompt);
}
