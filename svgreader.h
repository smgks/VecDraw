#ifndef SVGREADER_H
#define SVGREADER_H

#include <QList>
#include <QRectF>
#include <QString>
#include <QDomDocument>
#include "figures/abstractfigure.h"
#include "figures/fellipse.h"
#include "figures/fline.h"
#include "figures/fpolyline.h"
#include "figures/frect.h"
#include "mainscene.h"
class svgreader : public QObject
{
public:
    svgreader(QGraphicsScene *tscene);
    void getElements(const QString filename);
private:
    QGraphicsScene *cscene;
};

#endif // SVGREADER_H
