#include "tline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tLine::tLine()
{
    setText("line");
}
void tLine::draw(QGraphicsScene *scene)
{
    line->draw(scene);
}

void tLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        line = new fLine;
        QPointF *point = new QPointF;
        *point = event->scenePos();
        line->addpoint(point);
        info::figurStack.push_back(line);
    }
}
void tLine::setbar(TopToolBar *bar){
    mainlay = new QHBoxLayout;

    barWidget = new QWidget;

    layPenR = new QVBoxLayout;
    penRl = new QLabel;
    penRl->setText("pen radius");
    penRvaul = new QSpinBox;
    penRvaul->setMinimum(1);
    penRvaul->setMaximum(100);
    layPenR->addWidget(penRl);
    layPenR->addWidget(penRvaul);
    mainlay->addLayout(layPenR);
    QWidget *temp = new QWidget;
    temp->setFixedSize(2,60);
    temp->setStyleSheet("background-color: black");
    mainlay->addWidget(temp);
    layPenC = new QVBoxLayout;
    penCl = new QLabel;
    penCl->setText("pen color");
    penColor = new QPushButton;
    layPenC->addWidget(penCl);
    layPenC->addWidget(penColor);
    mainlay->addLayout(layPenC);

    barWidget->setLayout(mainlay);
    bar->addWidget(barWidget);
}
