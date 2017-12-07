#ifndef FRECT_H
#define FRECT_H

#include "abstractfigure.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QVector>
#include <QObject>

class fRect : public abstractfigure , public QObject
{
public:
    explicit fRect(QObject *parent = Q_NULLPTR);
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void setPen(QPen p);
    void setBrush(QBrush b);
    void setAngle(int a);
    void addPoint(QPointF *point);
private:
    QPointF *startPoint,*endPoint;
    QPen pen;
    QBrush brush;
    int angle;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FRECT_H
