#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/core/core.hpp>

#include <cstddef>

struct Size
{
	std::size_t height;
	std::size_t width;

	Size (std::size_t, std::size_t);
};

class Image
{
private:
	cv::Mat _opencvImage;

public:
	Image (std::size_t, std::size_t);
	Image (const cv::Mat& opencvImage);

	cv::Mat* GetMat ();

	static Image* Substract (Image*, Image*);
	static Image* Addition (Image*, Image*);
private:
	static Image* Operation (Image*, Image*, int op);
};

#endif