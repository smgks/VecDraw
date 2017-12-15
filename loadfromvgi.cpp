#include "loadfromvgi.h"
#include <QDomDocument>
#include <QFile>
#include <QDomNode>
#include <iostream>
#include "figures/fellipse.h"
#include "figures/fline.h"
#include "figures/fpolyline.h"
#include "figures/frect.h"

loadFromvgi::loadFromvgi(QString filename, QGraphicsScene *scene)
{

    QPen pen;
    QBrush brush;

     QDomDocument doc;
     QFile file(filename);
     std::cout<<"try1"<<std::endl;
     if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
         return ;
     QDomNodeList dNode = doc.elementsByTagName("g");
     std::cout<<dNode.length()<<std::endl;
     for (int i = 0; i < dNode.length(); ++i) {

         QDomNode rect = dNode.at(i).firstChildElement("rect");
         if(!(rect.isNull())){
             fRect *frect = new fRect;
             pen.setColor(QColor(dNode.at(i).toElement().attribute("pencolor")));
             pen.setWidth(dNode.at(i).toElement().attribute("penwidth").toInt());
             brush.setColor(QColor(dNode.at(i).toElement().attribute("brushcolor")));

             brush.setStyle(Qt::BrushStyle(dNode.at(i).toElement().attribute("brushstyle").toInt()));
             frect->setPen(pen);
             frect->setBrush(brush);
             frect->setAngle(dNode.at(i).toElement().attribute("angle").toInt());
             QDomNodeList nodes = rect.childNodes();

             QPointF temp(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());

             frect->addPoint(temp);
             std::cout<<nodes.item(0).toElement().attribute("x").toFloat()<<" <> "<<nodes.item(0).toElement().attribute("y").toFloat()<<std::endl;
             frect->setPos(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());
             temp = QPointF(nodes.item(1).toElement().attribute("x").toFloat(),
                            nodes.item(1).toElement().attribute("y").toFloat());
             frect->addPoint(temp);

             scene->addItem(frect);
             info::vecItems.append(frect);
         }
         QDomNode ellipse = dNode.at(i).firstChildElement("ellipse");
         if(!ellipse.isNull()){
             fEllipse *frect = new fEllipse;
             pen.setColor(QColor(dNode.at(i).toElement().attribute("pencolor")));
             pen.setWidth(dNode.at(i).toElement().attribute("penwidth").toInt());
             brush.setColor(QColor(dNode.at(i).toElement().attribute("brushcolor")));

             brush.setStyle(Qt::BrushStyle(dNode.at(i).toElement().attribute("brushstyle").toInt()));
             frect->setPen(pen);
             frect->setBrush(brush);
             QDomNodeList nodes = ellipse.childNodes();

             QPointF temp(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());

             frect->addPoint(temp);
             std::cout<<nodes.item(0).toElement().attribute("x").toFloat()<<" <> "<<nodes.item(0).toElement().attribute("y").toFloat()<<std::endl;
             frect->setPos(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());
             temp = QPointF(nodes.item(1).toElement().attribute("x").toFloat(),
                            nodes.item(1).toElement().attribute("y").toFloat());
             frect->addPoint(temp);

             scene->addItem(frect);
             info::vecItems.append(frect);
         }
         QDomNode line = dNode.at(i).firstChildElement("line");
         if(!line.isNull()){
             fLine *frect = new fLine;
             pen.setColor(QColor(dNode.at(i).toElement().attribute("pencolor")));
             pen.setWidth(dNode.at(i).toElement().attribute("penwidth").toInt());
             brush.setColor(QColor(dNode.at(i).toElement().attribute("brushcolor")));

             brush.setStyle(Qt::BrushStyle(dNode.at(i).toElement().attribute("brushstyle").toInt()));
             frect->setPen(pen);
             frect->setBrush(brush);
             frect->setAngle(dNode.at(i).toElement().attribute("angle").toInt());
             QDomNodeList nodes = line.childNodes();

             QPointF temp(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());
            std::cout<<nodes.item(0).toElement().attribute("x").toFloat()<<" <> "<<nodes.item(0).toElement().attribute("y").toFloat()<<std::endl;
             frect->addPoint(temp);

             frect->setPos(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());
             temp = QPointF(nodes.item(1).toElement().attribute("x").toFloat(),
                            nodes.item(1).toElement().attribute("y").toFloat());
             frect->addPoint(temp);

            scene->addItem(frect);
             info::vecItems.append(frect);
         }
         QDomNode polyline = dNode.at(i).firstChildElement("polyline");
         if(!polyline.isNull()){
             fPolyline *frect = new fPolyline;
             pen.setColor(QColor(dNode.at(i).toElement().attribute("pencolor")));
             pen.setWidth(dNode.at(i).toElement().attribute("penwidth").toInt());
             frect->setPen(pen);
             QDomNodeList nodes = polyline.childNodes();
             QPointF temp(nodes.item(0).toElement().attribute("x").toFloat(),
                          nodes.item(0).toElement().attribute("y").toFloat());
             frect->addPoint(temp);
             frect->setPos(nodes.item(0).toElement().attribute("x").toFloat(),
                           nodes.item(0).toElement().attribute("y").toFloat());
             for (int var = 1; var < nodes.length(); ++var) {
                 temp = QPointF(nodes.item(var).toElement().attribute("x").toFloat(),
                                nodes.item(var).toElement().attribute("y").toFloat());
                 frect->addPoint(temp);
             }
             scene->addItem(frect);
             info::vecItems.append(frect);
         }

     }
     std::cout<<"ended"<<std::endl;
     file.close();
}
