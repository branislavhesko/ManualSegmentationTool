#include "mouse_control_functions.h"
#include "pch.h"
#include <vector>
#include "opencv2/opencv.hpp"

void polygonSegmentationMouseControl(int event, int x, int y, int flag, void * points)
{
	auto *polyPoints = static_cast<std::vector<cv::Point> *> (points);

	if (event == cv::EVENT_LBUTTONUP) {
		polyPoints->push_back(cv::Point(x, y));
	}

}
