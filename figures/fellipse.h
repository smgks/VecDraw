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
    void setSelection(int s);
private:
    QPointF *startPoint,*endPoint;
    QPen pen;
    QBrush brush;
};

#endif // FELLIPSE_H
