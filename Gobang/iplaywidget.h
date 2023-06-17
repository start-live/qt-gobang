#ifndef IPLAYWIDGET_H
#define IPLAYWIDGET_H

#include <QtWidgets/qwidget.h>

class QHBoxLayout;
class QSpacerItem;
class IPersonalWidget;
class IBoardWidget;
class QLabel;

class IPlayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IPlayWidget(QWidget *parent = nullptr);

private:
    void init();

signals:

private:
    QHBoxLayout* m_pMainLayout;
    IPersonalWidget* m_pLeftPersonalWidget;
    QSpacerItem* m_pLeftHorizontalSpacer;
    QLabel* m_pVSLabel;
    QSpacerItem* m_pRightHorizontalSpacer;
    IPersonalWidget* m_pRightPersonalWidget;
};

#endif // IPLAYWIDGET_H
