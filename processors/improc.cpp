#include "processors/improc.h"


inline void FeatureDetectors::convertMat2QImage(void)
{
    cv::Mat temp; // make the same cv::Mat
    cvtColor(ImageToProcess, ImageToProcess, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    InOutQImage = QImage((const uchar *) ImageToProcess.data,
                       ImageToProcess.cols,
                       ImageToProcess.rows,
                       ImageToProcess.step,
                       QImage::Format_RGB888);
    InOutQImage.bits(); // enforce deep copy, see documentation
}


inline void FeatureDetectors::convertQImage2Mat(void)
{
    cv::Mat tmp(InOutQImage.height(),
                InOutQImage.width(),
                CV_8UC3,(uchar*)InOutQImage.bits(),
                InOutQImage.bytesPerLine());
    cvtColor(tmp, ImageToProcess, CV_BGR2RGB);
}

void FeatureDetectors::setFilter(filter _h)
{
    h = _h;
}

void FeatureDetectors::applyFilterOnInputImage(QImage inputQImage)
{
    InOutQImage = inputQImage;
    convertQImage2Mat();

//    if (h == CORNERS) applyShiThomasiCornerDetector();
//    if (h == EDGES) applySobelFilter();

    convertMat2QImage();

    emit returnQImageToMainwindow(InOutQImage);
}


