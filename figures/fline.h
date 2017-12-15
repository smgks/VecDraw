#ifndef FLINE_H
#define FLINE_H

#include "abstractfigure.h"
#include "sceneinfo.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>

class fLine : public abstractfigure
{
    Q_OBJECT
public:
    explicit fLine();
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void addPoint(QPointF point);
    const QVector<QWidget*> getParams();
    QVector<QPointF> getCords();
    QString getName(){return QString("line");}
    QPen getPen();

private:
    QPointF startPoint,endPoint;
    QPen pen;
    bool newF;
//    penColor *penC;
//    penRadius *penR;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FLINE_H
