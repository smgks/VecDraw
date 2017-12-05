#ifndef SCENEINFO_H
#define SCENEINFO_H

#include "tools/abstracttool.h"
//#include "figures/abstractfigure.h"
#include <QObject>

namespace info {
    class gScale
    {
    public:
        explicit gScale(){

        }
        qreal getScaleX(){
            return xScale;
        }
        qreal getScaleY(){
            return yScale;
        }
        qreal getLX(){
            return xLast;
        }
        qreal getLY(){
            return yLast;
        }
        void setScale(qreal a,qreal b){
            xLast = xScale;
            yLast = yScale;
            xScale = a/100;
            yScale = b/100;
        }
    private:
        qreal xLast;
        qreal yLast;
        qreal xScale;
        qreal yScale;
    };
    extern abstractTool *tool;
    extern gScale *globalScale;
}
#endif // SCENEINFO_H
