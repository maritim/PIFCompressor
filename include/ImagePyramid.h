#ifndef IMAGEPYRAMID_H
#define IMAGEPYRAMID_H

#include "Image.h"

#include <vector>

class ImagePyramid
{
private:
	Image* _original, *_final;
	std::vector<Image*> _residues;
public:
	ImagePyramid (Image*);
	~ImagePyramid ();

	std::size_t GetWidth ();
	std::size_t GetHeight ();
	std::size_t GetLevelsCount ();
	std::size_t GetDataSize ();

	Image* GetResidue (std::size_t pos);
	Image* GetFinalImage ();

	void AddResidue (Image* image);
	void SetFinalImage (Image* image);
};

#endif