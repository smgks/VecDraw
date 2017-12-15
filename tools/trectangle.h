#ifndef TRECTANGLE_H
#define TRECTANGLE_H

#include "tools/abstracttool.h"
#include "figures/frect.h"

class tRectangle : public abstractTool
{
public:
    explicit tRectangle();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    fRect *rect;

};

#endif // TRECTANGLE_H
