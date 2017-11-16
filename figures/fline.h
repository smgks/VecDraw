#ifndef FLINE_H
#define FLINE_H

#include "abstractfigure.h"

class fLine : public abstractFigure
{
public:
    explicit fLine();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
private:
    QPointF *startPoint,*endPoint;
};

#endif // FLINE_H
