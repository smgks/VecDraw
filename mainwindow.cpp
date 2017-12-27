#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sceneinfo.h"

#include <QScrollBar>
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>
#include <QClipboard>
#include <iostream>
#include <QSvgGenerator>
#include <QXmlStreamWriter>
#include <QFile>
#include <QTextStream>

#include "fixedsize.h"
#include "svgreader.h"
#include "vgi.h"
#include "loadfromvgi.h"
info::gScale *(info::globalScale) = new info::gScale;
QString info::path = "";
QVector<QAction*> undoGroup;
QVector<QAction*> redoGroup;
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
    filemenu->addAction("Save to vgi as");
    filemenu->addAction("Save to vgi");
    filemenu->addAction("Open from vgi");
    this->setWindowTitle(QString("Unnamed") + QString(" - not saved"));
    connect(LeftlBar,SIGNAL(changeScale()),this,SLOT(setMainScale()));

    connect(filemenu,SIGNAL(triggered(QAction*)),this,SLOT(clearScene(QAction*)));
}

void MainWindow::closeEvent(QCloseEvent *event){

    QWidget *dialog = new QWidget;
    QVBoxLayout *Vlay = new QVBoxLayout;
    QHBoxLayout *Hlay = new QHBoxLayout;
    QLabel *lb = new QLabel;
    QPushButton *yesBtn = new QPushButton;
    QPushButton *noBtn = new QPushButton;
    QPushButton *ignoreBtn = new QPushButton;

    dialog->setLayout(Vlay);
    dialog->setFixedSize(240,80);
    Vlay->addWidget(lb);
    lb->setText("you want to save it?");
    lb->setAlignment(Qt::AlignCenter);
    Vlay->addLayout(Hlay);
    Hlay->addWidget(noBtn);
    noBtn->setText("No");
    Hlay->addWidget(ignoreBtn);
    connect(noBtn,SIGNAL(clicked(bool)),this,SLOT(exitWithoutSaving()));
    ignoreBtn->setText("back");
    Hlay->addWidget(yesBtn);
    yesBtn->setText("Yes");
    connect(yesBtn,SIGNAL(clicked(bool)),this,SLOT(exitWithSaving()));
    dialog->show();
    event->ignore();
}

void MainWindow::exitWithSaving(){
    if (info::path==""){
        for (int var = 0; var < info::vecItems.length(); ++var) {
            info::vecItems[var]->setSelected(0);
        }
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save VGI"),
            info::path, tr("VGI files (*.vgi)"));

        if (newPath.isEmpty())
                return;
        info::path = newPath;
        vgi saving(info::path);
    }
    else{
        vgi saving(info::path);
    }
    exit(0);
}

