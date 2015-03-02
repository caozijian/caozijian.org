#ifndef HISTOGRAM1D_H
#define HISTOGRAM1D_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Histogram1D
{
private:
    int histSize[1];
    float hranges[2];
    const float *ranges[1];
    int channels[1];
public:
    Histogram1D();
    ~Histogram1D();
    cv::MatND getHistogram(const cv::Mat &image);
    cv::Mat getHistogramImage(const cv::Mat &image);
    cv::Mat applyLookUp(const cv::Mat &image,const cv::Mat &lookup);
    cv::Mat stretch(const cv::Mat &image,int minValue);
    cv::Mat equalizeHist(const cv::Mat &image);
};

#endif // HISTOGRAM1D_H
