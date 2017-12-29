#include "mainscene.h"

#include "sceneinfo.h"

#include <QGraphicsScale>

QVector<abstractfigure*> info::vecItems;

QPen info::pen;
QBrush info::brush;
int info::angle;
info::URst info::URstActs;
MainScene::MainScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

void MainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    info::tool->draw(this);
    info::tool->mouseMoveEvent(event);

    QGraphicsScene::mouseMoveEvent(event);
    update();
    emit mClick();
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

    if (info::tool->text() != "magnifier"){
        QGraphicsScene::mousePressEvent(event);
    }
    update();
    info::URstActs.addAct();
    info::URstActs.clearReActs();    
    emit mClick();
}
