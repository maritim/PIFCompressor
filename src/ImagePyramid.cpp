#include "ImagePyramid.h"

ImagePyramid::ImagePyramid (Image* original) :
	_original (original)
{

}

ImagePyramid::~ImagePyramid ()
{
	delete _original;
	delete _final;

	for (auto it : _residues) {
		delete it;
	}
}

std::size_t ImagePyramid::GetDataSize ()
{
	std::size_t output = 0;

	for (auto it : _residues) {
		output += it->GetMat ()->size ().width *
			it->GetMat ()->size ().height;
	}

	output += _final->GetMat ()->size ().width *
		_final->GetMat ()->size ().height;

	return output;
}

std::size_t ImagePyramid::GetWidth ()
{
	return _original->GetMat ()->size ().width;
}

std::size_t ImagePyramid::GetHeight ()
{
	return _original->GetMat ()->size ().height;
}

std::size_t ImagePyramid::GetLevelsCount ()
{
	return _residues.size ();
}

Image* ImagePyramid::GetFinalImage ()
{
	return _final;
}

void ImagePyramid::SetFinalImage (Image* image)
{
	_final = image;
}

Image* ImagePyramid::GetResidue (std::size_t pos)
{
	return _residues [pos];
}

void ImagePyramid::AddResidue (Image* residue)
{
	_residues.push_back (residue);
}
