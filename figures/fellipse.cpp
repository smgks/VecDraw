#include "fellipse.h"

fEllipse::fEllipse() : abstractfigure()
{
//    penC = new penColor;

//    penR = new penRadius;

//    brushC = new brushColor;

//    brushS = new brushStyle;

    newF = 1;
}

QRectF fEllipse::boundingRect() const
{
    return QRectF(QPointF(0 < endPoint.x()-startPoint.x() ? 0-5 : endPoint.x()-startPoint.x()-5,
                          0 < endPoint.y()-startPoint.y() ? 0-5 : endPoint.y()-startPoint.y()-5),
                           QSizeF(abs(endPoint.x()-startPoint.x())+10,
                                  abs(endPoint.y()-startPoint.y())+10));
}

void fEllipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(0,0,endPoint.x()-startPoint.x(),endPoint.y()-startPoint.y());
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

void fEllipse::setPen(QPen p)
{
    pen = p;
}
void fEllipse::setBrush(QBrush b)
{
    brush = b;
}

const QVector<QWidget *> fEllipse::getParams()
{
    QVector<QWidget*> w;
    penColor *penC = new penColor;
    penRadius *penR = new penRadius;
    brushColor *brushC = new brushColor;
    brushStyle *brushS = new brushStyle;
       w.append(penC);
       w.append(penR);
       w.append(brushC);
       w.append(brushS);
    return w;
}

void fEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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
        QPointF tempPoint ;
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

bool fEllipse::rigthA(QGraphicsSceneMouseEvent *event){
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
bool fEllipse::leftA(QGraphicsSceneMouseEvent *event){
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

void fEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event){

}

QPen fEllipse::getPen()
{return pen;}
QBrush fEllipse::getBrush()
{return brush;}

QVector<QPointF> fEllipse::getCords()
{
    QVector<QPointF> c;
    c.append(startPoint);
    c.append(endPoint);
    return c;
}
void fEllipse::addPoint(QPointF point)
{
    if (newF){
            startPoint = point;
            endPoint = point;
            newF=0;
        }else{
            endPoint = point;
    }
}
