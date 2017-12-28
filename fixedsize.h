#ifndef FIXEDSIZE_H
#define FIXEDSIZE_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class FixedSize : public QWidget
{
    Q_OBJECT
public:
    FixedSize();
private:
    QVBoxLayout *dVLay;
    QHBoxLayout *dHLay1;
    QLabel *hSize;
    QLineEdit *hSizeVaul;
    QHBoxLayout *dHLay2;
    QLabel *wSize;
    QLineEdit *wSizeVaul;
    QPushButton *okbtn;
private slots:
    void emitSize(){
        emit setFixedSceneSize((hSizeVaul->text()).toInt(),(wSizeVaul->text()).toInt());
    }
signals:
    void setFixedSceneSize(int ,int );
};

#endif // FIXEDSIZE_H
