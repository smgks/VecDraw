#include "penradius.h"
#include "sceneinfo.h"
penRadius::penRadius()
{
    lay = new QVBoxLayout;
    label = new QLabel;
    label->setText("pen radius");
    spinB = new QSpinBox;
    spinB->setFocusPolicy(Qt::NoFocus);
    spinB->setMinimum(1);
    spinB->setMaximum(100);
    spinB->setMinimumSize(20,40);
    this->setLayout(lay);
    lay->addWidget(label);
    lay->addWidget(spinB);
    spinB->setValue(info::pen.width());
    setAccessibleName("penRadius");
    connect(spinB,SIGNAL(valueChanged(int)),this,SLOT(vChg()));
}

void penRadius::vChg(){
    info::pen.setWidth(spinB->value());

    for (int var = 0; var < info::vecItems.length(); ++var) {
        if (info::vecItems[var]->isSelected()){
            info::vecItems[var]->setPen(info::pen);
            info::vecItems[var]->update();
        }
    }
    spinB->setEnabled(0);
    spinB->setEnabled(1);
    spinB->setFocusPolicy(Qt::NoFocus);
}
penRadius::~penRadius()
{
    delete lay;
    delete label;
    delete spinB;
}
