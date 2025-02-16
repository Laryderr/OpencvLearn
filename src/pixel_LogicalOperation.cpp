/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-16 19:41:19
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 20:21:26
 * @FilePath: /src/opencvlearn/src/pixel_LogicalOperation.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;


int main()
{ 
	cv::Mat m1 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
	cv::Mat m2 = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);

	// 绘制矩形
	// cv::Rect(x, y, w, h) 矩形的左上角坐标和宽、高
	cv::rectangle(m1, cv::Rect(100, 100, 80, 80), cv::Scalar(255, 255, 0), -1);//-1表示填充整个矩形
	cv::rectangle(m2, cv::Rect(150, 150, 80, 80), cv::Scalar(0, 255, 255), -1);
	

	// 像素位操作
	cv::Mat dst;
	// m1和m2进行与运算，只留下G通道与为运算后为1的颜色
	//cv::bitwise_and(m1, m2, dst);//对两个图像的每个像素进行 与 操作。只有两个像素的对应位都为 1 时，结果才为 1。常用于提取图像中的特定区域

	// 或运算
	cv::bitwise_or(m1, m2, dst);//对两个图像的每个像素进行 或 操作。只要两个像素的对应位有一个为 1，结果就为 1。常用于图像合成或将两个图像合并成一个图像

	// 非运算
	//cv::bitwise_not(m2, dst);//对图像的每个像素进行 非 操作。将每个像素的二进制位反转，即 0 变成 1，1 变成 0。常用于图像反转或二值图像的反转


	cv::imshow("m1", m1);
	cv::imshow("m2", m2);
	cv::imshow("dst", dst);
	cv::waitKey(0);
	return 0;
}
