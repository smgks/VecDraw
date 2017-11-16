#include "fpolyline.h"

fPolyline::fPolyline()
{
    pen = new QPen;
}


void fPolyline::addpoint(QPointF *point)
{
    points.push_back(*point);
}
void fPolyline::draw(QGraphicsScene *scene)
{
    for (int i = 1; i < points.length()-2; ++i) {
        scene->addLine(points.at(i).x(),points.at(i).y(),points.at(i+1).x(),points.at(i+1).y(),*pen);
    }
}
void fPolyline::setPen(QPen p)
{
    *pen = p;
}

