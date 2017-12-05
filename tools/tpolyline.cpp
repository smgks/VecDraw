#include "tpolyline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tPolyline::tPolyline()
{
    setText("polyline");
    pen = new QPen;
    Polyline = NULL;
}

void tPolyline::draw(QGraphicsScene *scene)
{
    if (Polyline){
        scene->removeItem(Polyline);
        scene->addItem(Polyline);
    }
}

void tPolyline::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->buttons() == Qt::LeftButton){
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        Polyline->addPoint(temppoint);
    }
}
void tPolyline::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        Polyline= new fPolyline;
        Polyline->setPen(*pen);
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        Polyline->addPoint(temppoint);
        Polyline->setPos(*temppoint);
    }
}
void tPolyline::setbar(TopToolBar *bar){
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
void tPolyline::setPenR()
{
    pen->setWidth(penRvaul->value());
}
void tPolyline::setPenC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    pen->setColor(temp);

}
