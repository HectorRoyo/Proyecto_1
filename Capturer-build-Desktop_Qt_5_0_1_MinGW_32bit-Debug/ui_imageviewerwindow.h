/********************************************************************************
** Form generated from reading UI file 'imageviewerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEWERWINDOW_H
#define UI_IMAGEVIEWERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageViewerWindow
{
public:
    QAction *actionAbrir;
    QAction *actionSalir;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *image;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageViewerWindow)
    {
        if (ImageViewerWindow->objectName().isEmpty())
            ImageViewerWindow->setObjectName(QStringLiteral("ImageViewerWindow"));
        ImageViewerWindow->resize(400, 300);
        actionAbrir = new QAction(ImageViewerWindow);
        actionAbrir->setObjectName(QStringLiteral("actionAbrir"));
        actionSalir = new QAction(ImageViewerWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralWidget = new QWidget(ImageViewerWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        image = new QLabel(centralWidget);
        image->setObjectName(QStringLiteral("image"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setScaledContents(true);

        verticalLayout->addWidget(image);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        ImageViewerWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageViewerWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 20));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        ImageViewerWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageViewerWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageViewerWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageViewerWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageViewerWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuArchivo->addAction(actionAbrir);
        menuArchivo->addAction(actionSalir);

        retranslateUi(ImageViewerWindow);

        QMetaObject::connectSlotsByName(ImageViewerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ImageViewerWindow)
    {
        ImageViewerWindow->setWindowTitle(QApplication::translate("ImageViewerWindow", "ImageViewerWindow", 0));
        actionAbrir->setText(QApplication::translate("ImageViewerWindow", "Abrir", 0));
        actionSalir->setText(QApplication::translate("ImageViewerWindow", "Salir", 0));
        image->setText(QApplication::translate("ImageViewerWindow", "TextLabel", 0));
        pushButton->setText(QApplication::translate("ImageViewerWindow", "&Salir", 0));
        menuArchivo->setTitle(QApplication::translate("ImageViewerWindow", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageViewerWindow: public Ui_ImageViewerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEWERWINDOW_H