void MainWindow::exitWithoutSaving(){
    exit(0);
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
        MainForm->addWidget(LeftlBar);this->setWindowTitle(info::path);
        addToolBar(Qt::LeftToolBarArea,LeftlBar);
        info::path="";
        this->setWindowTitle("unnamed");
    }
    if ((act->text()) == "Set fixed size"){
        FixedSize *tempDialog = new FixedSize;
        connect(tempDialog,SIGNAL(setFixedSceneSize(int,int)),this,SLOT(setFixedSceneSize(int,int)));
    }
    if(act->text() == "Open from vgi"){

        QString newPath = QFileDialog::getOpenFileName(this, trUtf8("Open VGI"),
            info::path);
        if (newPath.isEmpty())
                return;
        info::path = newPath;
        loadFromvgi temp(info::path,scene);
    }
    if ((act->text()) == "Save to vgi as"){
        saveAsDialog();
    }
    if ((act->text()) == "Save to vgi"){
        saveDialog();
    }
    if ((act->text()) == "Save to SVG"){
        for (int var = 0; var < info::vecItems.length(); ++var) {
            info::vecItems[var]->setSelected(0);

        }
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save SVG"),
            info::path, tr("SVG files (*.svg)"));

        if (newPath.isEmpty())
                return;
        info::path = newPath;
        QSvgGenerator generator;
            generator.setFileName(info::path);
            generator.setSize(QSize(scene->width(), scene->height()));
            generator.setViewBox(QRect(0, 0, scene->width(), scene->height()));
        QPainter painter;
            painter.begin(&generator);
            scene->render(&painter);
            painter.end();

    }
    if ((act->text()) == "Open from SVG"){
        QString newPath = QFileDialog::getOpenFileName(this, trUtf8("Open SVG"),
            info::path);
        if (newPath.isEmpty())
                return;
        info::path = newPath;
        svgreader reader(scene);
        scene->clear();
        reader.getElements(info::path);
        scene->update();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_C:
        if(event->modifiers() & Qt::CTRL){
            QFile file(QCoreApplication::applicationDirPath()+"/temp");
            file.open(QIODevice::WriteOnly);
            QXmlStreamWriter xmlWriter(&file);
            xmlWriter.setAutoFormatting(true);
            xmlWriter.writeStartDocument();
            xmlWriter.writeStartElement("VGI");
            QClipboard *clipboard = QApplication::clipboard();
            for (int var = 0; var < info::vecItems.length(); ++var) {
                if(info::vecItems[var]->isSelected()){
                    info::vecItems[var];

                     xmlWriter.writeStartElement("g");
                     xmlWriter.writeAttribute("pencolor",info::vecItems[var]->getPen().color().name());
                     xmlWriter.writeAttribute("penwidth",QString::number(info::vecItems[var]->getPen().width()));
                     xmlWriter.writeAttribute("brushcolor",info::vecItems[var]->getBrush().color().name());
                     xmlWriter.writeAttribute("brushstyle",QString::number(info::vecItems[var]->getBrush().style()));
                     xmlWriter.writeAttribute("angle",QString::number(info::vecItems[var]->getAngle()));

                     info::vecItems[var]->getCords();
                     xmlWriter.writeStartElement(info::vecItems[var]->getName());
                     for (int i = 0; i < info::vecItems[var]->getCords().length(); ++i) {
                         xmlWriter.writeStartElement("point");
                         xmlWriter.writeAttribute("x",QString::number(info::vecItems[var]->getCords()[i].x()));
                         xmlWriter.writeAttribute("y",QString::number(info::vecItems[var]->getCords()[i].y()));
                         xmlWriter.writeEndElement();
                     }
                     xmlWriter.writeEndElement();
                     xmlWriter.writeEndElement();
                }
            }
            xmlWriter.writeEndElement();
            file.flush();
            file.close();
            QDomDocument doc;
            if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
                return ;
            clipboard->setText(doc.toString());
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            file.remove();
            file.close();
        }
        break;
    case Qt::Key_V:
        if(event->modifiers() & Qt::CTRL){
            QClipboard *clipboard = QApplication::clipboard();
            QFile file(QCoreApplication::applicationDirPath()+"/temp");
            file.open(QIODevice::WriteOnly);
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            QTextStream writeStream(&file);
            writeStream << clipboard->text();
            file.close();
            loadFromvgi(QCoreApplication::applicationDirPath()+"/temp",scene,1);
            break;
        }
    }
}

void MainWindow::saveAsDialog(){

    for (int var = 0; var < info::vecItems.length(); ++var) {
        info::vecItems[var]->setSelected(0);
    }
    QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save VGI"),
        info::path, tr("VGI files (*.vgi)"));

    if (newPath.isEmpty())
            return;
    info::path = newPath;
    vgi saving(info::path);
    this->setWindowTitle(info::path);
}
void MainWindow::saveDialog(){

    if (info::path==""){
        for (int var = 0; var < info::vecItems.length(); ++var) {
            info::vecItems[var]->setSelected(0);
        }
        QString newPath = QFileDialog::getSaveFileName(this, trUtf8("Save VGI"),
            info::path, tr("VGI files (*.vgi)"));

        if (newPath.isEmpty())
                return;
        info::path = newPath;
        vgi saving(info::path);
    }
    else{
        vgi saving(info::path);
    }

}
MainWindow::~MainWindow(){
    delete ui;
}
