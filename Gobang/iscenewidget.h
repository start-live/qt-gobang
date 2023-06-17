#ifndef ISCENEWIDGET_H
#define ISCENEWIDGET_H

#include <QtWidgets/qwidget.h>

class QVBoxLayout;
class IPlayWidget;
class QSpacerItem;
class IBoardWidget;
class IOperationWidget;
class QLabel;

class ISceneBLL;

class ISceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ISceneWidget(QWidget *parent = nullptr);

private:
    void init();
    void initWidget();
    void initBLL();

signals:

private slots:
    void onBLLMessage(const QString& message);

private:
    QVBoxLayout* m_pMainLayout;
    QSpacerItem* m_pTopVerticalSpacer;
    IPlayWidget* m_pPlayWidget;
    IBoardWidget* m_pBoardWidget;
    IOperationWidget* m_pOperationWidget;
    QSpacerItem* m_pBottomVerticalSpacer;

    ISceneBLL* m_pSceneBLL;
};

#endif // ISCENEWIDGET_H
