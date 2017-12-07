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

void fLine::setPen(QPen p)
{
    pen = p;
}

void fLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void fLine::mousePressEvent(QGraphicsSceneMouseEvent *event){

}

bool fLine::rigthA(QGraphicsSceneMouseEvent *event){
    return ((event->scenePos().x()-pos().x()>=endPoint->x()-startPoint->x()-10/info::globalScale->getScaleX()) &&        //правый якорь
            (event->scenePos().y()-pos().y()>=endPoint->y()-startPoint->y()-10/info::globalScale->getScaleX())
            || (event->scenePos().x()-pos().x()>endPoint->x()-startPoint->x()-10/info::globalScale->getScaleX())
            || (event->scenePos().y()-pos().y()>endPoint->y()-startPoint->y()-10/info::globalScale->getScaleY()));}
bool fLine::leftA(QGraphicsSceneMouseEvent *event){
    return (((event->scenePos().x()-pos().x()<=10/info::globalScale->getScaleX()) &&          //левый якорь
             (event->scenePos().y()-pos().y()<=10/info::globalScale->getScaleX())
             ) || (event->scenePos().x()-pos().x()<10/info::globalScale->getScaleX())
                   || (event->scenePos().y()-pos().y()<10/info::globalScale->getScaleY()));
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
