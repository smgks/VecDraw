#ifndef LEFTTOOLBAR_H
#define LEFTTOOLBAR_H

#include <QToolBar>
#include <QPushButton>
#include <QSpinBox>

#include "tools/tpolyline.h"
#include "tools/trectangle.h"
#include "tools/tellipse.h"
#include "tools/tline.h"
#include "tools/tmagnifier.h"

class LeftToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit LeftToolBar(QToolBar *Bar);
signals:
    void changeScale();
private:
    tPolyline *Polyline;
    tRectangle *Rectangle;
    tEllipse *Ellipse;
    tLine *Line;
    tMagnifier *Magnifier;
    QToolBar *TopBar;  
    QSpinBox *scalebox;
private slots:
    void PolylineClick();
    void RectangleClick();
    void EllipseClick();
    void LineClick();
    void MagnifierClick();
    void scaleChanged();
    void setScaleBox();
};

#endif // LEFTTOOLBAR_H
