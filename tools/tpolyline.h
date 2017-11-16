#ifndef TPOLYLINE_H
#define TPOLYLINE_H

#include "abstracttool.h"
#include "figures/fpolyline.h"

class tPolyline : public abstractTool
{
public:
    explicit tPolyline();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    fPolyline *Polyline;
    QWidget *barWidget;

    QHBoxLayout *mainlay;
    QVBoxLayout *layPenR;
    QLabel *penRl;
    QSpinBox *penRvaul;
    QVBoxLayout *layPenC;
    QLabel *penCl;
    QPushButton *penColor;
    //////////////
    QPen *pen;
};

#endif // TPOLYLINE_H
