#ifndef SCENEINFO_H
#define SCENEINFO_H

#include "tools/abstracttool.h"
#include "figures/abstractfigure.h"
#include "vgi.h"
#include "loadfromvgi.h"
#include <iostream>
#include <QXmlStreamWriter>
#include <QDomDocument>
#include <QObject>
#include <QtCore>



namespace info {
    class gScale{
    public:
        explicit gScale(){

        }
        qreal getScaleX(){
            return xScale;
        }
        qreal getScaleY(){
            return yScale;
        }
        qreal getLX(){
            return xLast;
        }
        qreal getLY(){
            return yLast;
        }
        void setScale(qreal a,qreal b){
            xLast = xScale;
            yLast = yScale;
            xScale = a/100;
            yScale = b/100;
        }
    private:
        qreal xLast;
        qreal yLast;
        qreal xScale;
        qreal yScale;
    };
    extern abstractTool *tool;
    extern gScale *globalScale;
    extern QVector<abstractfigure*> vecItems;
    extern QPen pen;
    extern QBrush brush;
    extern int angle;
    extern QString path;

    class URst{
    private:
        QGraphicsScene *scene;
        const int len = 10;
        QVector<QString> undoGroup;
        QVector<QString> redoGroup;
    public:
        explicit URst(){}
        void setScene(QGraphicsScene *s){
            scene = s;
        }
        void addAct(){
            if (undoGroup.length() >= 10){
                undoGroup.pop_front();
            }

            QString path = QCoreApplication::applicationDirPath() +"/temp";
            vgi temp(path,0);
            QFile file(path);
            QDomDocument doc;
            if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
                return ;
            if (undoGroup.length()!=0){
                if (undoGroup.last() != doc.toString()){
                    undoGroup.append(doc.toString());
                    std::cout<<doc.toString().toStdString();
                }
            }else{
                undoGroup.append(doc.toString());
    //            std::cout<<doc.toString().toStdString();
            }
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            file.remove();
            file.close();
        }
        void undoAct(){
            addAct();
            if (undoGroup.length() != 1){
                redoGroup.append(undoGroup.last());
                undoGroup.removeLast();
            }
            QFile file(QCoreApplication::applicationDirPath()+"/temp");
            file.open(QIODevice::WriteOnly);
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            QTextStream writeStream(&file);
            writeStream << undoGroup.last();
            file.close();
            if (!file.open(QIODevice::ReadOnly))
                return ;
            scene->clear();
            for (int var = 0; var < vecItems.length(); ++var) {
                vecItems[var] = 0;
            }
            vecItems.clear();
            loadFromvgi(QCoreApplication::applicationDirPath()+"/temp",scene,0);
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            file.remove();
            file.close();
        }
        void redoAct(){
            addAct();
            if (redoGroup.length() != 0){
                undoGroup.append(redoGroup.last());
                redoGroup.removeLast();
            }
            QFile file(QCoreApplication::applicationDirPath()+"/temp");
            file.open(QIODevice::WriteOnly);
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            QTextStream writeStream(&file);
            scene->clear();
            for (int var = 0; var < vecItems.length(); ++var) {
                vecItems[var] = 0;
            }
            vecItems.clear();
            writeStream << undoGroup.last();
            file.close();
            if (!file.open(QIODevice::ReadOnly))
                return ;
            loadFromvgi(QCoreApplication::applicationDirPath()+"/temp",scene,0);
            file.setPermissions(QFile::ReadOwner | QFile::WriteOwner);
            file.remove();
            file.close();

        }
        void clearActs(){
            redoGroup.clear();
        }
    };

    extern URst URstActs;

}
#endif // SCENEINFO_H
