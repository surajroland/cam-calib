#include "processors/improc.h"


inline void FeatureDetectors::convertMat2QImage(void)
{
    cv::cvtColor(ImageToProcess, ImageToProcess, CV_BGRA2RGBA); // cvtColor Makes a copt, that what i need

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

    cv::cvtColor(temp, ImageToProcess, CV_BGRA2RGBA);
}

void FeatureDetectors::setFilter(filter _h)
{
    h = _h;
}

void FeatureDetectors::applyFilterOnInputImage(QImage inputQImage)
{
    InOutQImage = inputQImage;
    convertQImage2Mat();

    if (h == CORNERS) applyShiThomasiCornerDetector();
    if (h == EDGES) applySobelFilter();

    convertMat2QImage();

    emit returnQImageToMainwindow(InOutQImage);
}


inline void FeatureDetectors::applySobelFilter()
{
    cv::cvtColor(ImageToProcess, ImageToProcess, CV_RGBA2GRAY);

    int edgeThresh = 1;
    int lowThreshold = 10;
    int ratio = 3;
    int kernel_size = 3;

    blur( ImageToProcess, ImageToProcess, cv::Size(3,3) );
    Canny( ImageToProcess, ImageToProcess, lowThreshold, lowThreshold*ratio, kernel_size );

    cv::cvtColor(ImageToProcess, ImageToProcess, CV_GRAY2BGRA);

}

void FeatureDetectors::applyShiThomasiCornerDetector()
{
    std::vector<cv::Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;
    int maxCorners = 100;

    cv::cvtColor(ImageToProcess, ImageToProcess, CV_RGBA2GRAY);

    cv::goodFeaturesToTrack( ImageToProcess,
                             corners,
                             maxCorners,
                             qualityLevel,
                             minDistance,
                             cv::Mat(),
                             blockSize,
                             useHarrisDetector,
                             k );

    cv::cvtColor(ImageToProcess, ImageToProcess, CV_GRAY2BGRA);

    for( int i = 0; i < corners.size(); ++i )
    {
        circle( ImageToProcess, corners[i], 4, cv::Scalar(0,255,0), -1, 8, 0 );
    }
}
