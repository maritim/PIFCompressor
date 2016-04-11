#include "PIFCompressor.h"

#include "FileManager.h"
#include "Image.h"

#include "ImagePyramid.h"
#include "PIFFile.h"

#include "PyramidProcessor.h"
#include "PIFConvertor.h"

#include "PIFViewer.h"

#include "FileStream.h"

#include "Compressor.h"

#include <cstddef>
#include <vector>

PIFCompressor::PIFCompressor ()
{

}

PIFCompressor::~PIFCompressor ()
{

}

#include <iostream>

void PIFCompressor::Compress (const std::string& inputFilename, const std::string& outputFilename)
{
	Image* image = FileManager::Instance ()->LoadImage (inputFilename);

	std::size_t width = image->GetMat ()->size ().width;
	std::size_t height = image->GetMat ()->size ().height;

	ImagePyramid* pyramid = new ImagePyramid (image);

	Image* original = image;

	while (width > 1 || height > 1) {
		Image* downscale = PyramidProcessor::Instance ()->Downscale (image);
		Image* upscale = PyramidProcessor::Instance ()->Upscale (downscale, Size (height, width));

		Image* residue = Image::Substract (image, upscale);

		pyramid->AddResidue (residue);

		if (image != original) {
			delete image;
		}
		delete upscale;
		image = downscale;

		width = width / 2 + width % 2;
		height = height / 2 + height % 2;
	}

	pyramid->SetFinalImage (image);

	PIFFile* file = new PIFFile ();

	PIFConvertor::Instance ()->Image2PIF (file, pyramid);

	uchar* compressedData; std::size_t compressedSize;
	Compressor::Instance ()->Compress (file->data, file->dataSize, compressedData, compressedSize);
	
	delete file->data;
	file->data = compressedData;
	file->dataSize = compressedSize;

	FileStream::Instance ()->SavePIFFile (file, outputFilename);

	delete file->data;
	delete file;
	delete pyramid;
}

void PIFCompressor::Decompress (const std::string& inputFilename, const std::string& outputFilename)
{
	PIFFile* file = new PIFFile ();

	FileStream::Instance ()->LoadPIFFile (file, inputFilename);

	uchar* uncompressedData; std::size_t uncompressedSize;
	Compressor::Instance ()->Uncompress (file->data, file->dataSize, uncompressedData, uncompressedSize);

	delete file->data;
	file->data = uncompressedData;
	file->dataSize = uncompressedSize;

	Image* output = new Image (file->height, file->width);

	ImagePyramid* pyramid = new ImagePyramid (output);

	PIFConvertor::Instance ()->PIF2Image (pyramid, file);

	Image* image = pyramid->GetFinalImage ();

	for (std::size_t i=pyramid->GetLevelsCount () - 1; i > 0;i--) {
		Image* residue = pyramid->GetResidue (i - 1);

		Size size (residue->GetMat ()->size ().height,
			residue->GetMat ()->size ().width);

		Image* upscale = PyramidProcessor::Instance ()->Upscale (image, size);

		delete image;

		image = Image::Addition (upscale, residue);

		delete residue;
	}

	FileManager::Instance ()->SaveImage (image, outputFilename);

	// delete pyramid;
}