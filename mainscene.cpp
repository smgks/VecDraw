#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>
#include <QMatrix>

MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{
    //ReDraw();
}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->mouseMoveEvent(event);
    info::tool->draw(this);
    update();
}
void MainScene::ReDraw(){

}
void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->mousePressEvent(event);
    info::tool->draw(this);
}
