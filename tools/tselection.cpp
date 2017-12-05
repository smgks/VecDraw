#include "tselection.h"

#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsItem>
#include <QGraphicsEffect>

#include "figures/abstractfigure.h"

tSelection::tSelection()
{
    lpos = new QPointF;
    lScene = NULL;
    setText("selection");
}

void tSelection::draw(QGraphicsScene *scene)
{
    lScene = scene;
}

void tSelection::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        if(lScene){
            for (int i = 0; i < items.length(); ++i) {
                items[i]->setFlag(items[i]->ItemIsSelectable,0);
                items[i]->setSelected(0);
            }
            lScene->update();
            QPointF *qwe = new QPointF(lpos->x() < event->scenePos().x() ? lpos->x() : event->scenePos().x(),
                                       lpos->y() < event->scenePos().y() ? lpos->y() : event->scenePos().y());
            QRectF *tr = new QRectF(*qwe,QSizeF(abs(event->scenePos().x()-lpos->x()),abs(event->scenePos().y()-lpos->y())));
            items = lScene->items(*tr).toVector();
            for (int i = 0; i < items.length(); ++i) {
                items[i]->setFlag(items[i]->ItemIsSelectable,1);
                items[i]->setSelected(1);
            }
        }
    }
}
void tSelection::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        *lpos = event->scenePos();
        if(lScene){
            QGraphicsItem *temp = Q_NULLPTR;
            temp = lScene->itemAt(*lpos,QTransform());
            for (int i = 0; i < items.length(); ++i) {
                items[i]->setFlag(items[i]->ItemIsSelectable,0);
                items[i]->setSelected(0);
            }
            items.clear();
            if (temp){
                temp->setFlag(temp->ItemIsSelectable,1);
                temp->setSelected(1);
                items.append(temp);
            }
            lScene->update();
        }
    }
}
void tSelection::setbar(TopToolBar *bar)
{
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

void tSelection::delitems()
{
    for (int i = 0; i < items.length(); ++i) {
        lScene->removeItem(items[i]);
    }
    lScene->update();
}

void tSelection::downBPress()
{
    if (lScene){
        for (int i = 0; i < items.length(); ++i) {
            items[i]->setZValue(items[i]->zValue()-1);
        }
        lScene->update();
    }
}
void tSelection::upBPress()
{
    if (lScene){
        for (int i = 0; i < items.length(); ++i) {
            items[i]->setZValue(items[i]->zValue()-1);
        }
        lScene->update();
    }
}
