#ifndef TLINE_H
#define TLINE_H

#include "abstracttool.h"
#include "figures/fline.h"

class tLine : public abstractTool
{
public:
    explicit tLine();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    fLine *line;
    QWidget *barWidget;

    QHBoxLayout *mainlay;
    QVBoxLayout *layPenR;
    QLabel *penRl;
    QSpinBox *penRvaul;
    QVBoxLayout *layPenC;
    QLabel *penCl;
    QPushButton *penColor;
    //////////////
    QPen *pen;
public slots:
    void setPenR();
    void setPenC();
};

#endif // TLINE_H
