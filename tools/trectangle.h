#ifndef TRECTANGLE_H
#define TRECTANGLE_H

#include "tools/abstracttool.h"
#include "figures/frect.h"
class tRectangle : public abstractTool
{
public:
    explicit tRectangle();
    void draw(QGraphicsScene *scene);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setbar(TopToolBar *bar);
private:
    fRect *rect;
    QWidget *barWidget;

    QHBoxLayout *mainlay;
    QVBoxLayout *layPenR;
    QLabel *penRl;
    QSpinBox *penRvaul;
    QVBoxLayout *layPenC;
    QLabel *penCl;
    QPushButton *penColor;
    QVBoxLayout *layPenB;
    QLabel *brushCl;
    QPushButton *brushColor;
    QVBoxLayout *layBrushS;
    QLabel *brushSl;
    QVBoxLayout *anglelay;
    QLabel *anglelb;
    QSpinBox *angleBox;
    QComboBox *combobox;
    //////////////
    QPen *pen;
    QBrush *brush;
    int angle;
public slots:
    void setBrushstyle(int a);
    void setPenR();
    void setPenC();
    void setBrushC();
};

#endif // TRECTANGLE_H
