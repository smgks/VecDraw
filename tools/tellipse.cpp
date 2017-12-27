#include "tellipse.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tEllipse::tEllipse()
{
    ellipse = 0;
    setText("ellipse");
}
void tEllipse::draw(QGraphicsScene *scene)
{
    if (ellipse){
        scene->removeItem(ellipse);
        scene->addItem(ellipse);
    }
}

void tEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF temppoint;
        temppoint = event->scenePos();
        ellipse->addPoint(temppoint);
    }
}
void tEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        ellipse = new fEllipse;
        ellipse->setPen(info::pen);
        ellipse->setBrush(info::brush);
        QPointF temppoint;
        temppoint = event->scenePos();
        ellipse->setPos(temppoint);
        ellipse->addPoint(temppoint);
        info::vecItems.append(ellipse);

    }
}
void tEllipse::setbar(TopToolBar *bar){
    fEllipse temp;
    for (int i = 0; i < temp.getParams().length(); i++) {
        bar->addWidget(temp.getParams()[i]);
    }
}
