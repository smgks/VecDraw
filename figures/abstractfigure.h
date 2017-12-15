#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QGraphicsObject>
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include "toolbtns/abstractTB.h"
#include "toolbtns/brushcolor.h"
#include "toolbtns/brushstyle.h"
#include "toolbtns/pencolor.h"
#include "toolbtns/penradius.h"
#include "toolbtns/recta.h"

class abstractfigure : public QGraphicsObject
{
    Q_OBJECT
public:
    abstractfigure();
    virtual const QVector<QWidget*> getParams()=0;

    virtual void addPoint(QPointF point)=0;
    virtual void setPen(QPen p){}
    virtual void setBrush(QBrush b){}
    virtual void setAngle(int a){}
    virtual QVector<QPointF> getCords(){}
    virtual QString getName()=0;
    virtual QPen getPen(){
        return QPen();
    }
    virtual QBrush getBrush(){
        return QBrush();
    }
    virtual int getAngle(){
        return 0;
    }
};

#endif // ABSTRACTFIGURE_H
