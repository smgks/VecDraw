#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sceneinfo.h"

#include <QScrollBar>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QSvgGenerator>
#include "fixedsize.h"
#include "svgreader.h"
#include "vgi.h"
#include <iostream>
#include "loadfromvgi.h"
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
    PaintZone->setMouseTracking(1);
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
    filemenu->addAction("Save to SVG");
    filemenu->addAction("Open from SVG");
    filemenu->addAction("Save to vgi");
    filemenu->addAction("Open from vgi");
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
        for (int i = 0; i < scene->items().length(); ++i) {
            scene->removeItem(scene->items()[i]);
            info::vecItems.remove(i);
            i--;
        }
        delete info::tool;
        delete LeftlBar;
        LeftlBar = new LeftToolBar(TopBar);
        MainForm->addWidget(LeftlBar);
        addToolBar(Qt::LeftToolBarArea,LeftlBar);
    }
    if ((act->text()) == "Set fixed size"){
        FixedSize *tempDialog = new FixedSize;
        connect(tempDialog,SIGNAL(setFixedSceneSize(int,int)),this,SLOT(setFixedSceneSize(int,int)));
    }
    if(act->text() == "Open from vgi"){

        QString path;
        QString newPath = QFileDialog::getOpenFileName(this, trUtf8("Open VGI"),
            path);
        if (newPath.isEmpty())
                return;
        path = newPath;
        loadFromvgi temp(path,scene);
        std::cout<<"qqq\n";
    }
    if ((act->text()) == "Save to vgi"){
        for (int var = 0; var < info::vecItems.length(); ++var) {
            info::vecItems[var]->setSelected(0);
        }
        QString path;
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save VGI"),
            path, tr("VGI files (*.vgi)"));

        if (newPath.isEmpty())
                return;
        path = newPath;
        vgi saving(path);
    }
    if ((act->text()) == "Save to SVG"){
        for (int var = 0; var < info::vecItems.length(); ++var) {
            info::vecItems[var]->setSelected(0);

        }
        QString path;
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
            path, tr("SVG files (*.svg)"));

        if (newPath.isEmpty())
                return;
        path = newPath;
        QSvgGenerator generator;
            generator.setFileName(path);
            generator.setSize(QSize(scene->width(), scene->height()));
            generator.setViewBox(QRect(0, 0, scene->width(), scene->height()));
        QPainter painter;
            painter.begin(&generator);
            scene->render(&painter);
            painter.end();

    }
    if ((act->text()) == "Open from SVG"){
        QString path;
        QString newPath = QFileDialog::getOpenFileName(this, trUtf8("Open SVG"),
            path);
        if (newPath.isEmpty())
                return;
        path = newPath;
        svgreader reader(scene);
        scene->clear();
        reader.getElements(path);
        scene->update();
    }
}

MainWindow::~MainWindow(){
    delete ui;
}
