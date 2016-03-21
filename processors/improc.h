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

     void applyShiThomasiCornerDetector(void);
     void applySobelFilter(void);
     void convertMat2QImage(void);
     void convertQImage2Mat(void);

signals:
     void returnQImageToMainwindow(QImage processesdImage);

private slots:
     void applyFilterOnInputImage(QImage inputImage);
     void setFilter(FeatureDetectors::filter _h);

private:
    cv::Mat ImageToProcess;
    QImage  InOutQImage;

    filter h;
};

#endif // IMPROC_H
