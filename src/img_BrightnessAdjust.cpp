/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-16 14:56:09
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 15:31:36
 * @FilePath: /src/opencvlearn/src/img_BrightnessAdjust.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;


// 全局变量
cv::Mat src, dst, m;
int max_value = 100;  // 滑块的最大值
int lightness = 50;   // 初始亮度值

void on_track(int val, void*)
{
	m = cv::Scalar(val, val, val);
	cv::add(src, m, dst);

	// 显示结果
	cv::imshow("调节亮度", dst);
	
}

int main()
{ 
	src = cv::imread("/home/haong/图片/微信图片_20250215163934.jpg");
	
	m = cv::Mat::zeros(src.size(), src.type());
	dst = cv::Mat::zeros(src.size(), src.type());
	cv::namedWindow("调节亮度", cv::WINDOW_FREERATIO);
	
    /**
     * void cv::createTrackbar(const String& trackbarname, const String& winname,int* value, int count, TrackbarCallback onChange = 0 ); 
     * trackbarname：滚动条的名称，通常用于显示在窗口上。
        winname：滚动条所在的窗口名称，这个窗口是通过 cv::imshow() 创建的。
        value：滚动条的初始值（通常是一个整数指针）。这个值会随着滚动条的滑动而更新。
        count：滚动条的最大值。通常是整数，定义了滚动条的范围。
        onChange：可选的回调函数，当滚动条的值发生变化时会触发此函数。它的参数是当前滚动条的值。
     */
	cv::createTrackbar("Value Bar:", "调节亮度", &lightness, max_value, on_track);

	// 手动调用回调函数以初始化显示
	on_track(lightness, 0);
	
    cv::waitKey(0);
	return 0;
}
