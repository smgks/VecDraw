#include "recta.h"
#include "sceneinfo.h"
rectA::rectA()
{
    lay = new QVBoxLayout;
    label = new QLabel;
    spinB = new QSpinBox;
    spinB->setMinimumSize(20,40);
    spinB->setFocusPolicy(Qt::NoFocus);
    lay->addWidget(label);
    label->setText("rect angle");
    spinB->setMinimum(1);
    spinB->setMaximum(100);
    lay->addWidget(spinB);
    this->setLayout(lay);
    spinB->setFocusPolicy(Qt::NoFocus);
    spinB->setValue(info::angle);
    setAccessibleName("rectAngle");
    connect(spinB,SIGNAL(valueChanged(int)),this,SLOT(vChg()));
}

void rectA::vChg(){
    info::angle = spinB->value();

    for (int var = 0; var < info::vecItems.length(); ++var) {
        if (info::vecItems[var]->isSelected()){
            info::vecItems[var]->setAngle(info::angle);
            info::vecItems[var]->update();
        }
    }
    spinB->setEnabled(0);
    spinB->setEnabled(1);
    spinB->setFocusPolicy(Qt::NoFocus);
}
rectA::~rectA()
{
    delete lay;
    delete label;
    delete spinB;
}
