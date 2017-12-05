#include "fellipse.h"

fEllipse::fEllipse(QObject *parent) : QObject(parent), abstractfigure()
{
    startPoint = NULL;
    endPoint = NULL;
}

QRectF fEllipse::boundingRect() const
{
    return QRectF(0,0,endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y());
}

void fEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(0,0,endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y());
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

void fEllipse::setPen(QPen p)
{
    pen = p;
}
void fEllipse::setBrush(QBrush b)
{
    brush = b;
}

void fEllipse::setSelection(int s)
{
}

void fEllipse::addPoint(QPointF *point)
{
    if (!startPoint){
            startPoint = point;
            endPoint = point;
        }else{
            endPoint = point;
    }
}
