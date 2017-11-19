#include "frect.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
fRect::fRect()
{
    pen = new QPen;
    brush = new QBrush;
    angle = 1;
    startPoint = new QPointF;
    startPoint = NULL;
    endPoint = new QPointF;
    endPoint = NULL;
}

void fRect::addpoint(QPointF *point)
{   if (!startPoint){
        startPoint = point;
        endPoint = point;
    }else{
        endPoint = point;
    }
}
void fRect::draw(QGraphicsScene *scene)
{
    QRectF *rect = new QRectF;
    rect->setCoords(startPoint->x() > endPoint->x() ? endPoint->x() : startPoint->x(),//тут возникни проблемы с отрисовкой квадрата
                    startPoint->y() > endPoint->y() ? endPoint->y() : startPoint->y(),//справа на лево , углы не округлялись
                    endPoint->x() < startPoint->x() ? startPoint->x() : endPoint->x(),
                    endPoint->y() < startPoint->y() ? startPoint->y() : endPoint->y());//поэтому отрисовка только слева на право
    QPainterPath *tempPath = new QPainterPath;
    tempPath->addRoundRect(*rect,angle);
    scene->addPolygon(tempPath->toFillPolygon(),*pen,*brush);
}
void fRect::setPen(QPen p)
{
    *pen = p;
}
void fRect::setBrush(QBrush b)
{
    *brush = b;
}
void fRect::setAngle(int a)
{
    angle = a;
}
