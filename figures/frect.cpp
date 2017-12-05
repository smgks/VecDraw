#include "frect.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>

#include "sceneinfo.h"
#include "tools/tselection.h"

fRect::fRect(QObject *parent) : QObject(parent) , abstractfigure()
{
    angle = 1;
    startPoint = NULL;
    endPoint = NULL;
    sel=0;
}

QRectF fRect::boundingRect() const
{
    return QRectF(0,
                  0,
                  endPoint->x()-startPoint->x(),
                  endPoint->y()-startPoint->y());
}

void fRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF *tempP = new QPointF(0 > endPoint->x()-startPoint->x() ? endPoint->x()-startPoint->x() : 0,
                                 0 > endPoint->y()-startPoint->y() ? endPoint->y()-startPoint->y() : 0
                                 );
    QRectF *tempR = new QRectF(*tempP,QSize(abs(endPoint->x()-startPoint->x()),abs(endPoint->y()-startPoint->y())));
    painter->drawRoundedRect(*tempR,angle,angle);
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

void fRect::setAngle(int a)
{
    angle = a;
}

void fRect::setPen(QPen p)
{
    pen = p;
}

void fRect::setBrush(QBrush b)
{
    brush = b;
}

void fRect::setSelection(int s)
{
    sel = s;
}

void fRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    sel=1;
}
void fRect::addPoint(QPointF *point)
{
    if (!startPoint){
            startPoint = point;
            endPoint = point;
        }else{
            endPoint = point;
    }
}
