#ifndef TSELECTION_H
#define TSELECTION_H

#include "abstracttool.h"

class tSelection : public abstractTool
{
    Q_OBJECT
public:
    explicit tSelection();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    QPointF *lpos;
    QRectF *rect;
    QGraphicsScene *lScene;

    QVector<QGraphicsItem*> items;

    QWidget *widget;
    QHBoxLayout *lay;
    QPushButton *del;
private slots:
    void delitems();
};

#endif // TSELECTION_H
