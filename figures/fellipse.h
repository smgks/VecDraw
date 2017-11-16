#ifndef FELLIPSE_H
#define FELLIPSE_H

#include "abstractfigure.h"

class fEllipse : public abstractFigure
{
public:
    explicit fEllipse();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
private:
    QPointF *startPoint,*endPoint;
};

#endif // FELLIPSE_H
