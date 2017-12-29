#include "pencolor.h"
#include "sceneinfo.h"
penColor::penColor()
{
    lay = new QVBoxLayout;
    label = new QLabel;
    button = new QPushButton;
    lay->addWidget(label);
    label->setText("pen color");
    lay->addWidget(button);
    this->setLayout(lay);
    setAccessibleName("penColor");
    button->setStyleSheet("background-color: " + info::pen.color().name());
    connect(button,SIGNAL(clicked(bool)),this,SLOT(click()));
}
void penColor::click(){
    QColor temp = QColorDialog::getColor();
    if (!temp.isValid() ) {
    }
    info::pen.setColor(temp);

    for (int var = 0; var < info::vecItems.length(); ++var) {
        if (info::vecItems[var]->isSelected()){
            info::vecItems[var]->setPen(info::pen);
            info::vecItems[var]->update();
        }
    }
    info::URstActs.clearReActs();
    info::URstActs.addAct();
    button->setStyleSheet("background-color: " + info::pen.color().name());
}

penColor::~penColor()
{
    delete lay;
    delete label;
    delete button;
}
