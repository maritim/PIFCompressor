#include "PIFConvertor.h"

#include "ImageSerializer.h"

PIFConvertor::PIFConvertor ()
{

}

PIFConvertor::~PIFConvertor ()
{

}

void PIFConvertor::Image2PIF (PIFFile* file, ImagePyramid* pyramid)
{
	file->width = pyramid->GetWidth ();
	file->height = pyramid->GetHeight ();
	file->levels = pyramid->GetLevelsCount ();
	file->dataSize = pyramid->GetDataSize ();

	file->data = new unsigned char [file->dataSize];

	std::size_t iter = 0;

	for (std::size_t i=0;i<pyramid->GetLevelsCount ();i++) {
		Image* image = pyramid->GetResidue (i);

		std::size_t size = image->GetMat ()->size ().width *
			image->GetMat ()->size ().height;

		ImageSerializer::Instance ()->Serialize (file->data + iter, image);

		iter += size;
	}

	ImageSerializer::Instance ()->Serialize (file->data + iter, pyramid->GetFinalImage ());
}

void PIFConvertor::PIF2Image (ImagePyramid* pyramid, PIFFile* file)
{
	std::size_t width = file->width;
	std::size_t height = file->height;

	std::size_t iter = 0;

	for (std::size_t i=0;i<file->levels;i++) {
		Image* image = new Image (height, width);

		std::size_t size = width * height;

		ImageSerializer::Instance ()->Deserialize (file->data + iter, image);

		pyramid->AddResidue (image);

		width = width / 2 + width % 2;
		height = height / 2 + height % 2;

		iter += size;
	}

	Image* finalImage = new Image (height, width);
	ImageSerializer::Instance ()->Deserialize (file->data + iter, finalImage);

	pyramid->SetFinalImage (finalImage);
}