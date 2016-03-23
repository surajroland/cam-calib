#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QObject>
#include "processors/improc.h"


Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(FeatureDetectors::filter)
Q_DECLARE_METATYPE(std::vector<cv::Point2f>)


int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<FeatureDetectors::filter>("FeatureDetectors::filter");
    qRegisterMetaType<std::vector<cv::Point2f>>("std::vector<cv::Point2f>");

    QApplication a(argc, argv);

    MainWindow w ;
    FeatureDetectors feat;

    QObject::connect(&w, SIGNAL(sendSelectedFilter(FeatureDetectors::filter)),
                     &feat, SLOT(setFilter(FeatureDetectors::filter)));

    QObject::connect(&w, SIGNAL(sendImageToProcessor(QImage)),
                     &feat, SLOT(applyFilterOnInputImage(QImage)));

    QObject::connect(&feat, SIGNAL(returnQImageToMainwindow(QImage)),
                     &w, SLOT(displayProcessedImage(QImage)));

    w.show();

    return a.exec();

}


