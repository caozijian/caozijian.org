#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    // read an image
    cv::Mat image=cv::imread("../lena_std.tif");
    // create image window named "Lena Std"
    cv::namedWindow("Lena Std");

    cv::imshow("Lena Std",image);
    // do some operation
    cv::Mat result;
    cv::flip(image,result,1);
    // positive for horizontal, 0 for vertical,negative for both

    cv::namedWindow("Output Image");
    cv::imshow("Output Image",result);
    cv::waitKey(5000);
    // file extension determines which codec will be used to save the image.
    cv::imwrite("../output.bmp",result);


    return 1;
}
