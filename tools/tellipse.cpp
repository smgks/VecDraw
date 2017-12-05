#include "tellipse.h"
#include "sceneinfo.h"

#include <QGraphicsSceneMouseEvent>

tEllipse::tEllipse()
{
    pen = new QPen;
    brush = new QBrush;
    ellipse = NULL;
    setText("ellipse");
}
void tEllipse::draw(QGraphicsScene *scene)
{
    if (ellipse){
        scene->removeItem(ellipse);
        scene->addItem(ellipse);
    }
}

void tEllipse::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        ellipse->addPoint(temppoint);
    }
}
void tEllipse::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton){
        ellipse = new fEllipse;
        ellipse->setPen(*pen);
        ellipse->setBrush(*brush);
        QPointF *temppoint = new QPointF;
        *temppoint = event->scenePos();
        ellipse->setPos(*temppoint);
        ellipse->addPoint(temppoint);
    }
}
void tEllipse::setbar(TopToolBar *bar){
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

    layBrushS = new QVBoxLayout;
    brushSl = new QLabel;
    brushSl->setText("Brush Style");
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

    barWidget->setLayout(mainlay);

    bar->addWidget(barWidget);

    connect(penRvaul,SIGNAL(valueChanged(int)),this,SLOT(setPenR()));
    connect(penColor,SIGNAL(clicked(bool)),this,SLOT(setPenC()));
    connect(brushColor,SIGNAL(clicked(bool)),this,SLOT(setBrushC()));
    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(setBrushstyle(int)));
}
void tEllipse::setPenR()
{
    pen->setWidth(penRvaul->value());
}
void tEllipse::setPenC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    pen->setColor(temp);

}
void tEllipse::setBrushC()
{
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    brush->setColor(temp);
}
void tEllipse::setBrushstyle(int a)
{
    brush->setStyle(Qt::BrushStyle(a));
}
