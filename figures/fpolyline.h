#ifndef FPOLYLINE_H
#define FPOLYLINE_H

#include "abstractfigure.h"

#include <QObject>
#include <QVector>
class fPolyline : public abstractFigure
{
public:
    explicit fPolyline();

    void addpoint(QPointF *point);
    void draw(QGraphicsScene *scene);
    void setPen(QPen *pen);
private:
    QVector<QPointF> points;
    QPen *pen;
};

#endif // FPOLYLINE_H
