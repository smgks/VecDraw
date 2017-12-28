#ifndef PENRADIUS_H
#define PENRADIUS_H

#include "abstractTB.h"

class penRadius : public abstractTB
{
    Q_OBJECT
public:
    explicit penRadius();
    ~penRadius();
private:
    QVBoxLayout *lay;
    QLabel *label;
    QSpinBox *spinB;

private slots:
    void vChg();

};

#endif // PENRADIUS_H
