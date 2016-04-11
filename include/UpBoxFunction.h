#ifndef UPBOXFUNCTION_H
#define UPBOXFUNCTION_H

#include "PyramidProcessor.h"

class UpBoxFunction : public PyramidProcessor::UpsamplingFunction
{
public:
	void Execute (uchar*, uchar);
};

#endif