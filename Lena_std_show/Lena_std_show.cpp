#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
    // read an image
    cv::Mat image=cv::imread("../lena_std.tif");
    // create image window named "Lena Std"
    cv::namedWindow("Lena Std");

    cv::imshow("Lena Std",image);
    cv::waitKey(5000);

    return 1;
}
