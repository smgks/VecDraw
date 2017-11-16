#include "lefttoolbar.h"

#include "sceneinfo.h"

abstractTool *info::tool;
QVector<abstractFigure*> info::figurStack;

LeftToolBar::LeftToolBar(QToolBar *Bar)
{
    TopBar = Bar;
    Polyline = new tPolyline;
    Rectangle = new tRectangle;
    Ellipse = new tEllipse;
    Line = new tLine;
    Magnifier = new tMagnifier(scalebox);
    scalebox = new QSpinBox;

    scalebox->setMinimum(1);
    scalebox->setValue(100);
    scalebox->setMaximum(10000);

    setContextMenuPolicy(Qt::PreventContextMenu);
    setMovable(1);
    setMinimumSize(50,50);
    addWidget(scalebox);
    addWidget(Polyline);
    addWidget(Rectangle);
    addWidget(Ellipse);
    addWidget(Line);
    addWidget(Magnifier);
    TopBar->hide();
    ////////
    connect(scalebox,SIGNAL(valueChanged(int)),this,SLOT(scaleChanged()));
    connect(Polyline,SIGNAL(clicked()),this,SLOT(PolylineClick()));
    connect(Rectangle,SIGNAL(clicked()),this,SLOT(RectangleClick()));
    connect(Ellipse,SIGNAL(clicked(bool)),this,SLOT(EllipseClick()));
    connect(Line,SIGNAL(clicked(bool)),this,SLOT(LineClick()));
    connect(Magnifier,SIGNAL(clicked(bool)),this,SLOT(MagnifierClick()));
    ////////

    emit Polyline->click();
}
void LeftToolBar::setScaleBox(){
    scalebox->setValue(info::globalScale->getScaleX());
}

void LeftToolBar::PolylineClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tPolyline;
    Polyline->setFocus();

}
void LeftToolBar::RectangleClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tRectangle;
    Rectangle->setFocus();
}
void LeftToolBar::EllipseClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tEllipse;
}
void LeftToolBar::LineClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tLine;
    Line->setFocus();
}
void LeftToolBar::MagnifierClick(){
    TopBar->clear();
    TopBar->hide();
    info::tool = new tMagnifier(scalebox);
    Magnifier->setFocus();
}
void LeftToolBar::scaleChanged(){
    info::globalScale->setScale(qreal(scalebox->value()),qreal(scalebox->value()));
    emit changeScale();
}
