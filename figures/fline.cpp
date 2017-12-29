#include "fline.h"

fLine::fLine() : abstractfigure()
{

    newF = 1;

}

QRectF fLine::boundingRect() const
{
    return QRectF(QPointF(0 < endPoint.x()-startPoint.x() ? 0-5 : endPoint.x()-startPoint.x()-5,
           0 < endPoint.y()-startPoint.y() ? 0-5 : endPoint.y()-startPoint.y()-5),
            QSizeF(abs(endPoint.x()-startPoint.x())+10,
                   abs(endPoint.y()-startPoint.y())+10));
    //return QRectF(0,0,abs(endPoint.x()-startPoint.x()),abs(endPoint.y()-startPoint.y()));
}

const QVector<QWidget *> fLine::getParams()
{
    QVector<QWidget*> w;
    penColor *penC = new penColor;
       w.append(penC);
    penRadius *penR = new penRadius;
       w.append(penR);

    return w;
}

void fLine::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->drawLine(0,0,endPoint.x()-startPoint.x(),endPoint.y()-startPoint.y());
    if(isSelected()){
        QPen temppen;
        temppen.setColor(Qt::green);
        temppen.setWidth(1/info::globalScale->getScaleX());
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(endPoint.x()-startPoint.x()-5/info::globalScale->getScaleX(),
                                         endPoint.y()-startPoint.y()-5/info::globalScale->getScaleX()),
                                 QSizeF(5/info::globalScale->getScaleX(),
                                        5/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(0,
                                         0),
                                 QSizeF(5/info::globalScale->getScaleX(),
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

void fLine::setPen(QPen p)
{
    pen = p;
}

void fLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void fLine::mousePressEvent(QGraphicsSceneMouseEvent *event){
update();
}

bool fLine::rigthA(QGraphicsSceneMouseEvent *event){
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
bool fLine::leftA(QGraphicsSceneMouseEvent *event){
    bool res = 1;
    if (endPoint.x()-startPoint.x() > 0){
        res = res*(event->scenePos().x()-pos().x()<=10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() > 0){
        res = res*(event->scenePos().y()-pos().y()<=10/info::globalScale->getScaleY());
    }
    if (endPoint.x()-startPoint.x() < 0){
        res = res*(event->scenePos().x()-pos().x()>=-10/info::globalScale->getScaleX());
    }
    if (endPoint.y()-startPoint.y() < 0){
        res = res*(event->scenePos().y()-pos().y()>=-10/info::globalScale->getScaleY());
    }
    return res;
}
QVector<QPointF> fLine::getCords()
{
    QVector<QPointF> c;
    c.append(startPoint);
    c.append(endPoint);
    return c;
}

QPen fLine::getPen()
{return pen;}
void fLine::addPoint(QPointF point)
{
    if (newF){
            startPoint = point;
            endPoint = point;
            newF=0;
        }else{
            endPoint = point;
    }
}
