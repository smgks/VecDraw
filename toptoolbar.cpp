#include "toptoolbar.h"

TopToolBar::TopToolBar(){
    setContextMenuPolicy(Qt::PreventContextMenu);
    setMovable(false);
    setMinimumSize(40,40);
    setStyleSheet("background-color: grey");
}
