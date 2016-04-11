#include "FileManager.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

FileManager::FileManager ()
{

}

FileManager::~FileManager ()
{

}

Image* FileManager::LoadImage (const std::string& filename)
{
	Image* image = new Image (cv::imread(filename.c_str ()));

	return image;
}

void FileManager::SaveImage (Image* image, const std::string& filename)
{
	cv::imwrite (filename.c_str (), *image->GetMat ());
}