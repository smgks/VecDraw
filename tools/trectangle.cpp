#include "trectangle.h"
#include "sceneinfo.h"
#include <QGraphicsSceneMouseEvent>

tRectangle::tRectangle()
{
    pen = new QPen;
    brush = new QBrush;
    rect = NULL;
    setText("rectangle");
    angle = 1;
}
void tRectangle::draw(QGraphicsScene *scene)
{
    if (rect){
        scene->removeItem(rect);
        scene->addItem(rect);
    }
}

void tRectangle::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        rect->addPoint(temppoint);
    }
}
void tRectangle::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        rect = new fRect;
        rect->setAngle(angle);
        rect->setPen(*pen);
        rect->setBrush(*brush);
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        rect->setPos(*temppoint);
        rect->addPoint(temppoint);
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
    angleBox->setMinimum(1);
    angleBox->setValue(1);
    angleBox->setMaximum(100);
    anglelay->addWidget(anglelb);
    anglelay->addWidget(angleBox);
    brushSl = new QLabel;
    brushSl->setText("Brush Style");
    layBrushS = new QVBoxLayout;
    combobox = new QComboBox;
    combobox->addItem("NoBrush");
    combobox->addItem("SolidPattern");
    combobox->addItem("Dense1Pattern");
    combobox->addItem("Dense2Pattern");
    combobox->addItem("Dense3Pattern");
    combobox->addItem("Dense4Pattern");
    combobox->addItem("Dense5Pattern");
    combobox->addItem("Dense6Pattern");
    combobox->addItem("Dense7Pattern");
    combobox->addItem("HorPattern");
    combobox->addItem("VerPattern");
    combobox->addItem("CrossPattern");
    combobox->addItem("BDiagPattern");
    combobox->addItem("FDiagPattern");
    combobox->addItem("DiagCrossPattern");
    combobox->addItem("LinearGradientPattern");
    combobox->addItem("ConicalGradientPattern");
    combobox->addItem("RadialGradientPattern");
    layBrushS->addWidget(brushSl);
    layBrushS->addWidget(combobox);
    mainlay->addLayout(layBrushS);
    mainlay->addLayout(anglelay);

    layBrushS = new QVBoxLayout;
    barWidget->setLayout(mainlay);
    bar->addWidget(barWidget);

    connect(penRvaul,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
    connect(penColor,SIGNAL(clicked(bool)),this,SLOT(setPenC()));
    connect(brushColor,SIGNAL(clicked(bool)),this,SLOT(setBrushC()));
    connect(angleBox,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(setBrushstyle(int)));
}
void tRectangle::setPenR()
{
    pen->setWidth(penRvaul->value());
    angle = angleBox->value();
}
void tRectangle::setPenC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    pen->setColor(temp);

}
void tRectangle::setBrushC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    brush->setColor(temp);
}

void tRectangle::setBrushstyle(int a)
{
    brush->setStyle(Qt::BrushStyle(a));
}
