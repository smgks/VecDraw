#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "tools/abstracttool.h"
#include "tools/tpolyline.h"
#include "tools/trectangle.h"

class MainScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainScene(QObject *parent = 0);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void ReDraw();
signals:

public slots:

};

#endif // MAINSCENE_H
