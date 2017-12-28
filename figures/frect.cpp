#include "frect.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>

fRect::fRect() : abstractfigure()
{
    angle = 1;
    setAcceptHoverEvents(1);
    newF = 1;
//    penC = new penColor;
//    penR = new penRadius;
//    brushC = new brushColor;
//    brushS = new brushStyle;
//    angOfRect = new rectA;
}

QRectF fRect::boundingRect() const
{
    return QRectF(QPointF(0 < endPoint.x()-startPoint.x() ? 0-5 : endPoint.x()-startPoint.x()-5,
           0 < endPoint.y()-startPoint.y() ? 0-5 : endPoint.y()-startPoint.y()-5),
            QSizeF(abs(endPoint.x()-startPoint.x())+10,
                   abs(endPoint.y()-startPoint.y())+10));
}

void fRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    QPointF tempP(0 > endPoint.x()-startPoint.x() ? endPoint.x()-startPoint.x() : 0,
                                 0 > endPoint.y()-startPoint.y() ? endPoint.y()-startPoint.y() : 0
                                 );
    QRectF tempR(tempP,QSize(abs(endPoint.x()-startPoint.x()),abs(endPoint.y()-startPoint.y())));
    painter->drawRoundedRect(tempR,angle,angle);
    if(isSelected()){
        QPen temppen;
        temppen.setColor(Qt::green);
        temppen.setWidth(1/info::globalScale->getScaleX());
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint.x()-startPoint.x()-5/info::globalScale->getScaleX(),
                                         endPoint.y()-startPoint.y()-5/info::globalScale->getScaleX()),
                                 QSizeF(5/info::globalScale->getScaleX(),
                                        5/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(0,0),QSizeF(5/info::globalScale->getScaleX(),
                                                     5/info::globalScale->getScaleX())));
        temppen.setColor(Qt::red);
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint.x()-startPoint.x()-4/info::globalScale->getScaleX(),
                                         endPoint.y()-startPoint.y()-4/info::globalScale->getScaleX()),
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
        QPointF tempPoint;
        tempPoint.setX(endPoint.x()+(event->scenePos().x() - event->lastScenePos().x()));
        tempPoint.setY(endPoint.y()+(event->scenePos().y() - event->lastScenePos().y()));
        addPoint(tempPoint);
        update();
        scene()->update();
    }
    else{
    if(leftA(event)){
        QPointF tempPoint;
        tempPoint.setX(endPoint.x()-(event->scenePos().x() - event->lastScenePos().x()));
        tempPoint.setY(endPoint.y()-(event->scenePos().y() - event->lastScenePos().y()));
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
    if (endPoint.x()-startPoint.x() > 0){
        res = res*(event->scenePos().x()-pos().x() >= endPoint.x()-startPoint.x()-10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() > 0){
        res = res*(event->scenePos().y()-pos().y() >= endPoint.y()-startPoint.y()-10/info::globalScale->getScaleY());
    }
    if (endPoint.x()-startPoint.x() < 0){
        res = res*(event->scenePos().x()-pos().x() <= endPoint.x()-startPoint.x()+10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() < 0){
        res = res*(event->scenePos().y()-pos().y() <= endPoint.y()-startPoint.y()+10/info::globalScale->getScaleY());
    }
    return res;
}
QVector<QPointF> fRect::getCords()
{
    QVector<QPointF> c;
    c.append(startPoint);
    c.append(endPoint);
    return c;
}

QPen fRect::getPen(){return pen;}
QBrush fRect::getBrush(){return brush;}
int fRect::getAngle(){return angle;}

bool fRect::leftA(QGraphicsSceneMouseEvent *event){
    bool res = 1;
    if (endPoint.x()-startPoint.x() > 0){
        res = res  && (event->scenePos().x()-pos().x()<=10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() > 0){
        res = res && (event->scenePos().y()-pos().y()<=10/info::globalScale->getScaleY());
    }
    if (endPoint.x()-startPoint.x() < 0){
        res = res && (event->scenePos().x()-pos().x()>=-10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() < 0){
        res = res && (event->scenePos().y()-pos().y()>=-10/info::globalScale->getScaleY());
    }
    return res;
}

const QVector<QWidget *> fRect::getParams()
{
    QVector<QWidget*> w;
    penColor *penC = new penColor;
    penRadius *penR = new penRadius;
    brushColor *brushC = new brushColor;
    brushStyle *brushS = new brushStyle;
    rectA *angOfRect = new rectA;
       w.append(penC);
       w.append(penR);
       w.append(brushC);
       w.append(brushS);
       w.append(angOfRect);
    return w;
}

void fRect::addPoint(QPointF point)
{
    if (newF){
            startPoint = point;
            endPoint = point;
            newF=0;
        }else{
            endPoint = point;
    }
}
