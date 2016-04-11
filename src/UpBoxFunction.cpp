#include "UpBoxFunction.h"

void UpBoxFunction::Execute (uchar* output, uchar input)
{
	output [0] = input;
	output [1] = input;
	output [2] = input;
	output [3] = input;
}