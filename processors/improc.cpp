#include "processors/improc.h"
#include "opencv2/highgui/highgui.hpp"

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

    if (h == CORNERS) applyShiThomasiCornerDetector();
//  if (h == EDGES) applySobelFilter();

    convertMat2QImage();

    emit returnQImageToMainwindow(InOutQImage);
}


inline void FeatureDetectors::applyShiThomasiCornerDetector()
{
    std::vector<cv::Point2f> corners;
    double qualityLevel = 0.01;
    double minDistance = 10;
    int blockSize = 3;
    bool useHarrisDetector = false;
    double k = 0.04;
    int maxCorners = 1000;

    GaussianBlur( ImageToProcess, ImageToProcess, cv::Size(9, 9), 2, 2 );

    cv::imwrite("test.jpg", ImageToProcess);

//    cv::goodFeaturesToTrack( ImageToProcess,
//                         corners,
//                         maxCorners,
//                         qualityLevel,
//                         minDistance,
//                         cv::Mat(),
//                         blockSize,
//                         useHarrisDetector,
//                         k );

//    for( int i = 0; i < corners.size(); ++i )
//    {
//        circle( ImageToProcess, corners[i], 4, cv::Scalar(0,255,0), -1, 8, 0 );
//    }
}
