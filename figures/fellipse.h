#ifndef FELLIPSE_H
#define FELLIPSE_H

#include "abstractfigure.h"

class fEllipse : public abstractFigure
{
public:
    explicit fEllipse();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
    void setPen(QPen p);
    void setBrush(QBrush b);
private:
    QPointF *startPoint,*endPoint;
    QPen *pen;
    QBrush *brush;
};

#endif // FELLIPSE_H
