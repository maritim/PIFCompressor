#ifndef IMAGESERIALIZER_H
#define IMAGESERIALIZER_H

#include "Singleton.h"

#include "Image.h"

#define uchar unsigned char

class ImageSerializer : public Singleton<ImageSerializer>
{
	friend Singleton<ImageSerializer>;

public:
	void Serialize (uchar*, Image*);
	void Deserialize (uchar*, Image*);
private:
	ImageSerializer ();
	~ImageSerializer ();
	ImageSerializer (const ImageSerializer&);
	ImageSerializer& operator=(const ImageSerializer&);
};

#endif