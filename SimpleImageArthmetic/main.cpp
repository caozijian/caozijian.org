#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv.hpp>
#include <iostream>

int main()
{
    cv::Mat rain = cv::imread("../../images/rain.jpg");
    cv::Mat boldt = cv::imread("../../images/boldt.jpg");
    // attention logo.bmp.
    cv::Mat logo = cv::imread("../../images/logo.bmp");
    cv::Mat result;
    cv::Mat imageROI;

    //cv::addWeighted(rain,0.7,boldt,0.9,0.,result);
    // corresponding operator overloaded in OpenCV2.
    // result = 0.7*rain+0.9*boldt;
    // rain.jpg is a color image, have 3 channels. covert to gray
    cv::cvtColor(rain,rain,CV_BGR2GRAY);
    std::cout<<"rain have"<<rain.channels()<<"channels"<<std::endl;
    std::vector<cv::Mat>planes;
    cv::split(boldt,planes);
    planes[0] += rain;
    cv::merge(planes,result);
    // insert logo
    imageROI =result(cv::Rect(385,270,logo.cols,logo.rows));
    //cv::addWeighted(imageROI,1.0,logo,0.3,0.,imageROI);
    // insert logo by image mask
    /*
    http://docs.opencv.org/2.4.4/modules/highgui/doc/reading_and_writing_images_and_video.html?highlight=imread#cv2.imread
    C++: Mat imread(const string& filename, int flags=1 )
    Parameters:

    filename – Name of file to be loaded.
    flags –

    Flags specifying the color type of a loaded image:
        CV_LOAD_IMAGE_ANYDEPTH - If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
        CV_LOAD_IMAGE_COLOR - If set, always convert image to the color one
        CV_LOAD_IMAGE_GRAYSCALE - If set, always convert image to the grayscale one

        >0 Return a 3-channel color image.
            Note
            In the current implementation the alpha channel, if any, is stripped from the output image. Use negative value if you need the alpha channel.
        =0 Return a grayscale image.
        <0 Return the loaded image as is (with alpha channel).

    */
    cv::Mat mask = cv::imread("../../images/logo.bmp",CV_LOAD_IMAGE_GRAYSCALE);
    std::cout<<"mask have "<<mask.channels()<<std::endl;
    std::cout<<"logo have "<<logo.channels()<<std::endl;
    logo.copyTo(imageROI,mask);
    cv::namedWindow("result");
    cv::imshow("result",result);
    cv::namedWindow("original");
    cv::imshow("original",boldt);
    cv::namedWindow("imageROI");
    cv::imshow("imageROI",imageROI);
    cv::waitKey(0);
    return 1;
}

