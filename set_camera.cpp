/*���ߣ�������
 *�޸��ߣ�
 *�ļ�����������������getCameraVals�����������ǵõ���ǰ����ͷ�Ĳ���
				������calibrateCamera�������������޸�����ͷ�Ĳ���
 *�ļ�����������ʵ���˶�����ͷ�����ĵ�����
 *�������ļ�����ϵ��
 */
#include <iostream>
#include <opencv2/opencv.hpp>  
#include <linux/videodev2.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

using namespace cv;
using namespace std;

void calibrateCamera();
void getCameraVals();
VideoCapture cam(1);
//variables for cam camera
int brightness_slider = 125;
int contrast_slider = 86;
int gain_slider = 77;
int saturation_slider = 34;
int exposure_slider = 500;
int main()
{

	namedWindow("camera 1", WINDOW_AUTOSIZE);
	Mat frame;
	getCameraVals();
	createTrackbar("Brightness", "camera 1", &brightness_slider, 255);
	createTrackbar("Contrast", "camera 1", &contrast_slider, 255);
	createTrackbar("Gain", "camera 1", &gain_slider, 255);
	createTrackbar("Saturation", "camera 1", &saturation_slider, 255);
	createTrackbar("Exposure", "camera 1", &exposure_slider, 2047);
	while (true)
	{
		calibrateCamera();
		cam >> frame;
		imshow("camera 1", frame);
		if (waitKey(3) >= 0) break;
	}
	return(0);
}

/*�������ƣ�getCameraVals
 *������void
 *�������ܣ��õ���ǰ����ͷ�Ĳ���
 *����ֵ����
 */
void getCameraVals()
{
	brightness_slider = cam.get(CV_CAP_PROP_BRIGHTNESS);

	contrast_slider = cam.get(CV_CAP_PROP_CONTRAST);
	gain_slider = cam.get(CV_CAP_PROP_GAIN);
	saturation_slider = cam.get(CV_CAP_PROP_SATURATION);
	exposure_slider = cam.get(CV_CAP_PROP_EXPOSURE);
}

/*�������ƣ�calibrateCamera
 *������void
 *�������ܣ��޸�����ͷ�Ĳ���
 *����ֵ����
 */
void calibrateCamera()
{
	cam.set(CV_CAP_PROP_AUTO_EXPOSURE, 0.25);
	cam.set(CV_CAP_PROP_BRIGHTNESS, brightness_slider);
	cam.set(CV_CAP_PROP_CONTRAST, contrast_slider);
	cam.set(CV_CAP_PROP_GAIN, gain_slider);
	cam.set(CV_CAP_PROP_SATURATION, saturation_slider);
	cam.set(CV_CAP_PROP_EXPOSURE, exposure_slider);
}