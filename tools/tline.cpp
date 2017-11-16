#include "tline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tLine::tLine()
{
    setText("line");
}
void tLine::draw(QGraphicsScene *scene)
{
    line->draw(scene);
}

void tLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        line = new fLine;
        QPointF *point = new QPointF;
        *point = event->scenePos();
        line->addpoint(point);
        info::figurStack.push_back(line);
    }
}
