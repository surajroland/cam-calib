#ifndef IMPROC_H
#define IMPROC_H

#include <QObject>
#include <QImage>
#include <QDebug>
#include "opencv2/imgproc/imgproc.hpp"


class FeatureDetectors : public QObject
{
    Q_OBJECT
    Q_ENUMS(filter)

public:
//     FeatureDetectors();
//    ~FeatureDetectors();

     enum filter {CORNERS, EDGES};

     void applyShiThomasiCornerDetector();
     void applySobelFilter();
     void Mat2Qpix(cv::Mat matImage);

signals:
    void returnQImageToMainwindow(QImage processesdImage);

private slots:
    void QImage2Mat(QImage inputImage);

private:
    cv::Mat outMatImage;
    QImage  outQImage;
};

#endif // IMPROC_H
