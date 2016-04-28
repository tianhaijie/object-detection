#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>	
#include <cv.h>
#include <highgui.h>
#include <cvaux.h>
#include <iostream>
#include<string.h>
// For MySQL Connection
#include <cstdio>
#include <cstdlib>
#include <mysql.h>
	// Defining Constant Variables
#define SERVER "localhost"
#define USER "root"
#define PASSWORD "hgnr"
#define DATABASE "mini"
using namespace std;
using namespace cv;
int main(int argc,char *argv[])
{
		CvSVM svm;
		Mat img_mat;
		int img_area = 640*480;
		Mat image(1,img_area,CV_32FC1);	
		svm.load("train_data.xml");	
		/*
    MYSQL *connect;
    connect = mysql_init(NULL);

    if (!connect)
    {
        cout << "Mysql Initialization Failed";
        return 1;
    }

    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);

    if (connect)
    {
        cout << "Connection Succeeded\n";
    }
    else
    {
        cout << "Connection Failed\n";
    }

    MYSQL_RES *res_set;
    MYSQL_ROW row;
    mysql_query (connect,"select name from img_tab");
    res_set=mysql_store_result(connect);
    unsigned int numrows = mysql_num_rows(res_set);
		row=mysql_fetch_row(res_set);
    
		
		img_mat = imread(row[0],0);*/
		img_mat=imread("uploads/search",0);
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
			printf("car");
			/*namedWindow("car",WINDOW_AUTOSIZE);
			imshow("car",img_mat);*/
		}
		else if(v==2)
		{
			printf("person");
			/*namedWindow("person",WINDOW_AUTOSIZE);
			imshow("person",img_mat);*/
		}
		
		//mysql_close (connect);
	return 0;
}
