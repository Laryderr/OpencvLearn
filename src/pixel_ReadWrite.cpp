/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2025-02-15 16:35:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2025-02-16 14:23:59
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
    cv::imshow("img_origin", src);
    int w = src.cols;
    int h = src.rows;
    int dims = src.channels();


    /****************************************数组方式遍历********************************************* */
    for(int y = 0;y < h;y ++)
    {
        for(int x = 0; x < w;x ++)
        {
            if ((dims == 1))
            {
                // 灰度图像
				// at方法是Mat里面的1个函数模板，所以要指定模板的数据类型
				int pv = src.at<uchar>(y, x);
				src.at<uchar>(y, x) = 255 - pv;
            }
            else if (dims == 3)
			{
				// RGB图像
				// 是一个模板类 cv::Vec 的特化版本，专门用于存储 3 个 uchar（无符号字符）值，通常表示 BGR 通道。
				// 是一个用于表示固定大小的三维向量的类型，专门用于图像处理中的颜色数据
                // 这个类中的元素类型是 b，表示一个 8 位无符号整数（uchar），每个值的范围从 0 到 255
				cv::Vec3b bgr = src.at<cv::Vec3b>(y, x);
				src.at<cv::Vec3b>(y, x)[0] = 255 - bgr[0];
				src.at<cv::Vec3b>(y, x)[1] = 255 - bgr[1];
				src.at<cv::Vec3b>(y, x)[2] = 255 - bgr[2];
			}
        }
    }

    /****************************************指针方式遍历********************************************* */
    for (int y = 0; y < h; y++)
	{
		// 使用 src.ptr<uchar>(y) 获取当前行的指针;
		// current_y 是指向图像第 y 行第一个像素的指针。
		uchar* current_y = src.ptr<uchar>(y);
		
		for (int x = 0; x < w; x++)
		{
			if (dims == 1)
			{
				// 灰度图像
				int pv = *current_y;
                //先解引用赋值再++
				*current_y++ = 255 - pv;
			}
			else if (dims == 3)
			{
				// RGB图像
				*current_y++ = 255 - *current_y;
				*current_y++ = 255 - *current_y;
				*current_y++ = 255 - *current_y;
			}
		}
	}

    cv::imshow("img", src);
	cv::waitKey(0);
	cv::destroyAllWindows();
    
    

    return 0;


}