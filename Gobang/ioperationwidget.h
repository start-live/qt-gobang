#ifndef IOPERATIONWIDGET_H
#define IOPERATIONWIDGET_H

#include <QtWidgets/qwidget.h>

class QHBoxLayout;
class QPushButton;

class IOperationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IOperationWidget(QWidget *parent = nullptr);

private:
    void init();

signals:
    void start();
    void restart();
    void pause();
    void end();
    void regret();
    void dogfall();
    void defeat();
    void prompt();

private:
    QHBoxLayout* m_pMainLayout;
    QPushButton* m_pStartButton;
    QPushButton* m_pRestartButton;
    QPushButton* m_pPauseButton;
    QPushButton* m_pEndButton;
    QPushButton* m_pRegretButton;
    QPushButton* m_pDogfallButton;
    QPushButton* m_pDefeatButton;
    QPushButton* m_pPromptButton;
};

#endif // IOPERATIONWIDGET_H
