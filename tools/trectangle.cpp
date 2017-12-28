#include "trectangle.h"
#include "sceneinfo.h"
#include <QGraphicsSceneMouseEvent>

tRectangle::tRectangle()
{

    rect = NULL;
    setText("rectangle");

}
void tRectangle::draw(QGraphicsScene *scene)
{
    if (rect){
        scene->removeItem(rect);
        scene->addItem(rect);
    }
}

void tRectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF temppoint;
        temppoint = event->scenePos();
        rect->addPoint(temppoint);
    }
}
void tRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        info::URstActs.clearActs();
        info::URstActs.addAct();

        rect = new fRect;
        rect->setAngle(info::angle);
        rect->setPen(info::pen);
        rect->setBrush(info::brush);
        QPointF temppoint;
        temppoint = event->scenePos();
        rect->setPos(temppoint);
        rect->addPoint(temppoint);
        info::vecItems.append(rect);
    }
}
void tRectangle::setbar(TopToolBar *bar){
    fRect tempEl;
    for (int i = 0; i < tempEl.getParams().length(); i++) {
        bar->addWidget(tempEl.getParams()[i]);
    }
}
