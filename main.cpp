#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QObject>
#include "processors/improc.h"


Q_DECLARE_METATYPE(cv::Mat)

int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>();
    QApplication a(argc, argv);

    MainWindow w ;
    FeatureDetectors feat;

    QObject::connect(&w, SIGNAL(sendImageToProcessor(QImage)),
                     &feat, SLOT(QImage2Mat(QImage)));

    QObject::connect(&w, SIGNAL(sendSelectedFilter(FeatureDetectors::filter)),
                     &feat, SLOT(setFilter(FeatureDetectors::filter)));

    w.show();

    return a.exec();

}


