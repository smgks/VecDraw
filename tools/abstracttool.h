#ifndef ABSTRACTTOOL_H
#define ABSTRACTTOOL_H

#include <QPushButton>
#include <QGraphicsScene>

class abstractTool : public QPushButton
{
public:
    explicit abstractTool();
    virtual void draw(QGraphicsScene *scene) = 0;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;

};

#endif // ABSTRACTTOOL_H
