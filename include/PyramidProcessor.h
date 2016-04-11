#ifndef PYRAMIDPROCESSOR_H
#define PYRAMIDPROCESSOR_H

#include "Singleton.h"

#include "Image.h"

#define uchar unsigned char

class PyramidProcessor : public Singleton<PyramidProcessor>
{
	friend Singleton<PyramidProcessor>;

public:
	class DownsamplingFunction 
	{
	public:
		virtual uchar Execute (uchar*) = 0;
	};

	class UpsamplingFunction {
	public:
		virtual void Execute (uchar*, uchar) = 0;
	};

private:
	DownsamplingFunction* _downsampling;
	UpsamplingFunction* _upsampling;

public:
	Image* Upscale (Image*, Size, UpsamplingFunction* f = nullptr);
	Image* Downscale (Image*, DownsamplingFunction* f = nullptr);

public:
	PyramidProcessor ();
	~PyramidProcessor ();
	PyramidProcessor (const PyramidProcessor&);
	PyramidProcessor& operator=(const PyramidProcessor&);
};

#endif