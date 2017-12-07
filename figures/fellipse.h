#ifndef FELLIPSE_H
#define FELLIPSE_H

#include "abstractfigure.h"

#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QObject>

class fEllipse : public abstractfigure , public QObject
{
public:
    explicit fEllipse(QObject *parent = Q_NULLPTR);
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void setBrush(QBrush b);
    void addPoint(QPointF *point);
private:
    QPointF *startPoint,*endPoint;
    QPen pen;
    QBrush brush;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FELLIPSE_H
