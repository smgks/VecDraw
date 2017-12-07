#include "frect.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>

fRect::fRect(QObject *parent) : QObject(parent) , abstractfigure()
{
    angle = 1;
    startPoint = NULL;
    endPoint = NULL;
    setAcceptHoverEvents(1);
}

QRectF fRect::boundingRect() const
{
    return QRectF(QPointF(0 < endPoint->x()-startPoint->x() ? 0 : endPoint->x()-startPoint->x(),
           0 < endPoint->y()-startPoint->y() ? 0 : endPoint->y()-startPoint->y()),
            QSizeF(abs(endPoint->x()-startPoint->x()),
                   abs(endPoint->y()-startPoint->y())));
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
        temppen.setWidth(1/info::globalScale->getScaleX());
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint->x()-startPoint->x()-5/info::globalScale->getScaleX(),
                                         endPoint->y()-startPoint->y()-5/info::globalScale->getScaleX()),
                                 QSizeF(5/info::globalScale->getScaleX(),
                                        5/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(0,0),QSizeF(5/info::globalScale->getScaleX(),
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

void fRect::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void fRect::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
if(isSelected() && (info::tool->text()=="cursor")){
    if(rigthA(event)){
        QPointF *tempPoint = new QPointF;
        tempPoint->setX(endPoint->x()+(event->scenePos().x() - event->lastScenePos().x()));
        tempPoint->setY(endPoint->y()+(event->scenePos().y() - event->lastScenePos().y()));
        addPoint(tempPoint);
        update();
        scene()->update();
    }
    else{
    if(leftA(event)){
        QPointF *tempPoint = new QPointF;
        tempPoint->setX(endPoint->x()-(event->scenePos().x() - event->lastScenePos().x()));
        tempPoint->setY(endPoint->y()-(event->scenePos().y() - event->lastScenePos().y()));
        setPos(pos().x() + (event->scenePos().x() - event->lastScenePos().x()),
               pos().y() + (event->scenePos().y() - event->lastScenePos().y()));
        addPoint(tempPoint);
        update();
        scene()->update();
    }

        else{
    setPos(pos().x() + (event->scenePos().x() - event->lastScenePos().x()),
           pos().y() + (event->scenePos().y() - event->lastScenePos().y()));
    update();
        }
    }
}
}

bool fRect::rigthA(QGraphicsSceneMouseEvent *event){
    bool res = 1;
    if (endPoint->x()-startPoint->x() > 0){
        res = res*(event->scenePos().x()-pos().x() >= endPoint->x()-startPoint->x()-10/info::globalScale->getScaleX());
    }
    if (endPoint->y()-startPoint->y() > 0){
        res = res*(event->scenePos().y()-pos().y() >= endPoint->y()-startPoint->y()-10/info::globalScale->getScaleY());
    }
    if (endPoint->x()-startPoint->x() < 0){
        res = res*(event->scenePos().x()-pos().x() <= endPoint->x()-startPoint->x()+10/info::globalScale->getScaleX());
    }
    if (endPoint->y()-startPoint->y() < 0){
        res = res*(event->scenePos().y()-pos().y() <= endPoint->y()-startPoint->y()+10/info::globalScale->getScaleY());
    }
    return res;
}
bool fRect::leftA(QGraphicsSceneMouseEvent *event){
    bool res = 1;
    if (endPoint->x()-startPoint->x() > 0){
        res = res*(event->scenePos().x()-pos().x()<=10/info::globalScale->getScaleX());
    }
    if (endPoint->y()-startPoint->y() > 0){
        res = res*(event->scenePos().y()-pos().y()<=10/info::globalScale->getScaleY());
    }
    if (endPoint->x()-startPoint->x() < 0){
        res = res*(event->scenePos().x()-pos().x()>=-10/info::globalScale->getScaleX());
    }
    if (endPoint->y()-startPoint->y() < 0){
        res = res*(event->scenePos().y()-pos().y()>=-10/info::globalScale->getScaleY());
    }
    return res;
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
