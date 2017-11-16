#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>
#include <QMatrix>

MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{
    ReDraw();
}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->mouseMoveEvent(event);
    update();
    clear();
    ReDraw();
}
void MainScene::ReDraw(){
    addRect(this->sceneRect(),QPen(Qt::white),QBrush(Qt::white));
    for (int i = 0; i < info::figurStack.length(); ++i) {
        info::figurStack.at(i)->draw(this);
    }
}
void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
            info::tool->mousePressEvent(event);
}
