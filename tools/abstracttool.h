#ifndef ABSTRACTTOOL_H
#define ABSTRACTTOOL_H
#include "toptoolbar.h"

#include <QPushButton>
#include <QGraphicsScene>
#include <QToolBar>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class abstractTool : public QPushButton
{
    Q_OBJECT
public:
    explicit abstractTool();
    virtual void draw(QGraphicsScene *scene) = 0;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) = 0;
    virtual void setbar(TopToolBar *bar) = 0;
public slots:
    virtual void setBrushstyle(int a){}
    virtual void setPenR(){}
    virtual void setPenC(){}
    virtual void setBrushC(){}
};

#endif // ABSTRACTTOOL_H
