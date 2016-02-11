#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>
#include <cvaux.h>
#include <iostream>
#include<string.h>
using namespace std;
using namespace cv;
int main(int argc,char *argv[])
{
		svm.load("train_data.xml");	
		img_mat = imread(argv[1],0);
		resize(img_mat,img_mat, Size(640, 480));
		int ii = 0;
		for (int i = 0; i<img_mat.rows; i++) 
		{
	  	for (int j = 0; j < img_mat.cols; j++) 
	  	{
	      image.at<float>(0,ii++) = img_mat.at<uchar>(i,j);
	  	}
		}
		int v=svm.predict(image);
		if(v==1)
		{
			printf("\ncar\n");
		//	putText(img_mat, "car", Point(10, 30), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
		}
		else if(v==2)
		{
			printf("\nperson\n");
		//	putText(img_mat, "person", Point(10, 30), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
		}
			else if(v==3)
		{
			printf("\nbike\n");
		//	putText(img_mat, "person", Point(10, 30), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
		}
			else if(v==4)
		{
			printf("\ncycle\n");
		//	putText(img_mat, "person", Point(10, 30), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0), 2.0);
		}
		else
			printf("not found");
		return 0;
}
