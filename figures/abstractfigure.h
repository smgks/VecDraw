#ifndef ABSTRACTFIGURE_H
#define ABSTRACTFIGURE_H

#include <QObject>
#include <QGraphicsScene>
class abstractFigure
{
public:
    explicit abstractFigure();
    virtual void addpoint(QPointF *point) = 0;
    virtual void draw(QGraphicsScene *scene) = 0;
    virtual void setPen(QPen p){}
};

#endif // ABSTRACTFIGURE_H
