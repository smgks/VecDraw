#ifndef VGI_H
#define VGI_H

#include <QObject>

class vgi : public QObject
{
public:
    vgi(QString path,int sel = 0);
};

#endif // VGI_H
