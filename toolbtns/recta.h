#ifndef RECTA_H
#define RECTA_H

#include "abstractTB.h"

class rectA : public abstractTB
{
    Q_OBJECT
public:
    explicit rectA();
    ~rectA();
private:
    QVBoxLayout *lay;
    QLabel *label;
    QSpinBox *spinB;

private slots:
    void vChg();

};

#endif // RECTA_H
