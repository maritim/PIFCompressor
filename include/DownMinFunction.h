#ifndef DOWNMINFUNCTION
#define DOWNMINFUNCTION

#include "PyramidProcessor.h"

class DownMinFunction : public PyramidProcessor::DownsamplingFunction
{
public:
	uchar Execute (uchar*);
};

#endif