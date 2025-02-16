/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-15 16:35:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-15 22:57:00
 * @FilePath: /opencv/img_read&show.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%
 */
#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main()
{
    cv::Mat src = cv::imread("/home/haong/图片/微信图片_20250215163934.jpg");

    if (src.empty())
    {
        cout << "不能正确加载图片" <<endl;
        return -1;
    }
    //5*5和800*800矩阵，每个元素类型是32位float
    cv::Mat Mat1 = cv::Mat::zeros(cv::Size(8, 8), CV_8UC3);
    cv::Mat Mat2 = cv::Mat::zeros(cv::Size(800, 800), CV_8UC3);

    //创建了一个三通道的标量，每个通道的值都是 127。因此，这将给 m3 矩阵的每个像素赋值为 (127, 127, 127)，也就是一个灰色图像
    Mat2 = cv::Scalar(127,127,127);

    /*cout << "宽度为：" << Mat1.cols << " 高度为：" << Mat1.rows << " 通道数：" << Mat1.channels() << endl;
    cout << Mat1 << endl;
    Mat1 = cv::Scalar(127, 127, 127);*/

    cv::Mat hsv, gray;
	cv::cvtColor(src, hsv, cv::COLOR_BGR2HSV);
	cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cout << "✅ 图片加载成功！图像尺寸: " << src.rows << " x " << src.cols << endl;

    
    //允许窗口 自由缩放，但保持原始图像比例
    cv::namedWindow("my_window",cv::WINDOW_FREERATIO);

    /*cv::imshow("RGB", src);  
	cv::imshow("HSV", hsv);  
	cv::imshow("GRAY", gray);*/

    cv::imshow("Mat1",Mat1);  
    cv::imshow("Mat2",Mat2);  

    /* 图像对象的赋值*/
    cv::Mat m1,m2;

    //下面克隆和拷贝则会创建一个新的内存空间
    m1 = src.clone();
    src.copyTo(m2);
    
    // 直接赋值创建1个新Mat对象，指针还是指向同一个Data Block；
    // 所以这里的m3的像素值改变，而src也会随着一起改变。
    cv::Mat m3 = src;
    m3 = cv::Scalar(0, 0, 255);
    cv::imshow("m1",m1);
    cv::imshow("res", src);

    cv::waitKey(0);
    cv::destroyAllWindows();
    
    

    return 0;


}