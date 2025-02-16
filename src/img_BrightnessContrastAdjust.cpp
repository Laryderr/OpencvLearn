#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void on_lightness(int lightness, void* userdata)
{
	cv::Mat src = *((cv::Mat*)userdata);

	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(lightness, lightness, lightness);

	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
	
	// dst = alpha * src + beta * m + gamma
	// alpha = 1， beta = 0， gamma =0, dst = alpha + gamma 就是调整亮度了
	cv::addWeighted(src, 1.0, m, 2, lightness, dst);

	// 显示结果
	cv::imshow("亮度和对比度调整", dst);
	
}

void on_contrast(int lightness, void* userdata)
{
	cv::Mat src = *((cv::Mat*)userdata);

	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(lightness, lightness, lightness);

	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

	double contrast = lightness / 100.0;

	
	// alpha = contrast， beta = 0， gamma = 0, dst = src * alpha 就是调整亮度了
	cv::addWeighted(src, contrast, m, 0.0, 0, dst);

	// 显示结果
	cv::imshow("亮度和对比度调整", dst);
}

int main()
{ 
	cv::Mat src = cv::imread("/home/haong/图片/微信图片_20250215163934.jpg");

	int max_value = 100;  // 滑块的最大值
	int lightness = 50;   // 初始亮度值
	int contrast_value = 100;  // 默认对比度
	cv::namedWindow("亮度和对比度调整", cv::WINDOW_FREERATIO);
	

	cv::createTrackbar("Value Bar:", "亮度和对比度调整", &lightness, max_value, on_lightness, (void*)&src);
	cv::createTrackbar("Contrast Bar:", "亮度和对比度调整", &contrast_value, max_value, on_contrast, (void*)&src);

	// 手动调用回调函数以初始化显示
	on_lightness(lightness, &src);
	
	cv::waitKey(0);
	return 0;
}
