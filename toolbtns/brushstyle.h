#ifndef BRUSHSTYLE_H
#define BRUSHSTYLE_H

#include "abstractTB.h"

class brushStyle : public abstractTB
{
    Q_OBJECT
public:
    explicit brushStyle();
    ~brushStyle();
private:
    QVBoxLayout *lay;
    QLabel *label;
    QComboBox *combobox;

private slots:
    void vChg();

};

#endif // BRUSHSTYLE_H
