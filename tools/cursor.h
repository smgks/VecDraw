#ifndef CURSOR_H
#define CURSOR_H

#include "abstracttool.h"

class tcursor : public abstractTool
{
    Q_OBJECT
public:
    explicit tcursor();
    virtual void draw(QGraphicsScene *scene);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void setbar(TopToolBar *bar);
private:
    QGraphicsScene *lScene;

    QWidget *widget;
    QHBoxLayout *lay;
    QVBoxLayout *Vlay;

    QPushButton *upB;
    QPushButton *downB;

    QPushButton *del;
    TopToolBar *parentBar;
    QVector<QWidget*> paramVec;
    QVector<QAction*> acts;
    void fromSelToBar();
private slots:
    void delitems();
    void downBPress();
    void upBPress();

};

#endif // CURSOR_H
