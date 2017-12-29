#ifndef SCENEINFO_H
#define SCENEINFO_H

#include "tools/abstracttool.h"
#include "figures/abstractfigure.h"
#include "vgi.h"
#include "loadfromvgi.h"
#include <QXmlStreamWriter>
#include <QDomDocument>
#include <QObject>
#include <QtCore>

#include <iostream>


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

            QString tpath = QCoreApplication::applicationDirPath() + "/temp";
            vgi temp(tpath);
            QFile file(tpath);
            QDomDocument doc;
            if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
                return ;
            if (undoGroup.length()!=0){
                if (undoGroup.last() != doc.toString()){
                    undoGroup.append(doc.toString());
                }
            }else{
                undoGroup.append(doc.toString());
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
        bool isSaved(){

            QFile file(path);
            QDomDocument doc;
            if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
            {
                file.close();
                return 0;
            }
            QString tempStr = doc.toString();
            file.close();
            bool res =0;
            if (undoGroup.length()!=0){
            res = QString::localeAwareCompare(tempStr,undoGroup.last());
            }
            std::cout << res <<std::endl;
            return !res;

        }
        void clearReActs(){
            redoGroup.clear();
        }
    };

    extern URst URstActs;

}
#endif // SCENEINFO_H
