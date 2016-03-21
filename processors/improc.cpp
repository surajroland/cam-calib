#include "processors/improc.h"

void FeatureDetectors::Mat2Qpix(cv::Mat matImage)
{
    switch ( matImage.type() )
    {
        // 8-bit, 4 channel
        case CV_8UC4:
        {
            outQImage = QImage( matImage.data, matImage.cols, matImage.rows, matImage.step, QImage::Format_RGB32 );
        }

        // 8-bit, 3 channel
        case CV_8UC3:
        {
            outQImage = QImage( matImage.data, matImage.cols, matImage.rows, matImage.step, QImage::Format_RGB888 );
            outQImage = outQImage.rgbSwapped();
        }

        // 8-bit, 1 channel
        case CV_8UC1:
        {
            static QVector<QRgb>  sColorTable;
            // only create our color table once
            if ( sColorTable.isEmpty() )
            {
                for ( int i = 0; i < 256; ++i )
                sColorTable.push_back( qRgb( i, i, i ) );
            }
            outQImage = QImage( matImage.data, matImage.cols, matImage.rows, matImage.step, QImage::Format_Indexed8 );
            outQImage.setColorTable( sColorTable );
        }

        default:
            qWarning() << "FeatureDetectors::Mat2Qpix(cv::Mat) - cv::Mat image type not handled in switch:" << matImage.type();
            break;
    }
}


void FeatureDetectors::QImage2Mat(QImage inputImage)
{
      switch ( inputImage.format() )
      {
         // 8-bit, 4 channel
         case QImage::Format_ARGB32:
         {
            outMatImage = cv::Mat( inputImage.height(), inputImage.width(), CV_8UC4, const_cast<uchar*>(inputImage.bits()), inputImage.bytesPerLine() );
         }

         // 8-bit, 3 channel
         case QImage::Format_RGB888:
         {
            QImage  swapped = inputImage.rgbSwapped();
            outMatImage = cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
         }

         // 8-bit, 1 channel
         case QImage::Format_Indexed8:
         {
            outMatImage = cv::Mat( inputImage.height(), inputImage.width(), CV_8UC1, const_cast<uchar*>(inputImage.bits()), inputImage.bytesPerLine() );
         }

         default:
            qWarning() << "FeatureDetectors::QImage2Mat(QImage inputImage) - QImage format not handled in switch:" << inputImage.format();
            break;
     }
}

void FeatureDetectors::setFilter(filter _h)
{
    h = _h;
}

