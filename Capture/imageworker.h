#ifndef IMAGEWORKER_H
#define IMAGEWORKER_H

#include <QObject>
#include <QDebug>
#include <QThread>

class imageWorker : public QObject
{
    Q_OBJECT
public:
    explicit imageWorker(QObject *parent = 0);
    
signals:
    // Señal emitida cuando la imagen ha sido devuelta
    void imageBack (const QImage &img);

public slots:
    // Método encargado del ordenamiento
    void doImage(const QImage &img);
};


#endif // IMAGEWORKER_H
