#include "processors/improc.h"


void FeatureDetectors::Mat2Qpix(cv::Mat matImage)
{
    cv::Mat temp; // make the same cv::Mat
    cvtColor(matImage, temp, CV_BGR2RGB); // cvtColor Makes a copt, that what i need
    outQImage = QImage((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    outQImage.bits(); // enforce deep copy, see documentation
}


void FeatureDetectors::QImage2Mat(QImage inputImage)
{
    cv::Mat tmp(inputImage.height(),inputImage.width(),CV_8UC3,(uchar*)inputImage.bits(),inputImage.bytesPerLine());
    cvtColor(tmp, outMatImage,CV_BGR2RGB);
}

void FeatureDetectors::setFilter(filter _h)
{
    h = _h;
}


