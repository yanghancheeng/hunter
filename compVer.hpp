#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
//函数声明
double filter_aver(Mat src);
Mat filter(Mat image, Size size);

void compVer() {

	Mat Img1 = imread("1.jpg");
	int height = Img1.rows;
	int width = Img1.cols;
	Mat Img2 = imread("2.jpg");
	resize(Img2, Img2, Size(width, height));
	Mat Img3 = imread("3.jpg");
	resize(Img3, Img3, Size(width, height));


	//去噪
	Mat result1 = filter(Img1, Size(3, 3));
	Mat result2 = filter(Img2, Size(3, 3));
	Mat result3 = filter(Img3, Size(3, 3));

	//图1
	Mat des;
	des.create(height * 2, width * 3, Img1.type());
	Mat r11 = des(Rect(0, 0, width, height));
	Img1.copyTo(r11);
	Mat r12 = des(Rect(0, height, width, height));
	result1.copyTo(r12);
	//图2
	Mat r21 = des(Rect(width, 0, width, height));
	Img2.copyTo(r21);
	Mat r22 = des(Rect(width, height, width, height));
	result2.copyTo(r22);
	//图3
	Mat r31 = des(Rect(width * 2, 0, width, height));
	Img3.copyTo(r31);
	Mat r32 = des(Rect(width * 2, height, width, height));
	result3.copyTo(r32);

	resize(des, des, Size(1500, 700));
	namedWindow("算术平均值滤波结果", 1);
	cvResizeWindow("算术平均值滤波结果", 1500, 700);
	imshow("算术平均值滤波结果", des);

	waitKey(0);
	destroyAllWindows();
}

double filter_aver(Mat src)
{
	//算术均值滤波
	double sum = 0;
	for (int i = 0; i < src.rows; i++) {
		uchar* data = src.ptr<uchar>(i);
		for (int j = 0; j < src.cols; j++) {
			sum += double(data[j]);
		}
	}
	return sum / double(src.cols * src.rows);
}

Mat filter(Mat image, Size size)
{
	Mat result;
	image.copyTo(result);
	Mat channel[3];
	split(image, channel);
	int l = (size.height - 1) / 2;
	int w = (size.width - 1) / 2;
	for (int i = l; i < result.rows - l; i++) {
		for (int j = w; j < result.cols - w; j++) {
			for (int ii = 0; ii < 3; ii++) {
				result.at<Vec3b>(i, j)[ii] = saturate_cast<uchar>(filter_aver(channel[ii](Rect(j - w, i - l, size.width, size.height))));
			}
		}
	}
	return result;
}