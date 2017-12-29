#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "tools/abstracttool.h"
#include "tools/tpolyline.h"
#include "tools/trectangle.h"

#include "toolbtns/pencolor.h"
#include "toolbtns/penradius.h"
#include "toolbtns/brushcolor.h"
#include "toolbtns/brushstyle.h"
#include "toolbtns/recta.h"

class MainScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainScene(QObject *parent = 0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ReDraw();
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
signals:
    void mClick();
public slots:
};

#endif // MAINSCENE_H
