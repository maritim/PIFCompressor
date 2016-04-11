#include "Image.h"

#include <opencv2/imgproc/imgproc.hpp>

Size::Size (std::size_t height, std::size_t width) :
	width (width),
	height (height)
{

}

Image::Image (std::size_t height, std::size_t width) :
	_opencvImage (height, width, CV_8UC1)
{

}

Image::Image (const cv::Mat& opencvImage)
{
	cv::cvtColor(opencvImage, _opencvImage, CV_BGR2GRAY);

	// _opencvImage.convertTo (_opencvImage, CV_8UC1);
}

cv::Mat* Image::GetMat ()
{
	return &_opencvImage;
}

Image* Image::Substract (Image* first, Image* second)
{
	return Operation (first, second, -1);
}

Image* Image::Addition (Image* first, Image* second)
{
	return Operation (first, second, 1);
}

Image* Image::Operation (Image* first, Image* second, int op)
{
	std::size_t height = first->_opencvImage.size ().height;
	std::size_t width = second->_opencvImage.size ().width;

	Image* image = new Image (height, width);

	for (std::size_t i=0;i<height;i++) {
		for (std::size_t j=0;j<width;j++) {
			image->_opencvImage.at<uchar> (i, j) = (uchar)
				((int) first->_opencvImage.at<uchar> (i, j) + op *
				 (int) second->_opencvImage.at<uchar> (i, j));
		}
	}

	return image;
}
