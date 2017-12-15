#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>

QVector<abstractfigure*> info::vecItems;

QPen info::pen;
QBrush info::brush;
int info::angle;

MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{

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
