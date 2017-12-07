#include "fpolyline.h"

fPolyline::fPolyline(QObject *parent) : QObject(parent), abstractfigure()
{
    minX = 0;
    minY = 0;
    maxX = 0;
    maxY = 0;
}

QRectF fPolyline::boundingRect() const
{
        return QRectF(QPointF(minX-points[0].x(),minY-points[0].y()),QSizeF(abs(maxX-minX),abs(maxY-minY)));
}

void fPolyline::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen);
    for (int i = 1; i < points.length()-1; ++i) {
        QPointF f(points[i].x()-points[0].x(),points[i].y()-points[0].y());
        QPointF s(points[i+1].x()-points[0].x(),points[i+1].y()-points[0].y());
        painter->drawLine(f,s);
    }
    if(isSelected()){
        QPen temppen;
        temppen.setWidth(1/info::globalScale->getScaleX());
        temppen.setColor(Qt::green);
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(minX-points[0].x(),
                                 minY-points[0].y()),
                QSizeF(5/info::globalScale->getScaleX(),
                       5/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(maxX-points[0].x()-5/info::globalScale->getScaleX(),
                                 maxY-points[0].y()-5/info::globalScale->getScaleX()),
                QSizeF(5/info::globalScale->getScaleX(),
                       5/info::globalScale->getScaleX())));
        temppen.setColor(Qt::red);
        painter->setPen(temppen);
        painter->drawRect(QRectF(QPointF(minX-points[0].x()+1/info::globalScale->getScaleX(),
                                 minY-points[0].y()+1/info::globalScale->getScaleX()),
                QSizeF(3/info::globalScale->getScaleX(),3/info::globalScale->getScaleX())));
        painter->drawRect(QRectF(QPointF(maxX-points[0].x()-4/info::globalScale->getScaleX(),
                                 maxY-points[0].y()-4/info::globalScale->getScaleX()),
                QSizeF(3/info::globalScale->getScaleX(),
                       3/info::globalScale->getScaleX())));
    }
}

void fPolyline::setPen(QPen p)
{
    pen = p;
}

void fPolyline::addPoint(QPointF *point)
{
    if (point->x()>maxX){
        maxX=point->x();
    }
    if (point->y()>maxY){
        maxY=point->y();
    }
    if (point->x()<minX){
        minX=point->x();
    }
    if (point->y()<minY){
        minY=point->y();
    }
        points.push_back(*point);
    if (0==maxX){
           maxX=point->x();
    }
    if (0==maxY){
           maxY=point->y();
    }
    if (0==minX){
           minX=point->x();
    }
    if (0==minY){
           minY=point->y();
    }
}

void fPolyline::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(isSelected() and (info::tool->text()=="cursor")){
        setPos(pos().x() + (event->scenePos().x() - event->lastScenePos().x()),
               pos().y() + (event->scenePos().y() - event->lastScenePos().y()));
    }
}

void fPolyline::mousePressEvent(QGraphicsSceneMouseEvent *event){

}
