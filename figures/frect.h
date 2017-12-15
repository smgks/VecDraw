#ifndef FRECT_H
#define FRECT_H

#include "abstractfigure.h"
#include "sceneinfo.h"
#include <QGraphicsItem>
#include <QPainterPath>
#include <QPainter>
#include <QVector>

class fRect : public abstractfigure
{
    Q_OBJECT
public:
    explicit fRect();
    QRectF 	boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void setPen(QPen p);
    void setBrush(QBrush b);
    void setAngle(int a);
    void addPoint(QPointF point);
    QVector<QPointF> getCords();
    const QVector<QWidget*> getParams();
    QString getName(){return QString("rect");}
    QPen getPen();
    QBrush getBrush();
    int getAngle();

private:
    QPointF startPoint,endPoint;
    QPen pen;
    QBrush brush;
    int angle;
    bool newF;
//    penColor *penC;
//    penRadius *penR;
//    brushColor *brushC;
//    brushStyle *brushS;
//    rectA *angOfRect;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    bool leftA(QGraphicsSceneMouseEvent *event);
    bool rigthA(QGraphicsSceneMouseEvent *event);
};

#endif // FRECT_H
