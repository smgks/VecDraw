#include "cursor.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <iostream>
#include "sceneinfo.h"
tcursor::tcursor()
{
    lScene = Q_NULLPTR;
    setText("cursor");
}
void tcursor::draw(QGraphicsScene *scene){
    lScene = scene;
}
void tcursor::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->buttons() == Qt::LeftButton){
//        info::URstActs.clearReActs();
//        info::URstActs.addAct();
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
            fromSelToBar();
        }
    }
}
void tcursor::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (event->buttons() == Qt::LeftButton){
        fromSelToBar();
    }
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
    parentBar = bar;
}

void tcursor::delitems()
{
    for (int i = 0; i < info::vecItems.length(); ++i) {
        if(info::vecItems[i]->isSelected()){
            lScene->removeItem(info::vecItems[i]);
            info::vecItems.remove(i);
            i--;
        }
    }
    lScene->update();
}
void tcursor::fromSelToBar(){
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

void tcursor::downBPress()
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
void tcursor::upBPress()
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
