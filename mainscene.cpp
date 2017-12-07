#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>

MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{
    addRect(QRectF(0,0,0,0),QPen(Qt::color0));
}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->draw(this);
    info::tool->mouseMoveEvent(event);
    update();
    QGraphicsScene::mouseMoveEvent(event);
}
void MainScene::ReDraw(){

}

void MainScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

}

void MainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->draw(this);
    info::tool->mousePressEvent(event);
    update();
    if (info::tool->text() != "magnifier"){
        QGraphicsScene::mousePressEvent(event);
    }
}
