#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QGraphicsItem>

#include "sceneinfo.h"
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

class abstractfigure : public QGraphicsItem
{
public:
    abstractfigure();
    //virtual void setSelection(int s)=0;
    virtual void addPoint(QPointF *point)=0;
};

#endif // ABSTRACTFIGURE_H
