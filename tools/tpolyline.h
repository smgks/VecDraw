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
};

#endif // TPOLYLINE_H
