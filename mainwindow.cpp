#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sceneinfo.h"

#include <QScrollBar>
#include <QLabel>
#include <QLineEdit>
#include "fixedsize.h"

info::gScale *(info::globalScale) = new info::gScale;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    info::globalScale->setScale(99,99);
    ui->setupUi(this);
    mainMenuBar = new QMenuBar;
    mainMenuBar->setStyleSheet("background-color: gold");
    MainForm = new  QHBoxLayout;
    TopBar = new TopToolBar;
    addToolBar(Qt::TopToolBarArea,TopBar);
    LeftlBar = new LeftToolBar(TopBar);
    scene = new MainScene;

    PaintZone = new QGraphicsView;
    PaintZone->setScene(scene);
    PaintZone->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    PaintZone->scale(info::globalScale->getScaleX(),info::globalScale->getScaleY());
    PaintZone->setStyleSheet("border-color: silver");
    ui->centralWidget->setLayout(MainForm);
    MainForm->addWidget(LeftlBar);
    addToolBar(Qt::LeftToolBarArea,LeftlBar);
    MainForm->addWidget(PaintZone);
    setMenuBar(mainMenuBar);
    filemenu = new QMenu;
    filemenu->setStyleSheet("background-color: silver");
    filemenu->setTitle("File");
    mainMenuBar->addMenu(filemenu);
        filemenu->addAction("Clear");
        filemenu->addAction("Set fixed size");

    connect(LeftlBar,SIGNAL(changeScale()),this,SLOT(setMainScale()));

    connect(filemenu,SIGNAL(triggered(QAction*)),this,SLOT(clearScene(QAction*)));
}

void MainWindow::setMainScale(){
    PaintZone->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    PaintZone->scale(1/info::globalScale->getLX(),1/info::globalScale->getLY());
    PaintZone->scale(info::globalScale->getScaleX(),info::globalScale->getScaleY());
}

void MainWindow::setFixedSceneSize(int h,int w)
{
    PaintZone->setSceneRect(0,0,w,h);
}
void MainWindow::clearScene(QAction *act)
{
    if ((act->text()) == "Clear"){
        PaintZone->scene()->clear();
        while (info::figurStack.length() != 0){
            info::figurStack.pop_back();
        }
    }
    if ((act->text()) == "Set fixed size"){
        FixedSize *tempDialog = new FixedSize;
        connect(tempDialog,SIGNAL(setFixedSceneSize(int,int)),this,SLOT(setFixedSceneSize(int,int)));
    }
}

MainWindow::~MainWindow(){
    delete ui;
}
