#include "tmagnifier.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tMagnifier::tMagnifier(QSpinBox *spinBox)
{
    ScaleSpin = spinBox;
    setText("magnifier");
}
void tMagnifier::draw(QGraphicsScene *scene)
{
    scene->update();

}

void tMagnifier::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}
void tMagnifier::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        ScaleSpin->setValue(ScaleSpin->value()*2);
    }
    if (event->buttons() == Qt::RightButton){
        ScaleSpin->setValue(ScaleSpin->value()/2);
    }
}
void tMagnifier::setbar(TopToolBar *bar){
    //PASS
}
