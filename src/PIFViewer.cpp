#include "PIFViewer.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

PIFViewer::PIFViewer ()
{

}

PIFViewer::~PIFViewer ()
{

}

void PIFViewer::Show (Image* image)
{
	cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );

	cv::imshow("Display window", *image->GetMat ());

	cv::waitKey(0);
}