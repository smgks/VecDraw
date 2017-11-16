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
private:
    QVector<QPointF> points;
};

#endif // FPOLYLINE_H
