﻿// Image_Choose.cpp: 定义控制台应用程序的入口点。
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp> // for camera

using namespace cv;
using namespace std;

int main()
{
	int image_index = 455;
	char str[256];
	namedWindow("src", 1);
	Mat frame;
	VideoCapture capture("F:\\person\\20180801_033136_663.mp4");
	capture >> frame;

	while (1)
	{
		if (!capture.read(frame))
		{
			cout << "读取视频0失败" << endl;
			break;
		}

		cv::imshow("src", frame);
		char wk = waitKey(0);
		if ((27 == wk) || ('q' == wk))
		{
			break;
		}
		else if ('s' == wk)
		{
			sprintf(str, "F:\\person\\2\\%d.jpg", image_index);
			cv::imwrite(str, frame);
			printf("saving %d image\n", image_index);
			image_index++;
		}
	}
    return 0;
}

int main111()
{
	int image_index = 1;
	char str[256];
	Mat frame;
	
	for(int i=0; i<2260; i++)
	{
		//sprintf(str, "F:\\2501-3000\\human_%06d.jpg", i); //human_ % 06d.jpg
		sprintf(str, "F:\\sample2\\sample2\\human_%06d.jpg", i);
		frame = imread(str);
		if (!frame.data)
		{
			cout << "读取视频0失败" << endl;
			break;
		}
		sprintf(str, "F:\\sample2\\2260\\%d.jpg", image_index);
                cv::imwrite(str, frame);
		image_index++;
	}
	return 0;
}
