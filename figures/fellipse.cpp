﻿#include "fellipse.h"

fEllipse::fEllipse(QObject *parent) : QObject(parent), abstractfigure()
{
    startPoint = NULL;
    endPoint = NULL;
}

QRectF fEllipse::boundingRect() const
{
    return QRectF(0-2,0-2,abs(endPoint->x()-startPoint->x()+4),abs(endPoint->y()-startPoint->y())+4);
}

void fEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(0,0,endPoint->x()-startPoint->x(),endPoint->y()-startPoint->y());
    if(isSelected()){
        QPen temppen;
        temppen.setColor(Qt::green);
        temppen.setWidth(1/info::globalScale->getScaleX());
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint->x()-startPoint->x()-5/info::globalScale->getScaleX(),
                                         endPoint->y()-startPoint->y()-5/info::globalScale->getScaleX()),
                                 QSizeF(5/info::globalScale->getScaleX(),
                                        5/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(0,
                                         0),
                                 QSizeF(5/info::globalScale->getScaleX(),
                                        5/info::globalScale->getScaleX())));
        temppen.setColor(Qt::red);
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint->x()-startPoint->x()-4/info::globalScale->getScaleX(),
                                         endPoint->y()-startPoint->y()-4/info::globalScale->getScaleX()),
                                 QSizeF(3/info::globalScale->getScaleX(),
                                        3/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(0+1/info::globalScale->getScaleX(),
                                         0+1/info::globalScale->getScaleX()),
                                 QSizeF(3/info::globalScale->getScaleX(),
                                        3/info::globalScale->getScaleX())));
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


void fEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelected() && (info::tool->text()=="cursor")){
        if(rigthA(event) || leftA(event)){

        if(rigthA(event)){
            endPoint->setX(endPoint->x()+event->scenePos().x()-event->lastScenePos().x());
            endPoint->setY(endPoint->y()+event->scenePos().y()-event->lastScenePos().y());
            update();
        }
        if(leftA(event)){
            startPoint->setX(startPoint->x()+event->scenePos().x()-event->lastScenePos().x());
            startPoint->setY(startPoint->y()+event->scenePos().y()-event->lastScenePos().y());
            setPos(pos().x() + (event->scenePos().x() - event->lastScenePos().x()),
                   pos().y() + (event->scenePos().y() - event->lastScenePos().y()));
            update();
        }

           } else{
        setPos(pos().x() + (event->scenePos().x() - event->lastScenePos().x()),
               pos().y() + (event->scenePos().y() - event->lastScenePos().y()));
        update();
            }
        }
    }

bool fEllipse::rigthA(QGraphicsSceneMouseEvent *event){
    return ((event->scenePos().x()-pos().x()>=endPoint->x()-startPoint->x()-10/info::globalScale->getScaleX()) &&        //правый якорь
            (event->scenePos().y()-pos().y()>=endPoint->y()-startPoint->y()-10/info::globalScale->getScaleX())
            || (event->scenePos().x()-pos().x()>endPoint->x()-startPoint->x()-10/info::globalScale->getScaleX())
            || (event->scenePos().y()-pos().y()>endPoint->y()-startPoint->y()-10/info::globalScale->getScaleY()));}
bool fEllipse::leftA(QGraphicsSceneMouseEvent *event){
    return (((event->scenePos().x()-pos().x()<=10/info::globalScale->getScaleX()) &&          //левый якорь
             (event->scenePos().y()-pos().y()<=10/info::globalScale->getScaleX())
             ) || (event->scenePos().x()-pos().x()<10/info::globalScale->getScaleX())
                   || (event->scenePos().y()-pos().y()<10/info::globalScale->getScaleY()));
}

void fEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event){

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
