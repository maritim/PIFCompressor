#ifndef DOWNMAXFUNCTION_H
#define DOWNMAXFUNCTION_H

#include "PyramidProcessor.h"

class DownMaxFunction : public PyramidProcessor::DownsamplingFunction
{
public:
	uchar Execute (uchar*);
};

#endif