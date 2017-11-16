#ifndef FLINE_H
#define FLINE_H

#include "abstractfigure.h"

class fLine : public abstractFigure
{
public:
    explicit fLine();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
    void setPen(QPen p);
private:
    QPointF *startPoint,*endPoint;
    QPen *pen;
};

#endif // FLINE_H
