#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>
#include <QMatrix>

MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{
}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        info::tool->mouseMoveEvent(event);
        update();
        clear();
        addRect(0,0,0,0);
        ReDraw();
}
void MainScene::ReDraw(){
    for (int i = 0; i < info::figurStack.length(); ++i) {
        info::figurStack.at(i)->draw(this);
    }
}
void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
            info::tool->mousePressEvent(event);
}
