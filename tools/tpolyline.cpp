#include "tpolyline.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tPolyline::tPolyline()
{
    setText("polyline");
    pen = new QPen;
}

void tPolyline::draw(QGraphicsScene *scene)
{
    Polyline->draw(scene);

}

void tPolyline::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
        info::figurStack.at(info::figurStack.length()-1);
    }
}
void tPolyline::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        Polyline = new fPolyline;
        QPointF *point = new QPointF;
        *point = event->buttonDownScenePos(Qt::LeftButton);
        Polyline->addpoint(point);
        Polyline->setPen(*pen);
        info::figurStack.push_back(Polyline);
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
