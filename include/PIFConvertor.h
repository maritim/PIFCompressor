#ifndef PIFCONVERTOR_H
#define PIFCONVERTOR_H

#include "Singleton.h"

#include "PIFFile.h"
#include "ImagePyramid.h"

class PIFConvertor : public Singleton<PIFConvertor>
{
	friend Singleton<PIFConvertor>;

public:
	void Image2PIF (PIFFile*, ImagePyramid*);
	void PIF2Image (ImagePyramid*, PIFFile*);
private:
	PIFConvertor ();
	~PIFConvertor ();
	PIFConvertor (const PIFConvertor&);
	PIFConvertor& operator=(const PIFConvertor&);
};

#endif