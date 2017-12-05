#include "fline.h"

fLine::fLine(QObject *parent) : QObject(parent), abstractfigure()
{
    startPoint = NULL;
    endPoint = NULL;
}

QRectF fLine::boundingRect() const
{
    return QRectF(0,0,endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y());
}

void fLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->drawLine(0,0,endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y());
    if(isSelected()){
        QPen temppen;
        temppen.setColor(Qt::green);
        painter->setPen(temppen);
        painter->drawEllipse(QPointF(endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y()),5,5);
        painter->drawEllipse(QPointF(0,0),5,5);
        temppen.setColor(Qt::red);
        painter->setPen(temppen);
        painter->drawEllipse(QPointF(endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y()),3,3);
        painter->drawEllipse(QPointF(0,0),3,3);
    }
}

void fLine::setPen(QPen p)
{
    pen = p;
}

void fLine::setSelection(int s)
{
}

void fLine::addPoint(QPointF *point)
{
    if (!startPoint){
            startPoint = point;
            endPoint = point;
        }else{
            endPoint = point;
    }
}
