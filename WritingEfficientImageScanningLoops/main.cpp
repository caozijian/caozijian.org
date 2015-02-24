#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void colorReduce_1(cv::Mat &image, int div=64);
void colorReduce_2(cv::Mat &image, int div=64);
void colorReduce_3(cv::Mat &image, int div=64);
void colorReduce_4(cv::Mat &image, int div=64);
void colorReduce_5(cv::Mat &image, int div=64);


int main()
{

    double duration;

    cv::Mat image=cv::imread("../../images/boldt.jpg");
    // method 1
    duration = static_cast<double>(cv::getTickCount());
    colorReduce_1(image);
    duration = static_cast<double>(cv::getTickCount())-duration;
    duration/= cv::getTickFrequency(); // unit of ms
    std::cout<<"reduce color method 1 : "<<duration<<std::endl;
    // method 2
    duration = static_cast<double>(cv::getTickCount());
    colorReduce_2(image);
    duration = static_cast<double>(cv::getTickCount())-duration;
    duration/= cv::getTickFrequency(); // unit of ms
    std::cout<<"reduce color method 2 : "<<duration<<std::endl;
    // method 3
    duration = static_cast<double>(cv::getTickCount());
    colorReduce_3(image);
    duration = static_cast<double>(cv::getTickCount())-duration;
    duration/= cv::getTickFrequency(); // unit of ms
    std::cout<<"reduce color method 3 : "<<duration<<std::endl;
    // method 4
    duration = static_cast<double>(cv::getTickCount());
    colorReduce_4(image);
    duration = static_cast<double>(cv::getTickCount())-duration;
    duration/= cv::getTickFrequency(); // unit of ms
    std::cout<<"reduce color method 4 : "<<duration<<std::endl;
    // method 5
    duration = static_cast<double>(cv::getTickCount());
    colorReduce_5(image);
    duration = static_cast<double>(cv::getTickCount())-duration;
    duration/= cv::getTickFrequency(); // unit of ms
    std::cout<<"reduce color method 5 : "<<duration<<std::endl;
    return 1;
}

// reduceColor Table 2.1 (1)
void colorReduce_1(cv::Mat &image, int div){
    int nl = image.rows;
    int nc = image.cols*image.channels();

    for(int j=0;j<nl;j++){
        uchar* data = image.ptr<uchar>(j);
        for (int i=0;i<nc;i++){
            // process each pixel
            // $2.3 achieved by taking advantage of an integer
            // division that floors te division result to the nearest lower integer.
            data[i]=data[i]/div*div+div/2;
            // end of pixel processing
        }
    }
}
//reduceColor Table 2.1(2)
void colorReduce_2(cv::Mat &image, int div){
    int nl = image.rows;
    int nc = image.cols*image.channels();

    for(int j=0;j<nl;j++){
        uchar* data = image.ptr<uchar>(j);
        for (int i=0;i<nc;i++){
            // process each pixel
            *data++ = *data/div*div+div/2;
            // end of pixel processing
        }
    }
}

//reduceColor Table 2.1(3)
void colorReduce_3(cv::Mat &image, int div){
    int nl = image.rows;
    int nc = image.cols*image.channels();

    for(int j=0;j<nl;j++){
        uchar* data = image.ptr<uchar>(j);
        for (int i=0;i<nc;i++){
            // process each pixel
            data[i] = data[i]-data[i]%div+div/2;
            // end of pixel processing
        }
    }
}
//reduceColor Table 2.1(4)
void colorReduce_4(cv::Mat &image, int div){
    int nl = image.rows;
    int nc = image.cols*image.channels();

    double i = 0;

    while(pow(2,i) < div)
    {
        i++;
    }
    int n = i;
    if (pow(2,n) == div)
    {
        uchar mask = 0xFF<<n;
        for(int j=0;j<nl;j++){
            uchar* data = image.ptr<uchar>(j);
            for (int i=0;i<nc;i++){
                // process each pixel
                *data++ = *data&mask + div/2;
                // end of pixel processing
            }
        }
    }
}

//reduceColor Table 2.1(5)
void colorReduce_5(cv::Mat &image, int div){
    int nl = image.rows;

    double i = 0;

    while(pow(2,i) < div)
    {
        i++;
    }
    int n = i;
    if (pow(2,n) == div)
    {
        uchar mask = 0xFF<<n;
        for(int j=0;j<nl;j++){
            uchar* data = image.ptr<uchar>(j);
            for (int i=0;i<image.cols*image.channels();i++){
                // process each pixel
                *data++ = *data&mask + div/2;
                // end of pixel processing
            }
        }
    }
}
