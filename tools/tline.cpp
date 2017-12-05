#include "tline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tLine::tLine()
{
    pen = new QPen;
    line = NULL;
    setText("line");
}
void tLine::draw(QGraphicsScene *scene)
{
    if (line){
        scene->removeItem(line);
        scene->addItem(line);
    }
}

void tLine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        line->addPoint(temppoint);
    }
}
void tLine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        line = new fLine;
        line->setPen(*pen);
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        line->setPos(*temppoint);
        line->addPoint(temppoint);
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

    connect(penRvaul,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
    connect(penColor,SIGNAL(clicked(bool)),this,SLOT(setPenC()));
}
void tLine::setPenR()
{
    pen->setWidth(penRvaul->value());
}
void tLine::setPenC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    pen->setColor(temp);
}
