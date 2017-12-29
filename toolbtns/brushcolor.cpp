#include "brushcolor.h"
#include "sceneinfo.h"
brushColor::brushColor()
{
    lay = new QVBoxLayout;
    label = new QLabel;
    button = new QPushButton;
    button->setStyleSheet("background-color: " + info::brush.color().name());
    lay->addWidget(label);
    label->setText("brush color");
    lay->addWidget(button);
    this->setLayout(lay);
    setAccessibleName("brushColor");
    connect(button,SIGNAL(clicked(bool)),this,SLOT(click()));
}
void brushColor::click(){
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    info::brush.setColor(temp);

    for (int var = 0; var < info::vecItems.length(); ++var) {
        if (info::vecItems[var]->isSelected()){
            info::vecItems[var]->setBrush(info::brush);
            info::vecItems[var]->update();
        }
    }
    info::URstActs.clearReActs();
    info::URstActs.addAct();
    button->setStyleSheet("background-color: " + info::brush.color().name());
}
brushColor::~brushColor()
{
    delete lay;
    delete label;
    delete button;
}
