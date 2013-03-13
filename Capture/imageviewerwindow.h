#ifndef IMAGEVIEWERWINDOW_H
#define IMAGEVIEWERWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QMovie>
#include <QThread>
#include <QDebug>
#include "imageworker.h"



namespace Ui {
class ImageViewerWindow;
}

class ImageViewerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ImageViewerWindow(QWidget *parent = 0);
    ~ImageViewerWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_actionAbrir_triggered();

    void on_actionSalir_triggered();

    void on_movie_updated(const QRect& rect);


signals:
       // Señal para comunicarnos con el hilo de trabajo
       void imageRequested(const QImage);

   private slots:
       // Slot para saber cuando la imagen ha sido devuelta
       void imageBack(const QImage &img);



private:
    Ui::ImageViewerWindow *ui;
    QMovie *movie_;

    // Clase del hilo de trabajo
    QThread workingThread_;
    // Clase que hace el ordenamiento
    imageWorker imageWorker_;

};



#endif // IMAGEVIEWERWINDOW_H
