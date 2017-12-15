#include "fixedsize.h"
#include <QRegExpValidator>
FixedSize::FixedSize()
{

    setFixedSize(200,115);
    dVLay = new QVBoxLayout;
    dHLay1 = new QHBoxLayout;
        hSize = new QLabel;
            hSize->setText("Heigth");
        hSizeVaul = new QLineEdit;
            hSizeVaul->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0|-)[0-9]{3}"), this));
    dHLay1->addWidget(hSize);
    dHLay1->addWidget(hSizeVaul);
    dVLay->addLayout(dHLay1);
    dHLay2 = new QHBoxLayout;
        wSize = new QLabel;
            wSize->setText("Weigth");
        wSizeVaul = new QLineEdit;
            wSizeVaul->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0|-)[0-9]{3}"), this));
    dHLay2->addWidget(wSize);
    dHLay2->addWidget(wSizeVaul);
    dVLay->addLayout(dHLay2);
    setLayout(dVLay);
    okbtn = new QPushButton;
    dVLay->addWidget(okbtn);
    okbtn->setText("OK");
    show();
    connect(okbtn,SIGNAL(clicked(bool)),this,SLOT(emitSize()));
    connect(okbtn,SIGNAL(clicked(bool)),this,SLOT(close()));
}
