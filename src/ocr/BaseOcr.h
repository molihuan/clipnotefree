#ifndef BASEOCR_H
#define BASEOCR_H

#include <QObject>

class BaseOcr : public QObject
{
    Q_OBJECT
public:
    explicit BaseOcr(QObject *parent = nullptr);

signals:

};

#endif // BASEOCR_H
