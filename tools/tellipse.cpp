#include "tellipse.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tEllipse::tEllipse()
{
    setText("ellipse");
}
void tEllipse::draw(QGraphicsScene *scene)
{
    ellipse->draw(scene);
}

void tEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        ellipse = new fEllipse;
        QPointF *point = new QPointF;
        *point = event->scenePos();
        ellipse->addpoint(point);
        info::figurStack.push_back(ellipse);
    }
}
