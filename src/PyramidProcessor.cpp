#include "PyramidProcessor.h"

#include <cstddef>

#include "DownMinFunction.h"
#include "UpBoxFunction.h"

PyramidProcessor::PyramidProcessor () :
	_downsampling (new DownMinFunction ()),
	_upsampling (new UpBoxFunction ())
{

}

PyramidProcessor::~PyramidProcessor ()
{

}

#include <iostream>

Image* PyramidProcessor::Downscale (Image* source, PyramidProcessor::DownsamplingFunction* f)
{
	if (f == nullptr) {
		f = _downsampling;
	}

	std::size_t width = source->GetMat ()->size ().width;
	std::size_t height = source->GetMat ()->size ().height;

	std::size_t outputWidth = width / 2 + width % 2;
	std::size_t outputHeight = height / 2 + height % 2;

	Image* output = new Image (outputHeight, outputWidth);

	uchar* functionInput = new uchar [4];
	std::size_t outputI, outputJ;

	for (std::size_t i=0;i<height;i+=2) {
		for (std::size_t j=0;j<width;j+=2) {

			// std::cout << i << " " << j << std::endl;

			outputI = i >> 1;
			outputJ = j >> 1;

			functionInput [0] = source->GetMat ()->at<uchar>(i, j);
			functionInput [1] = i + 1 < width ? source->GetMat ()->at<uchar>(i, j + 1) : functionInput [0];
			functionInput [2] = i + 1 < height ? source->GetMat ()->at<uchar>(i + 1, j) : functionInput [0];
			functionInput [3] = i + 1 < height && j + 1 < width ?
				source->GetMat ()->at<uchar>(i + 1, j + 1) : functionInput [1];

			output->GetMat ()->at<uchar>(outputI, outputJ) = f->Execute (functionInput);
		}
	}

	delete functionInput;

	return output;
}

Image* PyramidProcessor::Upscale (Image* source, Size size, PyramidProcessor::UpsamplingFunction* f)
{
	if (f == nullptr) {
		f = _upsampling;
	}

	std::size_t width = source->GetMat ()->size ().width;
	std::size_t height = source->GetMat ()->size ().height;

	std::size_t outputHeight = size.height;
	std::size_t outputWidth = size.width;

	Image* output = new Image (outputHeight, outputWidth);

	uchar* functionOutput = new uchar [4];
	std::size_t outputI, outputJ;

	for (std::size_t i=0;i<height;i++) {
		outputI = i << 1;

		for (std::size_t j=0;j<width;j++) {
			outputJ = j << 1;

			f->Execute (functionOutput, source->GetMat ()->at<uchar> (i, j));

			output->GetMat ()->at<uchar> (outputI, outputJ) = functionOutput [0];
			if (outputJ + 1 < outputWidth) {
				output->GetMat ()->at<uchar> (outputI, outputJ + 1) = functionOutput [1];
			}
			if (outputI + 1 < outputHeight) {
				output->GetMat ()->at<uchar> (outputI + 1, outputJ) = functionOutput [2];
			}
			if (outputI + 1 < outputHeight && outputJ + 1 < outputWidth) {
				output->GetMat ()->at<uchar> (outputI + 1, outputJ + 1) = functionOutput [3];
			}
		}
	}

	delete functionOutput;

	return output;
}
