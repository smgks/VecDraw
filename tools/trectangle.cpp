#include "trectangle.h"
#include "sceneinfo.h"
#include <QGraphicsSceneMouseEvent>

tRectangle::tRectangle()
{
    setText("rectangle");
}
void tRectangle::draw(QGraphicsScene *scene)
{
    rect->draw(scene);
}

void tRectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        rect = new fRect;
        QPointF *point = new QPointF;
        *point = event->scenePos();
        rect->addpoint(point);
        info::figurStack.push_back(rect);
    }
}
