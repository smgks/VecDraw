#include "fellipse.h"

fEllipse::fEllipse()
{
    startPoint = new QPointF;
    endPoint = new QPointF;
    startPoint = NULL;
    endPoint = NULL;
}

void fEllipse::addpoint(QPointF *point)
{   if (!startPoint){
        startPoint = point;
        endPoint = point;
    }else{
        endPoint = point;
    }
}
void fEllipse::draw(QGraphicsScene *scene)
{
    QRectF *rect = new QRectF;
    rect->setCoords(startPoint->x() > endPoint->x() ? endPoint->x() : startPoint->x(),
                    startPoint->y() > endPoint->y() ? endPoint->y() : startPoint->y(),
                    endPoint->x() < startPoint->x() ? startPoint->x() : endPoint->x(),
                    endPoint->y() < startPoint->y() ? startPoint->y() : endPoint->y());
    QPainterPath *tempPath = new QPainterPath;
    tempPath->addEllipse(*rect);
    scene->addPath(*tempPath);
}
