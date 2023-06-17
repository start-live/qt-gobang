#ifndef IBOARDWIDGET_H
#define IBOARDWIDGET_H

#include <QtWidgets/qwidget.h>

class IBoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IBoardWidget(QWidget *parent = nullptr);

protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;


signals:
    void posClicked(const QPoint& pos);

private:
    qint32 m_x;
    qint32 m_y;
    qint32 m_space;
    qint32 m_width;
    qint32 m_height;
    qint32 m_pieceWidth;
    bool isb;
};

#endif // IBOARDWIDGET_H
