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
    bar->addWidget(widget);
    widget->setLayout(lay);
    lay->addWidget(del);
    connect(del,SIGNAL(clicked(bool)),this,SLOT(delitems()));
}
void tSelection::delitems()
{
    for (int i = 0; i < items.length(); ++i) {
        lScene->removeItem(items[i]);
    }
    lScene->update();
}
