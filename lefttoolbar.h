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
#include "tools/tselection.h"
#include "tools/cursor.h"

class LeftToolBar : public QToolBar
{
    Q_OBJECT
public:
    explicit LeftToolBar(TopToolBar *Bar);
signals:
    void changeScale();
private:
    tPolyline *Polyline;
    tRectangle *Rectangle;
    tEllipse *Ellipse;
    tLine *Line;
    tMagnifier *Magnifier;
    tSelection *Selection;
    tcursor *cursotool;

    TopToolBar *TopBar;
    QSpinBox *scalebox;
    void dropStyle();
private slots:
    void PolylineClick();
    void RectangleClick();
    void EllipseClick();
    void LineClick();
    void MagnifierClick();
    void SelectionClick();
    void cursotoolClick();
    void scaleChanged();
    void setScaleBox();
};

#endif // LEFTTOOLBAR_H
