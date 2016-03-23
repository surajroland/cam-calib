#include "processors/improc.h"



inline void FeatureDetectors::convertMat2QImage(void)
{
    cvtColor(ImageToProcess, ImageToProcess, CV_BGRA2RGBA); // cvtColor Makes a copt, that what i need

    InOutQImage = QImage((const uchar *) ImageToProcess.data,
                       ImageToProcess.cols,
                       ImageToProcess.rows,
                       ImageToProcess.step,
                       QImage::Format_RGBA8888);

    InOutQImage.bits(); // enforce deep copy, see documentation
}


inline void FeatureDetectors::convertQImage2Mat(void)
{
    cv::Mat temp(InOutQImage.height(),
                InOutQImage.width(),
                CV_8UC4,(uchar*)InOutQImage.bits(),
                InOutQImage.bytesPerLine());

    cvtColor(temp, ImageToProcess, CV_BGRA2RGBA);
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


