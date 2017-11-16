#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QMenuBar>

#include "lefttoolbar.h"
#include "mainscene.h"
#include "sceneinfo.h"
#include "toptoolbar.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QHBoxLayout *MainForm;
    TopToolBar *TopBar;
    LeftToolBar *LeftlBar;
    MainScene *scene;
    QGraphicsView *PaintZone;
    QMenuBar *mainMenuBar;
    QMenu *filemenu;
public slots:
    void setMainScale();
    void clearScene(QAction *act);
    void setFixedSceneSize(int h,int w);
};

#endif // MAINWINDOW_H
