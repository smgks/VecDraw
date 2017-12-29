#include "tline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tLine::tLine()
{
    line = NULL;
    setText("line");
}
void tLine::draw(QGraphicsScene *scene)
{
    if (line){
        scene->removeItem(line);
        scene->addItem(line);
    }
}

void tLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF temppoint;
        temppoint = event->scenePos();
        line->addPoint(temppoint);
    }
}
void tLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
//        info::URstActs.clearReActs();
//        info::URstActs.addAct();

        line = new fLine;
        line->setPen(info::pen);
        QPointF temppoint;
        temppoint = event->scenePos();
        line->setPos(temppoint);
        line->addPoint(temppoint);
        info::vecItems.append(line);
    }
}
void tLine::setbar(TopToolBar *bar){

    fLine tempEl;
    for (int i = 0; i < tempEl.getParams().length(); i++) {
        bar->addWidget(tempEl.getParams()[i]);
    }
}

