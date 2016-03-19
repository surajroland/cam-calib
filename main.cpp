#include "gui/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/cuda_types.hpp>
#include <opencv2/core/cuda.inl.hpp>


Q_DECLARE_METATYPE(cv::Mat)

int main(int argc, char *argv[])
{
    qRegisterMetaType<cv::Mat>();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
