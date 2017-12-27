#include "tselection.h"

#include <QGraphicsSceneMouseEvent>
#include <QTransform>
#include <QGraphicsItem>
#include <QGraphicsEffect>
#include <iostream>
#include "sceneinfo.h"
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
                items[i]->setFlag(items[i]->ItemIsSelectable,1);
                items[i]->setSelected(0);
            }

            lScene->update();

            QPointF qwe(lpos->x() < event->scenePos().x() ? lpos->x() : event->scenePos().x(),
                        lpos->y() < event->scenePos().y() ? lpos->y() : event->scenePos().y());

            QRectF tr(qwe,QSizeF(abs(event->scenePos().x()-lpos->x()),abs(event->scenePos().y()-lpos->y())));

            items = lScene->items(tr).toVector();

            for (int i = 0; i < items.length(); ++i) {
                items[i]->setFlag(items[i]->ItemIsSelectable,1);
                items[i]->setSelected(1);
            }
        }
        fromSelToBar();
    }
}

void tSelection::fromSelToBar(){
    //////////////////////
    QVector<QString> strVec;
    for (int var = paramVec.length()-1; var >= 0; --var) {
        delete paramVec[var];
    }
    paramVec.clear();
    for (int i = 0; i < info::vecItems.length(); ++i) {
        QVector<QWidget*> tempV = info::vecItems[i]->getParams();
        if(info::vecItems[i]->isSelected()){
            for (int j = 0; j < tempV.length(); ++j) {
                if (!(strVec.contains(tempV[j]->accessibleName()))){
                    strVec.append(tempV[j]->accessibleName());
                    paramVec.append(tempV[j]);
                }else{
                    delete tempV[j];
                }
            }
        }
    }
    for (int i = 0; i < info::vecItems.length(); ++i) {
        QVector<QWidget*> tempV = info::vecItems[i]->getParams();
        if(info::vecItems[i]->isSelected()){
            QVector<QString> strTempV;
            for (int j = tempV.length()-1; j >= 0; --j){
                strTempV.append(tempV[j]->accessibleName());
                delete tempV[j];
            }
            for (int j = 0; j < strVec.length(); ++j){
                if(!(strTempV.contains(strVec[j]))){
                    strVec.remove(j);
                    tempV.remove(j);
                    delete paramVec[j];
                    paramVec.remove(j);
                    j--;
                }
            }
            strTempV.clear();
        }
    }

    for (int var = 0; var < acts.length(); ++var) {
        parentBar->removeAction(acts[var]);
    }
    acts.clear();

    for (int var = 0; var < paramVec.length(); ++var) {
        QAction* MyAction = parentBar -> addWidget (paramVec[var]) ;
        paramVec[var]->setVisible(1);
        acts.append(MyAction);
        parentBar->addAction(MyAction);
    }
    strVec.clear();
parentBar->update();
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
        fromSelToBar();
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
    parentBar = bar;
}

void tSelection::delitems()
{
    for (int i = 0; i < lScene->items().length(); ++i) {
        if(lScene->items()[i]->isSelected()){
            lScene->removeItem(lScene->items()[i]);
            info::vecItems.remove(i);
            i--;
        }
    }
    lScene->update();
}

void tSelection::downBPress()
{
    if (lScene){
        for (int i = 0; i < lScene->items().length(); ++i) {
            if(lScene->items()[i]->isSelected()){
                lScene->items()[i]->setZValue(lScene->items()[i]->zValue()-1);
            }
        }
        lScene->update();
    }
}
void tSelection::upBPress()
{
    if (lScene){
        for (int i = 0; i < lScene->items().length(); ++i) {
            if(lScene->items()[i]->isSelected()){
                lScene->items()[i]->setZValue(lScene->items()[i]->zValue()+1);
            }
        }
        lScene->update();
    }
}
