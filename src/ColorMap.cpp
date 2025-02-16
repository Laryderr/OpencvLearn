/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-16 19:26:01
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 19:34:45
 * @FilePath: /src/opencvlearn/src/ColorMap.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{ 
	cv::Mat src = cv::imread("/home/haong/图片/微信图片_20250215163934.jpg");
	cv::Mat dst = cv::Mat::zeros(src.size(), src.type());

    /*cv::applyColorMap 用于将颜色映射应用到图像。它将 src 图像的数据转换为具有伪彩色效果的图像，并将结果存储在 dst 中。

    src：输入图像。注意，src 必须是单通道图像（如灰度图像），如果是彩色图像，applyColorMap 会转换失败。
    dst：输出图像，存储应用颜色映射后的结果。
    cv::COLORMAP_JET：指定使用的颜色映射类型，这里使用了 JET 颜色映射。

    cv::COLORMAP_JET 是 OpenCV 中内置的颜色表之一，它将灰度值映射到彩虹色图（从蓝色到红色）：

    低值（如黑色）映射为 蓝色。
    高值（如白色）映射为 红色。
    中间的值会被映射到 绿色、黄色、橙色 等中间色。

    使用 applyColorMap 后，图像的显示效果会发生明显变化，它更像是一个热图，适合用于表示某些数值范围的数据。*/

	cv::applyColorMap(src, dst, cv::COLORMAP_SPRING);
    
    
	cv::namedWindow("result", cv::WINDOW_FREERATIO);
	cv::imshow("result", dst);
	cv::waitKey(0);
	return 0;
}
