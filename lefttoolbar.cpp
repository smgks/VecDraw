#include "lefttoolbar.h"

#include "sceneinfo.h"

abstractTool *info::tool;
QVector<abstractFigure*> info::figurStack;

LeftToolBar::LeftToolBar(TopToolBar *Bar)
{
    setStyleSheet("background-color: grey");
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
    dropStyle();
    Polyline->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}
void LeftToolBar::RectangleClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tRectangle;
    dropStyle();
    Rectangle->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}
void LeftToolBar::EllipseClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tEllipse;
    dropStyle();
    Ellipse->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}
void LeftToolBar::LineClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tLine;
    dropStyle();
    Line->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}
void LeftToolBar::MagnifierClick(){
    TopBar->clear();
    TopBar->hide();
    info::tool = new tMagnifier(scalebox);
    dropStyle();
    Magnifier->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}
void LeftToolBar::dropStyle(){
    Magnifier->setStyleSheet("background-color: silver");
    Line->setStyleSheet("background-color: silver");
    Ellipse->setStyleSheet("background-color: silver");
    Rectangle->setStyleSheet("background-color: silver");
    Polyline->setStyleSheet("background-color: silver");
    Polyline->setStyleSheet("background-color: silver");
}
void LeftToolBar::scaleChanged(){
    info::globalScale->setScale(qreal(scalebox->value()),qreal(scalebox->value()));
    emit changeScale();
}
