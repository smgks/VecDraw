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
    void setFigureNull(){fromSelToBar();}
private:
    QPointF *lpos;
    QRectF *rect;
    QGraphicsScene *lScene;

    QVector<QGraphicsItem*> items;

    QWidget *widget;
    QHBoxLayout *lay;
    QVBoxLayout *Vlay;

    QPushButton *upB;
    QPushButton *downB;

    QPushButton *del;

    TopToolBar *parentBar;
    QVector<QWidget*> paramVec;
    QVector<QAction*> acts;
    void fromSelToBar();
private slots:
    void delitems();
    void downBPress();
    void upBPress();

};

#endif // TSELECTION_H
