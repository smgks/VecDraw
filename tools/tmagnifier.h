#ifndef TMAGNIFIER_H
#define TMAGNIFIER_H

#include "abstracttool.h"

class tMagnifier : public abstractTool
{

public:
    explicit tMagnifier(QSpinBox *spinBox);
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    QSpinBox *ScaleSpin;
};

#endif // TMAGNIFIER_H
