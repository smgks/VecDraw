#ifndef PENCOLOR_H
#define PENCOLOR_H

#include "abstractTB.h"

class penColor : public abstractTB
{
    Q_OBJECT
public:
    explicit penColor();
    ~penColor();
private:
    QVBoxLayout *lay;
    QLabel *label;
    QPushButton *button;

private slots:
    void click();

};

#endif // PENCOLOR_H
