#ifndef FPOLYLINE_H
#define FPOLYLINE_H

#include "abstractfigure.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QVector>
#include <QObject>

class fPolyline : public abstractfigure , public QObject
{
public:
    explicit fPolyline(QObject *parent = Q_NULLPTR);
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void addPoint(QPointF *point);
    void setSelection(int s);
private:
    QVector<QPointF> points;
    QPen pen;
    int maxX,maxY;
    int minX,minY;
};

#endif // FPOLYLINE_H
