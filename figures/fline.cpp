#include "fline.h"

fLine::fLine()
{
    pen = new QPen;
    startPoint = new QPointF;
    endPoint = new QPointF;
    startPoint = NULL;
    endPoint = NULL;
}

void fLine::addpoint(QPointF *point)
{   if (!startPoint){
        startPoint = point;
        endPoint = point;
    }else{
        endPoint = point;
    }
}
void fLine::draw(QGraphicsScene *scene)
{
    QLine *tempLine = new QLine(startPoint->x(),startPoint->y(),endPoint->x(),endPoint->y());
    scene->addLine(*tempLine,*pen);
}
void fLine::setPen(QPen p)
{
    *pen = p;
}
