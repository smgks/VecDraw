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
    void setFigureNull(){line=NULL;}
private:
    fLine *line;

};

#endif // TLINE_H
