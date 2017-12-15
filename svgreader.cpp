#include "svgreader.h"
#include "sceneinfo.h"

#include <QStringList>
#include <QtSvg/QGraphicsSvgItem>
#include <QPainterPath>

svgreader::svgreader(QGraphicsScene *tscene)
{
    cscene = tscene;
}
void svgreader::getElements(const QString filename)
{
    QDomDocument doc;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return ;
    QDomNodeList gList = doc.elementsByTagName("g");
    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);
        QDomElement rectangle = gNode.firstChildElement("rect");
        QDomElement ellipse = gNode.firstChildElement("ellipse");
        QDomElement polyline = gNode.firstChildElement("polyline");
        if (!(polyline.isNull())){

            fPolyline *temppl = new fPolyline;
            QDomElement gElement = gNode.toElement();
            QString transform(gElement.attribute("transform"));

            transform = transform.remove(0,7);
            transform = transform.remove(transform.length()-2,2);
            QColor strokeColor(gElement.attribute("stroke"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            temppl->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toFloat()));
            QVector<float> vauls;
            int start = 0;
            for (int var = 0; var < transform.length(); ++var) {
                if(transform[var] ==","){
                    vauls.append(transform.midRef(start,var-start).toFloat());
                    start=var+1;
                }
            }

            for (int i = 0; i < gNode.childNodes().length(); i++) {
                QDomElement lElement = gNode.childNodes().at(i).toElement();
                QStringList listP = lElement.attribute("points").split(QRegExp(" "));


                vauls.append(transform.midRef(start,transform.length()).toFloat());

                    if(0==i){
                        temppl->setPos(QPointF(
                                        listP.at(0).split(QRegExp(",")).at(0).toFloat() +
                                           QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dx(),
                                        listP.at(0).split(QRegExp(",")).at(1).toFloat() +
                                           QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dy()
                                              )
                                      );
                        temppl->addPoint(QPointF(listP.at(0).split(QRegExp(",")).at(0).toFloat(),listP.at(0).split(QRegExp(",")).at(1).toFloat()));
                        //std::cout<<i+1<<")"<<listP.at(0).split(QRegExp(",")).at(0).toFloat()<<"\t\t"<<listP.at(0).split(QRegExp(",")).at(1).toFloat()<<std::endl;
                        temppl->addPoint(QPointF(listP.at(1).split(QRegExp(",")).at(0).toFloat(),listP.at(1).split(QRegExp(",")).at(1).toFloat()));
                        //std::cout<<i+2<<")"<<listP.at(1).split(QRegExp(",")).at(0).toFloat()<<"\t\t"<<listP.at(1).split(QRegExp(",")).at(1).toFloat()<<std::endl;
                    }else{
                        temppl->addPoint(QPointF(listP.at(1).split(QRegExp(",")).at(0).toFloat(),listP.at(1).split(QRegExp(",")).at(1).toFloat()));
                        //std::cout<<i+2<<")"<<listP.at(1).split(QRegExp(",")).at(0).toFloat()<<"\t\t"<<listP.at(1).split(QRegExp(",")).at(1).toFloat()<<std::endl;
                    }

            }
            cscene->addItem(temppl);
            info::vecItems.append(temppl);
        }
        if (!(rectangle.isNull())){
            fRect *rect = new fRect;
            QDomElement gElement = gNode.toElement();
            rect->setFlag(QGraphicsItem::ItemIsMovable,1);
            QPointF temp(rectangle.attribute("x").toFloat(),
                         rectangle.attribute("y").toFloat());
            rect->addPoint(temp);
//            QColor fillColor(gElement.attribute("fill"));
//            fillColor.setAlphaF(gElement.attribute("fill-opacity").toFloat());
            QString fill = gElement.attribute("fill", "#ffffff");
                        if(fill.contains("url(#gradient")){
                            fill.replace(QString("url(#gradient"), QString(""));
                            fill.replace(QString(")"), QString(""));
                            QBrush brush;
                            brush.setColor(fill);
                            brush.setStyle(Qt::BrushStyle(2));
                            rect->setBrush(brush);
                        }
            QColor strokeColor(gElement.attribute("stroke"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());

            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toFloat()));


            QString transform(gElement.attribute("transform"));

            transform = transform.remove(0,7);
            transform = transform.remove(transform.length()-2,2);

            QVector<float> vauls;
            int start = 0;
            for (int var = 0; var < transform.length(); ++var) {
                if(transform[var] ==","){
                    vauls.append(transform.midRef(start,var-start).toFloat());
                    start=var+1;
                }
            }
            vauls.append(transform.midRef(start,transform.length()).toFloat());
            rect->setPos(temp.x() + QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dx(),
                         temp.y() + QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dy());
            temp = QPointF(rectangle.attribute("x").toFloat() + rectangle.attribute("width").toFloat(),
                           rectangle.attribute("y").toFloat() + rectangle.attribute("height").toFloat());

            rect->addPoint(temp);
            cscene->addItem(rect);
            cscene->update();
            info::vecItems.append(rect);
        }
        if (!(ellipse.isNull())){
            fEllipse *rect = new fEllipse;
            rect->setFlag(QGraphicsItem::ItemIsMovable,1);
            QDomElement gElement = gNode.toElement();
            cscene->addItem(rect);
            QPointF temp(ellipse.attribute("cx").toFloat()-ellipse.attribute("rx").toFloat(),
                         ellipse.attribute("cy").toFloat()-ellipse.attribute("ry").toFloat());
            rect->addPoint(temp);
            rect->setPos(temp);//
            QString fill = gElement.attribute("fill", "#ffffff");
                        if(fill.contains("url(#gradient")){
                            fill.replace(QString("url(#gradient"), QString(""));
                            fill.replace(QString(")"), QString(""));
                            QBrush brush;
                            brush.setColor(fill);
                            brush.setStyle(Qt::BrushStyle(gElement.attribute("fill-opacity").toInt()));
                            rect->setBrush(brush);
                        }
            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());
            QString transform(gElement.attribute("transform"));

            transform = transform.remove(0,7);
            transform = transform.remove(transform.length()-2,2);
            QVector<float> vauls;
            int start = 0;
            for (int var = 0; var < transform.length(); ++var) {
                if(transform[var] ==","){
                    vauls.append(transform.midRef(start,var-start).toFloat());
                    start=var+1;
                }
            }
            vauls.append(transform.midRef(start,transform.length()).toFloat());
            rect->setPos(temp.x()+QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dx(),
                         temp.y()+QMatrix(vauls[0],vauls[1],vauls[2],vauls[3],vauls[4],vauls[5]).dy());
            rect->setPen(QPen(strokeColor,gElement.attribute("stroke-width", "0").toFloat()));
            temp = QPointF(ellipse.attribute("rx").toFloat()+ellipse.attribute("cx").toFloat(),
                           ellipse.attribute("ry").toFloat()+ellipse.attribute("cy").toFloat());
            rect->addPoint(temp);
            cscene->update();
            info::vecItems.append(rect);

        }


    }

    file.close();
}

