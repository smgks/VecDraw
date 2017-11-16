#include "trectangle.h"
#include "sceneinfo.h"
#include <QGraphicsSceneMouseEvent>

tRectangle::tRectangle()
{
    setText("rectangle");
}
void tRectangle::draw(QGraphicsScene *scene)
{
    angle = 0;
    rect->draw(scene);
}

void tRectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *point = new QPointF;
        *point = event->scenePos();
        info::figurStack.at(info::figurStack.length()-1)->addpoint(point);
    }
}
void tRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        rect = new fRect;
        QPointF *point = new QPointF;
        *point = event->scenePos();
        rect->setAngle(angle);
        rect->setBrush(brush);
        rect->setPen(pen);
        rect->addpoint(point);
        info::figurStack.push_back(rect);
    }
}
void tRectangle::setbar(TopToolBar *bar){
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

    layPenB = new QVBoxLayout;
    brushCl = new QLabel;
    brushCl->setText("brush color");
    brushColor = new QPushButton;
    layPenB->addWidget(brushCl);
    layPenB->addWidget(brushColor);
    mainlay->addLayout(layPenB);

    anglelay = new QVBoxLayout;
    anglelb = new QLabel;
    anglelb->setText("rect angle radius");
    angleBox = new QSpinBox;
    angleBox->setMinimum(0);
    angleBox->setValue(0);
    angleBox->setMaximum(100);
    anglelay->addWidget(anglelb);
    anglelay->addWidget(angleBox);
    mainlay->addLayout(anglelay);

    layBrushS = new QVBoxLayout;
    barWidget->setLayout(mainlay);
    bar->addWidget(barWidget);

    connect(penRvaul,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
    connect(penColor,SIGNAL(clicked(bool)),this,SLOT(setPenC()));
    connect(brushColor,SIGNAL(clicked(bool)),this,SLOT(setBrushC()));
    connect(angleBox,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
}
void tRectangle::setPenR()
{
    pen.setWidth(penRvaul->value());
    angle = angleBox->value();
}
void tRectangle::setPenC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    pen.setColor(temp);

}
void tRectangle::setBrushC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    brush.setColor(temp);
    brush.setStyle(Qt::SolidPattern);
}

