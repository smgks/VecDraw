#include "tpolyline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>



tPolyline::tPolyline()
{
    setText("polyline");
    Polyline = NULL;
}

void tPolyline::draw(QGraphicsScene *scene)
{
    if (Polyline){
        scene->removeItem(Polyline);
        scene->addItem(Polyline);
    }
}

void tPolyline::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->buttons() == Qt::LeftButton){
        QPointF temppoint;
        temppoint = event->scenePos();
        Polyline->addPoint(temppoint);
    }
}
void tPolyline::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        Polyline= new fPolyline;
        Polyline->setPen(info::pen);
        QPointF temppoint;
        temppoint = event->scenePos();
        Polyline->addPoint(temppoint);
        Polyline->setPos(temppoint);
        info::vecItems.append(Polyline);
    }
}
void tPolyline::setbar(TopToolBar *bar){
    fPolyline tempEl;
    for (int i = 0; i < tempEl.getParams().length(); i++) {
        bar->addWidget(tempEl.getParams()[i]);
    }
}

