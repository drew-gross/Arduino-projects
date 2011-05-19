#include <iostream>
#include <vector>
#include <algorithm>

#include <cv.h>
#include <highgui.h>

int main() {
	cvNamedWindow("Background", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Main", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("LEDImage", CV_WINDOW_AUTOSIZE);

    CvCapture *camera = cvCaptureFromCAM(0);
}