#include "cursor.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
tcursor::tcursor()
{
    lScene = Q_NULLPTR;
    setText("cursor");
}
void tcursor::draw(QGraphicsScene *scene){
    lScene = scene;
}
void tcursor::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (lScene){
        QGraphicsItem *temp = Q_NULLPTR;
        temp = lScene->itemAt(event->scenePos(),QTransform());
        if (temp){
            temp->setFlag(temp->ItemIsSelectable,1);
            temp->setSelected(1);
            lScene->update();
        }
        else {
            for (int i = 0; i < lScene->items().length(); ++i) {
                lScene->items()[i]->setSelected(0);
            }
        }
    }
}
void tcursor::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
//    if (lScene){
//        QGraphicsItem *temp = Q_NULLPTR;
//        temp = lScene->itemAt(event->scenePos(),QTransform());
//        if (temp){
//            temp->setFlag(temp->ItemIsSelectable,1);
//            temp->setSelected(1);
//            lScene->update();
//        }
//        else {
//            for (int i = 0; i < lScene->items().length(); ++i) {
//                lScene->items()[i]->setSelected(0);
//            }
//        }
//    }
}
void tcursor::setbar(TopToolBar *bar){

    widget = new QWidget;
    lay = new QHBoxLayout;
    del = new QPushButton("Del");

    Vlay = new QVBoxLayout;
    upB = new QPushButton;
    downB = new QPushButton;

    bar->addWidget(widget);
    widget->setLayout(lay);
    lay->addWidget(del);
    lay->addLayout(Vlay);
    Vlay->addWidget(upB);
    upB->setText("up");
    downB->setText("down");
    Vlay->addWidget(downB);
    connect(del,SIGNAL(clicked(bool)),this,SLOT(delitems()));
    connect(upB,SIGNAL(clicked(bool)),this,SLOT(upBPress()));
    connect(downB,SIGNAL(clicked(bool)),this,SLOT(downBPress()));
}

void tcursor::delitems()
{
    for (int i = 0; i < lScene->items().length(); ++i) {
        if(lScene->items()[i]->isSelected()){
            lScene->removeItem(lScene->items()[i]);
            i--;
        }
    }
    lScene->update();
}

void tcursor::downBPress()
{
    if (lScene){
        for (int i = 0; i < lScene->items().length(); ++i) {
            lScene->items()[i]->setZValue(lScene->items()[i]->zValue()-1);
        }
        lScene->update();
    }
}
void tcursor::upBPress()
{
    if (lScene){
        for (int i = 0; i < lScene->items().length(); ++i) {
            lScene->items()[i]->setZValue(lScene->items()[i]->zValue()+1);
        }
        lScene->update();
    }
}
