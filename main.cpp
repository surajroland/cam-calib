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

    QObject::connect(&w, SIGNAL(applyFilter(FeatureDetectors::filter h, QImage inputImage)), &feat, SLOT(QImage2Mat(QImage inputImage)));

    w.show();

    return a.exec();

}


