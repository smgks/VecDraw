#ifndef FRECT_H
#define FRECT_H

#include "abstractfigure.h"

class fRect : public abstractFigure
{
public:
    explicit fRect();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
private:
    QPointF *startPoint,*endPoint;
};

#endif // FRECT_H
