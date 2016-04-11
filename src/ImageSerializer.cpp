#include "ImageSerializer.h"

ImageSerializer::ImageSerializer ()
{

}

ImageSerializer::~ImageSerializer ()
{

}

/*
 * Raster serialization.
*/

void ImageSerializer::Serialize (uchar* stream, Image* image)
{
	std::size_t width = image->GetMat ()->size ().width;
	std::size_t height = image->GetMat ()->size ().height;

	std::size_t streamIter = 0;

	for (std::size_t i=0;i<height;i++) {
		for (std::size_t j=0;j<width;j++) {
			stream [streamIter ++] = image->GetMat ()->at<uchar> (i, j);
		}
	}
}

void ImageSerializer::Deserialize (uchar* stream, Image* image)
{
	std::size_t width = image->GetMat ()->size ().width;
	std::size_t height = image->GetMat ()->size ().height;

	std::size_t streamIter = 0;

	for (std::size_t i=0;i<height;i++) {
		for (std::size_t j=0;j<width;j++) {
			image->GetMat ()->at<uchar> (i, j) = stream [streamIter ++];
		}
	}
}