#include "imageviewerwindow.h"
#include "ui_imageviewerwindow.h"
#include <QimageReader>
#include <QWaitCondition>
#include <QMutex>

ImageViewerWindow::ImageViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViewerWindow)
{
    ui->setupUi(this);

    movie_=new QMovie();
    //ui->image->setMovie(movie_);
    connect(movie_, SIGNAL(updated(const QRect&)),
                this, SLOT(on_movie_updated(const QRect&)));


    qDebug() << Q_FUNC_INFO << QThread::currentThreadId();

       // Pasar la petición de ordenar a la instancia de SorterWorker
       connect(this, SIGNAL(imageRequested(QImage)),
           &imageWorker_, SLOT(doImage(QImage)));
       // Ser notificado cuando el vector haya sido ordenado
       connect(&imageWorker_, SIGNAL(imageBack(QImage)),
           this, SLOT(imageBack(QImage)));

       // Migrar la instancia de SorterWorker al hilo de trabajo
       imageWorker_.moveToThread(&workingThread_);

       // Iniciar el hilo de trabajo
       workingThread_.start();


}

ImageViewerWindow::~ImageViewerWindow()
{
    delete ui;
}

void ImageViewerWindow::on_actionAbrir_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Abrir Fichero"), QString(),
    tr("Imagen (*.mjpeg)"));

    if(!fileName.isEmpty() ){
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"),
            tr("No se pudo abrir el fichero"));
            return;
        }

        movie_->setFileName(fileName);
        if (!movie_->isValid()) {
            QMessageBox::critical(this, tr("Error"),
                tr("No se pudo abrir el archivo o el formato"
                   " es inválido"));
            return;
        }

        movie_->start();    // Iniciar la reproducción de la animación
        //QWaitCondition sleep;
        //QMutex mutex;
        //sleep.wait(&mutex, 2000);    // Espera de 2 segundos


}
}

void ImageViewerWindow::on_pushButton_clicked()
{
    qApp->quit();
}
void ImageViewerWindow::on_movie_updated(const QRect& rect)
{
    QPixmap pixmap = movie_->currentPixmap();
    //Pasar el QPixmap a QImage y emitir la imagen al otro hilo
    QImage img = pixmap.toImage();
    //ui->image->setPixmap(pixmap);
    emit imageRequested(img);
}


void ImageViewerWindow::on_actionSalir_triggered()
{
    exit;
}

void ImageViewerWindow::imageBack(const QImage& img){

    qDebug() << img;

}
