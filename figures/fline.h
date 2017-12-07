#ifndef FLINE_H
#define FLINE_H

#include "abstractfigure.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QObject>

class fLine : public abstractfigure , public QObject
{
public:
    explicit fLine(QObject *parent = Q_NULLPTR);
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void addPoint(QPointF *point);
private:
    QPointF *startPoint,*endPoint;
    QPen pen;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FLINE_H
