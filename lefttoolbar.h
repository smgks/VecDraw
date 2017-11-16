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
    tPolyline *btn;
    tRectangle *btn1;
    tEllipse *btn2;
    tLine *btn3;
    tMagnifier *btn4;
    QToolBar *TopBar;  
    QSpinBox *scalebox;
private slots:
    void btnClick();
    void btn1Click();
    void btn2Click();
    void btn3Click();
    void btn4Click();
    void scaleChanged();
    void setScaleBox();
};

#endif // LEFTTOOLBAR_H
