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
int main()
{
		int num_files = 439;
		int img_area = 640*480;

		namedWindow("window", WINDOW_AUTOSIZE );
		Mat training_mat(num_files,img_area,CV_32FC1);
		Mat image(1,img_area,CV_32FC1);
		Mat img_mat;
		int file_num=0;
		for(int k=0;k<=438;k++)
		{
			stringstream ss(stringstream::in | stringstream::out);
			ss<<"data/img_"<<k<<".png";
			img_mat = imread(ss.str(),0);
			resize(img_mat,img_mat, Size(640, 480));
			int ii = 0; 
			for (int i = 0; i<img_mat.rows; i++) 
			{
		  	for (int j = 0; j < img_mat.cols; j++) 
		  	{
		      training_mat.at<float>(file_num,ii++) = img_mat.at<uchar>(i,j);
		  	}
			}
			file_num++;

		}
		Mat labels(num_files,1,CV_32FC1);
		int k;
		for(k=0;k<=270;k++)
			labels.at<float>(k, 0) = 1.0;
		for(;k<=438;k++)
			labels.at<float>(k, 0) = 2.0;

		CvSVMParams params;
		params.svm_type = CvSVM::C_SVC;
		params.kernel_type = CvSVM::LINEAR;
		params.gamma = 3;
		params.degree = 3;
		CvSVM svm;
		svm.train(training_mat, labels, Mat(), Mat(), params);
		svm.save("train_data.xml");
	return 0;
}
