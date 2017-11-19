#ifndef FRECT_H
#define FRECT_H

#include "abstractfigure.h"

class fRect : public abstractFigure
{
public:
    explicit fRect();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
    void setPen(QPen p);
    void setBrush(QBrush b);
    void setAngle(int a);
private:
    QPointF *startPoint,*endPoint;
    QPen *pen;
    QBrush *brush;
    int angle;
};

#endif // FRECT_H
