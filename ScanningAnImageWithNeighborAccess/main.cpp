#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv.hpp>

void sharpen(const cv::Mat &image, cv::Mat &result);

int main()
{

    cv::Mat image = cv::imread("../../images/boldt.jpg");
    // RGB to Gray
    cv::cvtColor(image,image,CV_BGR2GRAY);
    cv::namedWindow("original");
    cv::imshow("original",image);
    sharpen(image,image);
    cv::namedWindow("sharpen");
    cv::imshow("sharpen",image);
    cv::waitKey(0);
    return 1;
}

void sharpen(const cv::Mat &image, cv::Mat &result){
    result.create(image.size(),image.type());
    for (int j = 1; j < image.rows-1;j++){
        const uchar* previous = image.ptr<const uchar>(j-1);
        const uchar* current = image.ptr<const uchar>(j);
        const uchar* next = image.ptr<const uchar>(j+1);

        uchar* output = result.ptr<uchar>(j);
        for (int i = 1; i < image.cols-1;i++){
            *output++ = cv::saturate_cast<uchar>(5*current[i]-current[i-1]-current[i+1]-previous[i]-next[i]);
        }
    }
    //
    result.row(0).setTo(cv::Scalar(0));
    result.row(result.rows-1).setTo(cv::Scalar(0));
    result.col(0).setTo(cv::Scalar(0));
    result.col(result.cols-1).setTo(cv::Scalar(0));
}
