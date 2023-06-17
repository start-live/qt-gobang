#ifndef IPERSONALWIDGET_H
#define IPERSONALWIDGET_H

#include <QtWidgets/qwidget.h>

class QHBoxLayout;
class QVBoxLayout;
class QLabel;

enum IInfoDerection
{
    LeftToRight,
    RightToLeft
};

class IPersonalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IPersonalWidget(QWidget *parent = nullptr);

    void setDirection(const IInfoDerection& derection);

    void setImage(const QPixmap& pixmap);
    void setName(const QString& name);

private:
    void init();

signals:

private:
    QHBoxLayout* m_pMainLayout;
    QLabel* m_pImageLabel;
    QVBoxLayout* m_pInfoLayout;
    QLabel* m_pNameLabel;
    QLabel* m_pTimeLabel;
    IInfoDerection m_derection;
};

#endif // IPERSONALWIDGET_H
