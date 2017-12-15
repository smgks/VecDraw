#ifndef FPOLYLINE_H
#define FPOLYLINE_H

#include "abstractfigure.h"
#include "sceneinfo.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QVector>

class fPolyline : public abstractfigure
{
    Q_OBJECT
public:
    explicit fPolyline();
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void addPoint(QPointF point);
    const QVector<QWidget*> getParams();
    QVector<QPointF> getCords();
    QString getName(){return QString("polyline");}
    QPen getPen();

private:
    QVector<QPointF> points;
    QPen pen;
    int maxX,maxY;
    int minX,minY;
//    penColor *penC;
//    penRadius *penR;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // FPOLYLINE_H
