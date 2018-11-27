#include <opencv2\opencv.hpp>
#include <fstream>
#include <tchar.h>

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	
	VideoCapture capture1("../.mp4");//读入左路视频
	Mat image01;
	capture1 >> image01;
	resize(image01, image01, Size(3840 ,1280), 0, 0, INTER_LINEAR);
	imwrite("11.jpg", image01);
	VideoWriter  panovideo = VideoWriter("out.avi", CV_FOURCC('X', 'V', 'I', 'D'), 25, cvSize(image01.cols, image01.rows), true);//图像大小为全景图的尺寸

	while (true)
	{
		capture1 >> image01;
		resize(image01, image01, Size(3840, 1280), 0, 0, INTER_LINEAR);
		panovideo << image01;		
	}
	return 0;
}
