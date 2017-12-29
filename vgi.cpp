#include "vgi.h"
#include <QXmlStreamWriter>
#include <QFile>

#include "sceneinfo.h"

vgi::vgi(QString path,int sel)
{
    QFile file(path);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("VGI");
    xmlWriter.writeStartElement("title");
    xmlWriter.writeCharacters("vgi by Andrey Osadchiy");
    xmlWriter.writeEndElement();
    for (int var = 0; var < info::vecItems.length(); ++var) {
        if ((info::vecItems[var]->isSelected() == sel) || (!sel)){
         xmlWriter.writeStartElement("g");
         xmlWriter.writeAttribute("pencolor",info::vecItems[var]->getPen().color().name());
         xmlWriter.writeAttribute("penwidth",QString::number(info::vecItems[var]->getPen().width()));
         xmlWriter.writeAttribute("brushcolor",info::vecItems[var]->getBrush().color().name());
         xmlWriter.writeAttribute("brushstyle",QString::number(info::vecItems[var]->getBrush().style()));
         xmlWriter.writeAttribute("angle",QString::number(info::vecItems[var]->getAngle()));
         xmlWriter.writeAttribute("z",QString::number(info::vecItems[var]->zValue()));
         xmlWriter.writeStartElement("pos");
         xmlWriter.writeAttribute("x",QString::number(info::vecItems[var]->pos().x()));
         xmlWriter.writeAttribute("y",QString::number(info::vecItems[var]->pos().y()));
         xmlWriter.writeEndElement();
         info::vecItems[var]->getCords();
         xmlWriter.writeStartElement(info::vecItems[var]->getName());
         for (int i = 0; i < info::vecItems[var]->getCords().length(); ++i) {
             xmlWriter.writeStartElement("point");
             xmlWriter.writeAttribute("x",QString::number(info::vecItems[var]->getCords()[i].x()));
             xmlWriter.writeAttribute("y",QString::number(info::vecItems[var]->getCords()[i].y()));
             xmlWriter.writeEndElement();
         }
        }
         xmlWriter.writeEndElement();
         xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();
    file.close();
}
