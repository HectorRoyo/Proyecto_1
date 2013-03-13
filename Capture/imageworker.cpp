#include "imageworker.h"

imageWorker::imageWorker(QObject *parent) :
    QObject(parent)
{
}

void imageWorker::doImage(const QImage &img) {
    qDebug() << Q_FUNC_INFO << QThread::currentThreadId();
    // Transformar imagen

    //Devolver imagen
    emit imageBack(img);
}



