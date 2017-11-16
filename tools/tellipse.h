#ifndef TELLIPSE_H
#define TELLIPSE_H

#include "abstracttool.h"
#include "figures/fellipse.h"

class tEllipse : public abstractTool
{
public:
    explicit tEllipse();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    fEllipse *ellipse;
};

#endif // TELLIPSE_H
