#ifndef FELLIPSE_H
#define FELLIPSE_H

#include "abstractfigure.h"
#include "sceneinfo.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>

class fEllipse : public abstractfigure
{
    Q_OBJECT
public:
    explicit fEllipse();
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR) ;
    void setPen(QPen p);
    void setBrush(QBrush b);
    void addPoint(QPointF point);
    const QVector<QWidget*> getParams();
    QVector<QPointF> getCords();
    QString getName(){return QString("ellipse");}
    QPen getPen();
    QBrush getBrush();

private:
    QPointF startPoint,endPoint;
    QPen pen;
    QBrush brush;
    bool newF;
//    penColor *penC;
//    penRadius *penR;
//    brushColor *brushC;
//    brushStyle *brushS;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FELLIPSE_H
