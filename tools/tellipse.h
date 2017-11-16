#ifndef TELLIPSE_H
#define TELLIPSE_H

#include "abstracttool.h"
#include "figures/fellipse.h"

class tEllipse : public abstractTool
{
public:
    explicit tEllipse();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    fEllipse *ellipse;

    QWidget *barWidget;

    QHBoxLayout *mainlay;
    QVBoxLayout *layPenR;
    QLabel *penRl;
    QSpinBox *penRvaul;
    QVBoxLayout *layPenC;
    QLabel *penCl;
    QPushButton *penColor;
    QVBoxLayout *layPenB;
    QLabel *brushCl;
    QPushButton *brushColor;
    QVBoxLayout *layBrushS;
    QLabel *brushSl;
    //////////////
    QPen *pen;
};
#endif // TELLIPSE_H
