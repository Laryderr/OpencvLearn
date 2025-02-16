/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-15 16:35:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 14:48:13
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

    /*********************通过运算符重载来实现********************* */

    cv::Mat dst;
	dst = src + cv::Scalar(50, 50, 50);    // 加法
	//dst = src - cv::Scalar(50, 50, 50);  // 减法
	//dst = src / cv::Scalar(2, 2, 2);      // 除法
	
	// 两个图形相乘，是不可以用标量进行操作的
	// penCV 并不支持直接用 * 操作符对 cv::Mat 和 cv::Scalar 进行运算
	//dst = src * cv::Scalar(2, 2, 2);
	// 使用 cv::multiply 函数
	cv::Mat m = cv::Mat::zeros(src.size(), src.type());
	m = cv::Scalar(2, 2, 2);
    
    //逐元素地将 src 图像和 m 矩阵相乘，存储结果到 dst 中
	cv::multiply(src, m, dst);

	cv::imshow("乘法操作", dst);

    /*********************通过api来实现************************ */

	cv::waitKey(0);
	cv::destroyAllWindows();

    

    return 0;


}