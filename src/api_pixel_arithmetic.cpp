/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-15 16:35:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 14:51:07
 * @FilePath: /opencv/img_read&show.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%
 */
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

/**
 *  src.at<uchar>(y, x);;  // 单通道图像获取某个像素值
    src.at<cv::Vec3b>(y, x);  // RGB三通道图像获取某个像素值
    src.ptr<uchar>(y);  // 获取单通道图像某一行的指针
 */

int main()
{
    cv::Mat src = cv::imread("/home/haong/图片/微信图片_20250215163934.jpg");

    if (src.empty())
    {
        cout << "不能正确加载图片" <<endl;
        return -1;
    }

    /*********************通过api来实现************************ */
    
    cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(50, 50, 50);

	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());
	
	// 加法
	cv::add(src, m, dst);
	// 减法
	//cv::subtract(src, m, dst);
	// 除法
	//cv::divide(src, m, dst);
	cv::imshow("api算术操作", dst);

	cv::waitKey(0);
	cv::destroyAllWindows();

    

    return 0;


}