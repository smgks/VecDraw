#include "brushstyle.h"
#include "sceneinfo.h"
brushStyle::brushStyle()
{
    lay = new QVBoxLayout;
    label = new QLabel;
    combobox = new QComboBox;
    combobox->setFixedWidth(90);
    lay->addWidget(label);
    label->setText("brush style");
    lay->addWidget(combobox);
    combobox->addItem("NoBrush");
    combobox->addItem("SolidPattern");
    combobox->addItem("Dense1Pattern");
    combobox->addItem("Dense2Pattern");
    combobox->addItem("Dense3Pattern");
    combobox->addItem("Dense4Pattern");
    combobox->addItem("Dense5Pattern");
    combobox->addItem("Dense6Pattern");
    combobox->addItem("Dense7Pattern");
    combobox->addItem("HorPattern");
    combobox->addItem("VerPattern");
    combobox->addItem("CrossPattern");
    combobox->addItem("BDiagPattern");
    combobox->addItem("FDiagPattern");
    combobox->addItem("DiagCrossPattern");
    combobox->addItem("LinearGradientPattern");
    combobox->addItem("ConicalGradientPattern");
    combobox->addItem("RadialGradientPattern");
    combobox->setCurrentIndex(info::brush.style());
    this->setLayout(lay);
    setAccessibleName("brushStyle");
    connect(combobox,SIGNAL(currentIndexChanged(int)),this,SLOT(vChg()));
}

void brushStyle::vChg(){
    info::brush.setStyle(Qt::BrushStyle(combobox->currentIndex()));
    for (int var = 0; var < info::vecItems.length(); ++var) {
        if (info::vecItems[var]->isSelected()){
            info::vecItems[var]->setBrush(info::brush);
        }
    }
}

brushStyle::~brushStyle()
{
    delete lay;
    delete label;
    delete combobox;
}
