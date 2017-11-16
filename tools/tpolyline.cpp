#include "tpolyline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tPolyline::tPolyline()
{
    setText("polyline");
}

void tPolyline::draw(QGraphicsScene *scene)
{
    Polyline->draw(scene);

}

void tPolyline::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tPolyline::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        Polyline = new fPolyline;
        QPointF *point = new QPointF;
        *point = event->buttonDownScenePos(Qt::LeftButton);
        Polyline->addpoint(point);
        info::figurStack.push_back(Polyline);
    }
}
