#include <QCoreApplication>
#include "histogram1d.h"
#include <iostream>
int main()
{
    cv::Mat image=cv::imread("../../images/group.jpg",0);
    Histogram1D h;
    // for histogram data
    //cv::MatND histo = h.getHistogram(image);
    //for(int i=0;i<256;i++)
    //    std::cout<<"Value"<<i<<"="<<histo.at<float>(i)<<std::endl;
    // for hisgogram image
    //cv::namedWindow("Histogram");
    //cv::imshow("Histogram",h.getHistogramImage(image));

    // thresholded
    cv::Mat thresholded;
    cv::threshold(image,thresholded,60,255,cv::THRESH_BINARY);
    cv::namedWindow("Output Image");
    cv::imshow("Output Image",thresholded);

    // loopup table
    int dim(256);
    cv::Mat lut(1,&dim,CV_8U);
    for(int i = 0; i < 256; i++){
        lut.at<uchar>(i) = 255 -i;
    }
    cv::Mat lookupImage;
    lookupImage = h.applyLookUp(image,lut);
    cv::namedWindow("lookup");
    cv::imshow("lookup",lookupImage);

    cv::waitKey(0);
    return 1;
}
