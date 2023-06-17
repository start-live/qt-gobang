#ifndef IMAINWIDGETWIDGET_H
#define IMAINWIDGETWIDGET_H

#include <QWidget>

class IMainWidgetWidget : public QWidget
{
    Q_OBJECT

public:
    IMainWidgetWidget(QWidget *parent = nullptr);
    ~IMainWidgetWidget();
};
#endif // IMAINWIDGETWIDGET_H
