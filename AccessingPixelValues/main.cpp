#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

// function decleration
void salt(cv::Mat &image, int n);
void colorReduce(cv::Mat &image, int div=64);

int main()
{

    cv::Mat image=cv::imread("../../images/boldt.jpg");
    // demo for $2.2
    //salt(image,3000);
    // demo for $2.3
    colorReduce(image);
    cv::namedWindow("Image");
    cv::imshow("Image",image);
    cv::waitKey(5000);

    return 1;
}

// $2.2
void salt(cv::Mat &image,int n){
    for(int k=0; k < n; k++ ){
        //rand()
        int i = qrand()%image.cols;
        int j = qrand()%image.rows;
        if(image.channels()==1){
            image.at<uchar>(j,i)=255;
        }else if(image.channels()==3){
            image.at<cv::Vec3b>(j,i)[0] = 255;
            image.at<cv::Vec3b>(j,i)[1] = 255;
            image.at<cv::Vec3b>(j,i)[2] = 255;
        }
    }
}

// $2.3
void colorReduce(cv::Mat &image, int div){
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
