#include "lefttoolbar.h"

#include "sceneinfo.h"

abstractTool *info::tool;
QVector<abstractFigure*> info::figurStack;

LeftToolBar::LeftToolBar(QToolBar *Bar)
{
    TopBar = Bar;
    btn = new tPolyline;
    btn1 = new tRectangle;
    btn2 = new tEllipse;
    btn3 = new tLine;
    btn4 = new tMagnifier(scalebox);
    scalebox = new QSpinBox;

    scalebox->setMinimum(1);
    scalebox->setValue(100);
    scalebox->setMaximum(10000);

    setContextMenuPolicy(Qt::PreventContextMenu);
    setMovable(1);
    setMinimumSize(50,50);
    addWidget(scalebox);
    addWidget(btn);
    addWidget(btn1);
    addWidget(btn2);
    addWidget(btn3);
    addWidget(btn4);
    TopBar->hide();
    ////////
    connect(scalebox,SIGNAL(valueChanged(int)),this,SLOT(scaleChanged()));
    connect(btn,SIGNAL(clicked()),this,SLOT(btnClick()));
    connect(btn1,SIGNAL(clicked()),this,SLOT(btn1Click()));
    connect(btn2,SIGNAL(clicked(bool)),this,SLOT(btn2Click()));
    connect(btn3,SIGNAL(clicked(bool)),this,SLOT(btn3Click()));
    connect(btn4,SIGNAL(clicked(bool)),this,SLOT(btn4Click()));
    ////////

    emit btn->click();
}
void LeftToolBar::setScaleBox(){
    scalebox->setValue(info::globalScale->getScaleX());
}

void LeftToolBar::btnClick(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tPolyline;
    btn->setFocus();
}
void LeftToolBar::btn1Click(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tRectangle;
    btn1->setFocus();
}
void LeftToolBar::btn2Click(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tEllipse;
}
void LeftToolBar::btn3Click(){
    TopBar->clear();
    TopBar->show();
    info::tool = new tLine;
    btn3->setFocus();
}
void LeftToolBar::btn4Click(){
    TopBar->clear();
    TopBar->hide();
    info::tool = new tMagnifier(scalebox);
    btn4->setFocus();
}
void LeftToolBar::scaleChanged(){
    info::globalScale->setScale(qreal(scalebox->value()),qreal(scalebox->value()));
    emit changeScale();
}
