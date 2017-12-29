#include "lefttoolbar.h"

#include "sceneinfo.h"

abstractTool *info::tool;
//QVector<QGraphicsItem*> info::figurStack;

LeftToolBar::LeftToolBar(TopToolBar *Bar)
{
    setStyleSheet("background-color: grey");
    TopBar = Bar;
    Polyline = new tPolyline;
    Rectangle = new tRectangle;
    Ellipse = new tEllipse;
    cursotool = new tcursor;
    Line = new tLine;
    Magnifier = new tMagnifier(scalebox);
    Selection = new tSelection;
    scalebox = new QSpinBox;
    scalebox->setMinimum(1);
    scalebox->setValue(100);
    scalebox->setMaximum(10000);

    setContextMenuPolicy(Qt::PreventContextMenu);
    setMovable(1);
    setMinimumSize(50,50);
    addWidget(scalebox);
    scalebox->setMinimumSize(20,40);
    addWidget(Polyline);
    addWidget(Rectangle);
    addWidget(Ellipse);
    addWidget(Line);
    addWidget(Magnifier);
    addWidget(Selection);
    addWidget(cursotool);
    TopBar->hide();
    ////////
    connect(scalebox,SIGNAL(valueChanged(int)),this,SLOT(scaleChanged()));
    connect(Polyline,SIGNAL(clicked()),this,SLOT(PolylineClick()));
    connect(Rectangle,SIGNAL(clicked()),this,SLOT(RectangleClick()));
    connect(Ellipse,SIGNAL(clicked(bool)),this,SLOT(EllipseClick()));
    connect(Line,SIGNAL(clicked(bool)),this,SLOT(LineClick()));
    connect(Magnifier,SIGNAL(clicked(bool)),this,SLOT(MagnifierClick()));
    connect(Selection,SIGNAL(clicked(bool)),this,SLOT(SelectionClick()));
    connect(cursotool,SIGNAL(clicked(bool)),this,SLOT(cursotoolClick()));
    ////////

    emit Polyline->click();
}

void LeftToolBar::drop(){
    abstractTool *temp = info::tool;
    TopBar->clear();
    TopBar->show();
    info::tool = new tPolyline;
    info::tool = temp;
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
void LeftToolBar::cursotoolClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tcursor;
    dropStyle();
    cursotool->setStyleSheet("background-color: yellow");
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

void LeftToolBar::SelectionClick()
{
    TopBar->clear();
    TopBar->show();
    info::tool = new tSelection;
    dropStyle();
    Selection->setStyleSheet("background-color: yellow");
    info::tool->setbar(TopBar);
}

void LeftToolBar::dropStyle(){
    Magnifier->setStyleSheet("background-color: silver");
    Line->setStyleSheet("background-color: silver");
    Ellipse->setStyleSheet("background-color: silver");
    Rectangle->setStyleSheet("background-color: silver");
    Polyline->setStyleSheet("background-color: silver");
    Selection->setStyleSheet("background-color: silver");
    cursotool->setStyleSheet("background-color: silver");
}

void LeftToolBar::scaleChanged(){
    info::globalScale->setScale(qreal(scalebox->value()),qreal(scalebox->value()));
    scalebox->setEnabled(0);
    scalebox->setEnabled(1);
    scalebox->setFocusPolicy(Qt::NoFocus);
    emit changeScale();
}
