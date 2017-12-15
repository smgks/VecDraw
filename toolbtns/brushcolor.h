#ifndef BRUSHCOLOR_H
#define BRUSHCOLOR_H

#include "abstractTB.h"

class brushColor : public abstractTB
{
    Q_OBJECT
public:
    explicit brushColor();
    ~brushColor();
private:
    QVBoxLayout *lay;
    QLabel *label;
    QPushButton *button;

private slots:
    void click();
};

#endif // BRUSHCOLOR_H
