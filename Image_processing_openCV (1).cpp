// Winter Programming Bootcamp
// -----------------------------------------------------------------------------

// Project 01 : Image Rotation Using OpenCV2 in C++
// Problem Statement: To rotate the image on a specific angle entered by user.
// -----------------------------------------------------------------------------

// Name: Sanjay Bhatt
// Course: B.Tech. (CSE)
// Semester: 4th
// Section: A
// University Roll No: 2014834
// -----------------------------------------------------------------------------

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat rotate(Mat src, double angle){

    // creating dst object for stroing the output image
    Mat dst;

    // finding the center of image
    Point2f pt(src.cols/2., src.rows/2.);

    // creating Mat object for stroing after rotation
    Mat r = getRotationMatrix2D(pt, angle, 1.0);

    // finding the new height, width of window
    double abs_cos = abs(r.at<double>(0,0));
    double abs_sin = abs(r.at<double>(0,1));
    double height = src.size().height;
    double width = src.size().width;

    int boundW = (int)(height * abs_sin + width * abs_cos);
    int boundH = (int)(height * abs_cos + width * abs_sin);

    // finding the new center of window
    r.at<double>(0,2) += boundW / 2- width / 2;
    r.at<double>(1,2) += boundH / 2 - height / 2;

    // applie an affine transforation to image.
    warpAffine(src, dst, r, Size(boundW, boundH));

    // returning Mat object for output image file
    return dst;
}



int main()
{
    // reading the image in mat object(Here image is 1.png)
    Mat src = imread("1.png");

    // creating dst object for stroing the output image
    Mat dst;

    int angle;
    cout << "Enter the angle at which you want to rotate: ";
    cin >> angle;

    // rotating the image using rotate function
    dst = rotate(src, angle);

    // displaying the original image
    imshow("src", src);

    // displaying the rotated image
    imshow("dst", dst);

    // to exit press escape
    waitKey(0);
    return 0;
}
