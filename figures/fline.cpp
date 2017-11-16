#include "fline.h"

fLine::fLine()
{
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
    scene->addLine(*tempLine);
}
